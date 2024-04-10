#include<bits/stdc++.h>
using namespace std;
enum{N=1009,M=N*N};
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int RD=rd();
struct H{size_t operator()(int x)const{return x^RD;}};
unordered_set<int,H>st[M];
char s[N][N];
int h,w,u,px[13],py[13],ltc[M];
namespace D{
int f[M],sz[M],st[999],tp;
int gf(int x){return f[x]==x?x:gf(f[x]);}
void init(){for(int i=0;i<M;++i)f[i]=i,sz[i]=1;}
void mg0(int x,int y){
	if(x=gf(x),y=gf(y),x==y)return;
	if(sz[x]>sz[y])swap(x,y);
	f[x]=y,sz[y]+=sz[x];
}
void mg(int x,int y){
	if(x=gf(x),y=gf(y),x==y)return;
	if(sz[x]>sz[y])swap(x,y);
	f[x]=y,sz[y]+=sz[x],st[++tp]=x;
}
void clr(){
	int x;
	while(tp)x=st[tp--],sz[f[x]]-=sz[x],f[x]=x;
}
}
inline int id(int x,int y){return x*N+y;}
inline void wk0(int x,int y){if(x>=0&&y>=0&&s[x][y]=='#')D::mg0(u,id(x,y));}
inline void wk(int x,int y){if(s[x][y]=='#')D::mg(u,id(x,y));}
basic_string<int>la,lb;
inline void wk1(int x,int y){la+=ltc[id(x,y)];}
inline void wk2(int x,int y){lb+=ltc[id(x,y)];}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int q,i,j,k,l,rd,bl,o,ax,ay,ux,uy;
	cin>>h>>w>>q;
	for(i=1;i<=h;++i)cin>>s[i]+1;
	for(i=3;i<=w+1;++i)s[0][i]='#';
	for(i=3;i<=h+1;++i)s[i][0]='#';
	for(i=1;i<=w-2;++i)s[h+1][i]='#';
	for(i=1;i<=h-2;++i)s[i][w+1]='#';
	++h,++w,D::init();
	for(i=0;i<=h;++i)for(j=0;j<=w;++j)if(s[i][j]=='#'){
		u=id(i,j);
		wk0(i-1,j-1),wk0(i-1,j),wk0(i,j-1),wk0(i-1,j+1),wk0(i+1,j-1);
		wk0(i+1,j),wk0(i,j+1),wk0(i+1,j+1);
	}
	for(i=0;i<=h;++i)for(j=0;j<=w;++j)if(s[i][j]=='#'){
		u=id(i,j);
		ltc[u]=D::gf(u);
	}
	for(i=0;i<=h;++i)for(j=0;j<=w;++j)if(s[i][j]=='#'){
		o=ltc[id(i,j)];
		for(ax=-2;ax<=2;++ax)if((ux=ax+i)>=0)
		for(ay=-2;ay<=2;++ay)if((uy=ay+j)>=0){
			if(s[ux][uy]=='#')
		st[o].insert(ltc[id(ux,uy)]);
		}
	}
	rd=D::gf(id(h,0)),bl=D::gf(id(0,w));
	if(rd==bl){
		while(q--)cout<<"NO"<<endl;
		return 0;
	}
	while(q--){
		cin>>k;
		for(l=0;l<k;++l){
			cin>>i>>j,px[l]=i,py[l]=j;
			s[i][j]='#';
		}
		for(l=0;l<k;++l){
			u=id(i=px[l],j=py[l]);
			wk(i-1,j-1),wk(i-1,j),wk(i,j-1),wk(i-1,j+1),wk(i+1,j-1);
			wk(i+1,j),wk(i,j+1),wk(i+1,j+1);
		}
		rd=D::gf(id(h,0)),bl=D::gf(id(0,w));
		if(rd==bl){cout<<"NO"<<endl;goto gg;}
		la=lb={};
		for(l=0;l<k;++l){
			u=id(i=px[l],j=py[l]);
			if((o=D::gf(u))==rd){
				wk1(i-1,j-1),wk1(i-1,j),wk1(i,j-1),wk1(i-1,j+1),wk1(i+1,j-1);
			wk1(i+1,j),wk1(i,j+1),wk1(i+1,j+1);
			for(ax=-2;ax<=2;++ax)if((ux=ax+i)>=0)
			for(ay=-2;ay<=2;++ay)if((uy=ay+j)>=0){
				if(D::gf(id(ux,uy))==bl){cout<<"NO"<<endl;goto gg;}
			}
			}else if(o==bl){
				wk2(i-1,j-1),wk2(i-1,j),wk2(i,j-1),wk2(i-1,j+1),wk2(i+1,j-1);
			wk2(i+1,j),wk2(i,j+1),wk2(i+1,j+1);
			for(ax=-2;ax<=2;++ax)if((ux=ax+i)>=0)
			for(ay=-2;ay<=2;++ay)if((uy=ay+j)>=0){
				if(D::gf(id(ux,uy))==rd){cout<<"NO"<<endl;goto gg;}
			}
			}
		}la+=ltc[id(h,0)],lb+=ltc[id(0,w)];
		sort(begin(la),end(la)),sort(begin(lb),end(lb));
		la.resize(unique(begin(la),end(la))-begin(la));
		lb.resize(unique(begin(lb),end(lb))-begin(lb));
		for(int oa:la)for(int ob:lb)if(st[oa].count(ob)){
			cout<<"NO"<<endl;goto gg;}
		cout<<"YES"<<endl;
		gg:;
		D::clr();
		for(l=0;l<k;++l)s[i=px[l]][j=py[l]]='.';
	}
	return 0;
}