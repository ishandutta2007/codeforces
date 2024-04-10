#include<bits/stdc++.h>
#define N 300000
#define inf 999999999999999
#define int long long
using namespace std;
int n,m,st,a[N+1],b[4*N+1],nxt[4*N+1],ls[N+1],bq[4*N+1],p,q,r,pb,fp[N+1],pbi;
struct bian{int p,q;}bi[N+1];
vector<int>fve[N+1],fsm[N+1];
priority_queue<pair<int,int> >pq;
queue<int>qu;
int s[N+1],dfn[N+1],pdfn,fdfn[N+1],fa[N+1],fc[N+1],ns[N+1],lc[N+1];
int sm[N+1],zp[N+1],ufa[N+1],uq[N+1],sz[N+1],fl[N+1];
int qread(){int nans=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')nans=nans*10+c-'0',c=getchar();return nans;}
void lb(int np,int nq,int nr){ls[np]=(a[np]?nxt[ls[np]]:a[np])=++pb,b[pb]=nq,bq[pb]=nr;}
void putin(){
	n=qread(),m=qread(),st=qread();
	for(int i=1;i<=m;i++)p=qread(),q=qread(),r=qread(),lb(p,q,r),lb(q,p,r);
}
void ycl(){
	for(int i=1;i<=n;i++)s[i]=inf;s[st]=0,fl[st]=1;
	qu.push(st);
	while(!qu.empty()){
		int nt=qu.front();qu.pop();
		for(int i=a[nt];i;i=nxt[i])if(s[nt]+bq[i]<s[b[i]])s[b[i]]=s[nt]+bq[i],qu.push(b[i]);
	}
//	pq.push(make_pair(0,st));
//	while(!pq.empty()){
//		int nt=pq.top().second;pq.pop(),fl[nt]=0;
//		for(int i=a[nt];i;i=nxt[i]){
//			if(s[nt]+bq[i]<s[b[i]]&&!fl[b[i]])fl[b[i]]=1,s[b[i]]=s[nt]+bq[i],pq.push(make_pair(-s[b[i]],b[i]));
//		}
//	}
	for(int i=1;i<=n;i++){
		for(int j=a[i];j;j=nxt[j]){
			if(s[i]+bq[j]==s[b[j]])bi[++pbi]=(bian){i,b[j]};
		}
	}
	memset(a,0,sizeof(a)),memset(b,0,sizeof(b)),memset(nxt,0,sizeof(nxt)),memset(ls,0,sizeof(ls)),pb=0;
	for(int i=1;i<=pbi;i++)lb(bi[i].p,bi[i].q,0),fve[bi[i].q].push_back(bi[i].p);
}
void dfs(int x){
	dfn[x]=++pdfn;
	for(int i=a[x];i;i=nxt[i]){
		if(!dfn[b[i]])fa[b[i]]=x,lc[x]=(fc[x]?ns[lc[x]]:fc[x])=b[i],dfs(b[i]);
	}
}
pair<int,int>fnd(int x){
	if(ufa[x]==x)return make_pair(x,uq[x]);
	pair<int,int>np=fnd(ufa[x]);
	ufa[x]=np.first,(dfn[sm[np.second]]<dfn[sm[uq[x]]]&&(uq[x]=np.second));
	return make_pair(ufa[x],uq[x]);
}
void mge(int x,int y){
	x=fnd(x).first,y=fnd(y).first;
	ufa[x]=y,(dfn[sm[uq[y]]]<dfn[sm[uq[x]]]&&(uq[x]=uq[y]));
}
signed main(){
//	freopen("P5180_6.in","r",stdin);
	putin();
	ycl();
	dfs(st);
	for(int i=1;i<=n;i++)if(dfn[i])fdfn[dfn[i]]=i,ufa[i]=i;
	dfn[0]=N+1;
	for(int ii=pdfn;ii>=1;ii--){
		int i=fdfn[ii];sm[i]=0;
		for(int nj=0;nj<fve[i].size();nj++){
			int j=fve[i][nj];
			if(dfn[j]<dfn[i]){
				if(dfn[j]<dfn[sm[i]])sm[i]=j;
			}else{
				int nt=sm[fnd(j).second];
				if(dfn[nt]<dfn[sm[i]])sm[i]=nt;
			}
		}
		uq[i]=i,fsm[sm[i]].push_back(i);
		for(int nj=0;nj<fsm[i].size();nj++){
			int j=fsm[i][nj];
			int nn=fnd(j).second;
			if(dfn[sm[nn]]==dfn[sm[j]])zp[j]=sm[j],fp[j]=j;
			else fp[j]=nn;
		}
		for(int j=fc[i];j;j=ns[j]){
			mge(j,i);
		}
	}
	for(int ii=1;ii<=pdfn;ii++){
		int i=fdfn[ii];
		zp[i]=zp[fp[i]];
	}
	zp[st]=0;
	for(int ii=pdfn;ii>=1;ii--)sz[fdfn[ii]]++,sz[zp[fdfn[ii]]]+=sz[fdfn[ii]];
	int ans=0;
	for(int i=1;i<=pdfn;i++){
		if(fdfn[i]==st)continue;
		ans=max(ans,sz[fdfn[i]]);
	}
	cout<<ans<<endl;
	return 0;
}
/*
9 13
1 2
2 3
3 4
2 5
5 6
6 7
7 8
5 9
5 1
7 2
7 4
9 6
8 6

6 7 1
1 2 1
2 3 2
1 3 3
3 4 3
4 5 1
5 6 2
2 6 2
*/