#include<bits/stdc++.h>
#define N 300000
#define int long long
#define inf 999999999999
using namespace std;
struct itv{
	int l,r,bh;
}a[N+1];
int n,K,pr,ans;
int dic[2*N+1],pdic,dis[2*N+1],pg,ph,acnt,len[N+1][2],sr[N+1];
vector<pair<int,int> > ve[N+1],fe[N+1];
map<int,itv>ma;
pair<int,itv>g[2*N+1],h[2*N+1];
inline bool cr(itv x,itv y){return (x.r>y.l&&x.l<y.r);}
inline int qread(){int nans=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')nans=nans*10+c-'0',c=getchar();return nans;}
void putin(){
	n=qread(),K=qread();
	for(int i=1;i<=n;i++)a[i].l=qread(),a[i].r=qread(),a[i].bh=i;
}
//void caldic(){
//	for(int i=1;i<=n;i++)dic[++pdic]=a[i].l,dic[++pdic]=a[i].r;
//	sort(dic+1,dic+pdic+1),pdic=unique(dic+1,dic+pdic+1)-dic-1;
//	for(int i=1;i<pdic;i++)dis[i]=dic[i+1]-dic[i];
//	for(int i=1;i<=n;i++)a[i].l=lower_bound(dic+1,dic+pdic+1,a[i].l)-dic,a[i].r=lower_bound(dic+1,dic+pdic+1,a[i].r)-dic-1;
//}
void odtadd(itv x,int nt){
	itv nx;pg=ph=0;
	map<int,itv>::iterator ni=ma.lower_bound(x.r);
	if(ni!=ma.begin())ni--;
	while(ni!=ma.end()&&cr(ni->second,x)){
		nx=ni->second;
		if(nx.l<x.l&&nx.r>x.r){
			g[++pg]=make_pair(nx.l,(itv){nx.l,x.l,nx.bh}),g[++pg]=make_pair(x.r,(itv){x.r,nx.r,nx.bh});
			ve[nx.bh].push_back(make_pair(nt,x.r-x.l));
		}else if(nx.l>=x.l&&nx.r<=x.r){
			ve[nx.bh].push_back(make_pair(nt,nx.r-nx.l));
		}else if(nx.l<x.l){
			g[++pg]=make_pair(nx.l,(itv){nx.l,x.l,nx.bh});
			ve[nx.bh].push_back(make_pair(nt,nx.r-x.l));
		}else if(nx.r>x.r){
			g[++pg]=make_pair(x.r,(itv){x.r,nx.r,nx.bh});
			ve[nx.bh].push_back(make_pair(nt,x.r-nx.l));
		}
		h[++ph]=make_pair(nx.l,nx);
		if(ni==ma.begin())break;
		ni--;
	}
	g[++pg]=make_pair(x.l,x);
	for(int i=1;i<=ph;i++)ma.erase(h[i].first);
	for(int i=1;i<=pg;i++)ma.insert(g[i]);
}
void ycl(){
	for(int i=1;i<=n;i++){
		odtadd(a[i],i);
		len[i][0]=len[i][1]=a[i].r-a[i].l;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<ve[i].size();j++)fe[ve[i][j].first].push_back(make_pair(i,ve[i][j].second)),acnt++;
	}
}
bool chk(int nx){
//	if(nx==3){
//		cout<<"aa";
//	}
	for(int i=1;i<=n;i++)len[i][1]=len[i][0];
	int np=0,ng=0,nans=0;
	for(int i=1;i<=n;i++){
		while(ng<nx&&np<=n){
			np++;
			for(int j=0;j<fe[np].size();j++){
				if(fe[np][j].first>=i)ng-=fe[np][j].second,len[fe[np][j].first][1]-=fe[np][j].second;
			}
			ng+=len[np][0];
		}
		nans+=(np-i);
		sr[i]=np-1;
		ng-=len[i][1];
	}
	return n*(n+1)/2-nans>=K;
}
int efans(){
	int nl=0,nr=inf,nmid;
	while(nl!=nr){
		nmid=(nl+nr+1)/2;
		if(chk(nmid))nl=nmid;
		else nr=nmid-1;
	}
	return nl;
}
pair<int,int>cal(int nx){

	memset(sr,0,sizeof(sr));
	for(int i=1;i<=n;i++)len[i][1]=len[i][0];
	int np=0,ng=0,nans=0,aa=0,na=0,slen=0,ss=0;
	for(int i=1;i<=n;i++){
		na=0;
		while(ng<nx&&np<=n){
			np++;
			if(np>n)break;
			for(int j=0;j<fe[np].size();j++){
				if(fe[np][j].first>=i)na+=fe[np][j].second,ng-=fe[np][j].second,len[fe[np][j].first][1]-=fe[np][j].second;
			}
			ng+=len[np][0];
		}
		nans+=(np-i);
		sr[np]=i;
		ng-=len[i][1];
	}ng=0;
	for(int i=1;i<=n;i++)sr[i]=max(sr[i],sr[i-1]),len[i][1]=len[i][0];
		if(nx==inf){
//		cout<<"aa";
	}
	for(int i=1;i<=n;i++){
		ng+=(i-ss)*len[i][0];slen+=len[i][0];
		
		for(int j=sr[i-1]+1;j<=sr[i];j++){
			ng-=slen;slen-=len[j][1];len[j][1]=0;ss++;
		}for(int j=0;j<fe[i].size();j++){
			if(fe[i][j].first>ss)len[fe[i][j].first][1]-=fe[i][j].second,slen-=fe[i][j].second,ng-=(fe[i][j].first-ss)*fe[i][j].second;
		}
		aa+=ng;
	}
	return make_pair(nans,aa);
}
void cal1(){
	int nl=efans();
	pair<int,int>nt=cal(nl);
	ans=cal(inf).second-(nl*(n*(n+1)/2-K-nt.first)+nt.second);
	cout<<ans<<endl;
}
signed main(){
//	freopen("c2.in","r",stdin);
//	freopen("c.out","w",stdout);
	putin();
//	caldic();
	ycl();
	cal1();
	return 0;
}
/*
5 8
1 4
2 5
3 4
3 6
4 5
*/