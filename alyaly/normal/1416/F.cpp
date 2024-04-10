#include<bits/stdc++.h>
//#define int long long
#define N 200000
#define inf 1000000007
using namespace std;
int T,n,m,q0,pcol,ffl,nn;
int a[4*N+1],b[20*N+1],nxt[20*N+1],ls[20*N+1],bq[20*N+1],pb=1,cur[20*N+1];
int bs[4*N+1],st,fi;
int s[N+1],ans[N+1],d[N+1],fl[N+1],col[N+1],t[N+1];
int mx[7]={0,1,0,0,-1};
int my[7]={0,0,1,-1,0};
string td=" DRLU";
inline int pos(int x,int y){return (x-1)*m+y;}
inline void lb(int np,int nq,int nr){ls[np]=(a[np]?nxt[ls[np]]:a[np])=++pb,b[pb]=nq,bq[pb]=nr;}
inline void flb(int np,int nq,int nr){/*cout<<np<<' '<<nq<<endl;*/lb(np,nq,nr),lb(nq,np,0);}
void putin(){
//	n=250,m=400,ffl=0;
	cin>>n>>m,ffl=0;
//	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)s[pos(i,j)]=613862524;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>s[pos(i,j)];
}
inline bool bfs(){
	queue<int>qu;while(!qu.empty())qu.pop();qu.push(st);
	for(int i=1;i<=nn;i++)bs[i]=0,cur[i]=a[i];bs[st]=1;
	while(!qu.empty()){
		int nt=qu.front();qu.pop();
		for(int i=a[nt];i;i=nxt[i])if(bq[i]&&!bs[b[i]])bs[b[i]]=bs[nt]+1,qu.push(b[i]);
	}
	return bs[fi]!=0;
}
inline int dfs(int x,int nf){
	if(x==fi)return nf;
	int nans=0;
	for(int i=cur[x];i;i=nxt[i],cur[x]=i){
		if(bs[b[i]]!=bs[x]+1)continue;
		int nt=dfs(b[i],min(nf,bq[i]));
		nans+=nt,nf-=nt,bq[i]-=nt,bq[i^1]+=nt;
		if(!nf)return nans;
	}return nans;
}
inline void dinic(){
//	for(int i=1;i<=nn;i++)cur[i]=a[i];
	while(bfs()){
		dfs(st,inf);
	}
}
inline bool chk(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m;
}
inline int getp(int x,int y){
//	if(x==2&&y==1){
//		cout<<"aa\n";
//	}
	if((x+y)&1){
		for(int i=a[pos(x,y)];i;i=nxt[i]){
			if(!bq[i]&&b[i]!=st)return b[i];
		}
	}else{
		for(int i=a[pos(x,y)];i;i=nxt[i]){
			if(bq[i]&&b[i]!=fi)return b[i];
		}
	}return 0;
}
void ycl(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			bool fl1=0,fl2=0;
			for(int k=1;k<=4;k++){
				int nx=i+mx[k],ny=j+my[k];
				if(!chk(nx,ny))continue;
				if(s[pos(nx,ny)]<s[pos(i,j)])fl1=1;
				if(s[pos(nx,ny)]==s[pos(i,j)])fl2=1;
			}
			if(fl2&&!fl1)t[pos(i,j)]=1;
			else if(fl2&&fl1)t[pos(i,j)]=2;
			else if(!fl2&&!fl1){
				ffl=1;break;
			}
		}
		if(ffl)break;
	}
//	for(int i=1;i<=n;i++,cout<<'\n')for(int j=1;j<=m;j++)cout<<t[pos(i,j)]<<' ';
	nn=n*m+2,st=nn-1,fi=nn;
	if(ffl)return;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(t[pos(i,j)]){
				if((i+j)&1){
					for(int k=1;k<=4;k++){
						int nx=i+mx[k],ny=j+my[k];
						if(chk(nx,ny)&&s[pos(nx,ny)]==s[pos(i,j)]&&t[pos(i,j)]+t[pos(nx,ny)]!=4)flb(pos(i,j),pos(nx,ny),1);
					}
				}
				if(t[pos(i,j)]==1){
					if((i+j)&1)flb(st,pos(i,j),1);
					else flb(pos(i,j),fi,1);
				}
			}
		}
	}
	dinic();//cout<<"a1\n";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(t[pos(i,j)]==2&&((i+j)&1))flb(st,pos(i,j),1);
		}
	}
	dinic();
	for(int i=a[st];i;i=nxt[i]){
		if(t[b[i]]==2&&bq[i])flb(b[i],fi,1);
	}
	dinic();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(t[pos(i,j)]==2&&!((i+j)&1))flb(pos(i,j),fi,1);
		}
	}
	dinic();
	for(int i=1;i<=n;i++/*,cout<<'\n'*/){
		for(int j=1;j<=m;j++){
			if(d[pos(i,j)])continue;
			int np=getp(i,j);
			//cout<<np<<' ';
			//if(d[pos(i,j)])continue;
			if(!np){
				if(t[pos(i,j)]==1){ffl=1;return;}
			}else{
				for(int k=1;k<=4;k++){
					if(chk(i+mx[k],j+my[k])&&pos(i+mx[k],j+my[k])==np){
						d[pos(i,j)]=k;
						d[np]=5-k;
						break;
					}
				}
				ans[pos(i,j)]=s[np]/2,ans[np]=(s[np]+1)/2;
			}
		}
	}
}
void cal0(){
	if(ffl){cout<<"NO\n";return;}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(d[pos(i,j)])continue;
			for(int k=1;k<=4;k++){
				if(!chk(i+mx[k],j+my[k]))continue;
				int nk=pos(i+mx[k],j+my[k]);
				if(s[nk]<s[pos(i,j)]){
					d[pos(i,j)]=k;
					ans[pos(i,j)]=s[pos(i,j)]-s[nk];
					break;
				}
			}
			if(!d[pos(i,j)]){cout<<"NO\n";return;}
		}
	}
	cout<<"YES\n";
	for(int i=1;i<=n;i++,cout<<'\n')for(int j=1;j<=m;j++,cout<<' ')cout<<ans[pos(i,j)];
	for(int i=1;i<=n;i++,cout<<'\n')for(int j=1;j<=m;j++,cout<<' ')cout<<td[d[pos(i,j)]];
}
void achk(){
	if(ffl){cerr<<"no\n";return;}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int ns=0;
			pcol++;
			int nx=i,ny=j;
			while(col[pos(nx,ny)]!=pcol){
				col[pos(nx,ny)]=pcol,ns+=ans[pos(nx,ny)];
				int ax=nx+mx[d[pos(nx,ny)]],ay=ny+my[d[pos(nx,ny)]];
				nx=ax,ny=ay;
			}
			if(ns!=s[pos(i,j)]){
				cerr<<"fail\n"<<i<<' '<<j<<endl;
				return;
			}
		}
	}
	cerr<<"ok\n";
}
void aclr(){
	for(int i=1;i<=nn;i++)ans[i]=s[i]=d[i]=a[i]=ls[i]=t[i]=col[i]=0;nn=0;
	for(int i=1;i<=pb;i++)b[i]=nxt[i]=bq[i]=0;pb=1,ffl=pcol=0;
}
signed main(){
//	freopen("grid.in","r",stdin);
//	freopen("grid.out","w",stdout);
	cin>>T;
	while(T--){
		putin();
		ycl();
		cal0();
//		achk();
		aclr();
	}
	return 0;
}