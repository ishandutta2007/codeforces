#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LL long long
#define LD long double
const LL INF=1e18;
const int N=1e5+10;
int n,m,Q;
struct P{
	LL x,y,h;
}a[N],b[5];
int tr[N][3];
vector<int> V[N],po[1000005];
struct QUERY{
	int h,u,id;
}query[N];
int fa[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

struct KUAI{
	int h;
	LD ans,W,AD;
}ku[N];

void Cal(KUAI &x,int t){
	if(x.h==t) return;
	LL o=x.h-t;
	x.ans += x.W * (LD)o;
	x.ans += x.AD * (LD)((1+o)*o/2);
	x.W += x.AD * (LD)o;
	x.h=t;
	return;
}
bool used[N];
LD cal2(LL x,LL y,LL z,LL xx,LL yy,LL zz){
	LL i=y*zz-yy*z;
	LL j=x*zz-xx*z;
	LL k=x*yy-xx*y;
	LD re=sqrt((LD)i*(LD)i+(LD)j*(LD)j+(LD)k*(LD)k)/2;
	return re;
}

vector<KUAI> U[1000005];
LD ANS[N];
void MAIN(){
	int u,v,w;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].x>>a[i].y>>a[i].h;
		po[a[i].h].push_back(i);
	}
	cin>>m;
	for(int i=1;i<=m;++i){
		cin>>tr[i][0]>>tr[i][1]>>tr[i][2];
		V[tr[i][0]].push_back(i);
		V[tr[i][1]].push_back(i);
		V[tr[i][2]].push_back(i);
	}
	cin>>Q;
	for(int i=1;i<=Q;++i){
		cin>>query[i].h>>query[i].u;
		query[i].id=i;
	}
	sort(query+1,query+1+Q,[&](QUERY &x,QUERY &y){
		return x.h>y.h;
	});
	memset(fa,0,sizeof(fa));
	KUAI tmp;
//	LD sss=0;
//	for(int y=1;y<=m;++y){
//		b[0]=a[tr[y][0]];
//		b[1]=a[tr[y][1]];
//		b[2]=a[tr[y][2]];
//		if(b[0].h<b[1].h) swap(b[0],b[1]);
//		if(b[1].h<b[2].h) swap(b[2],b[1]);
//		if(b[0].h<b[1].h) swap(b[0],b[1]);
//		LD O=cal2(
//		b[1].x-b[0].x,b[1].y-b[0].y,b[1].h-b[0].h,
//		b[2].x-b[0].x,b[2].y-b[0].y,b[2].h-b[0].h);
//		sss+=O;
//	}
//	printf("%0.15Lf\n",sss);
	for(int t=1000000,q=1;t>=0;--t){
		while(q<=Q&&query[q].h==t){
			if(a[query[q].u].h<=t){
				ANS[query[q].id]=-1;
			}
			else{
				query[q].u=find(query[q].u);
				Cal(ku[query[q].u],t);
				ANS[query[q].id]=ku[query[q].u].ans;
				//sol kuai to time t
				//cout ans
			}
			++q;
		}
		for(auto x : po[t]){
			fa[x]=x;
			for(auto y:V[x]){
				if(used[y]) continue;
				used[y]=1;
				b[0]=a[tr[y][0]];
				b[1]=a[tr[y][1]];
				b[2]=a[tr[y][2]];
				if(b[0].h<b[1].h) swap(b[0],b[1]);
				if(b[1].h<b[2].h) swap(b[2],b[1]);
				if(b[0].h<b[1].h) swap(b[0],b[1]);
				LD O=cal2(
				b[1].x-b[0].x,b[1].y-b[0].y,b[1].h-b[0].h,
				b[2].x-b[0].x,b[2].y-b[0].y,b[2].h-b[0].h);
				LD O1;
				LL ti;
				if(b[0].h!=b[1].h){
					O1=O*(LD)(b[0].h-b[1].h)/(LD)(b[0].h-b[2].h);
					ti=b[0].h-b[1].h;
					tmp.h=x;
					
					O1=O1/(LD)(ti*ti);
					
					tmp.W=-O1;
					tmp.AD=O1+O1;
					U[b[0].h].push_back(tmp);
					
					tmp.W=(-ti-ti+1)*O1;
					tmp.AD=-tmp.AD;
					U[b[1].h].push_back(tmp);
				}
				if(b[1].h!=b[2].h){
					O1=O*(LD)(b[1].h-b[2].h)/(LD)(b[0].h-b[2].h);
					ti=b[1].h-b[2].h;
					tmp.h=x;
					
					O1=O1/(LD)(ti*ti);
					
					tmp.W=(ti+ti+1)*O1;
					tmp.AD=-O1-O1;
					U[b[1].h].push_back(tmp);
					
					tmp.W=-O1;
					tmp.AD=-tmp.AD;
					U[b[2].h].push_back(tmp);
				}
				if(b[1].h==b[2].h&&b[0].h==b[1].h){
					ku[x].ans+=O;
				}
			}
		}
		for(auto x:U[t]){
			int FA=find(x.h);
			Cal(ku[FA],t);
			ku[FA].W+=x.W;
			ku[FA].AD+=x.AD;
		}
		for(auto x : po[t]){
			int X=find(x);
			for(auto y:V[x]){
				for(int hhh=0;hhh<=2;++hhh){
					int Y=find(tr[y][hhh]);
					if(Y==X||Y==0) continue;
					Cal(ku[X],t);
					Cal(ku[Y],t);
					ku[X].ans+=ku[Y].ans;
					ku[X].W+=ku[Y].W;
					ku[X].AD+=ku[Y].AD;
					fa[Y]=X;
				}
			}
		}
	}
	for(int i=1;i<=Q;++i){
		if(ANS[i]==-1) printf("-1\n");
		else printf("%0.15Lf\n",ANS[i]);
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int ttt=1;//cin>>ttt;
	while(ttt--) MAIN();
	return 0;
}
/*
16
0 5 0
1 2 0
2 5 5
3 7 0
4 0 0
4 3 5
5 5 1
6 2 0
6 6 5
7 4 4
7 8 0
8 2 0
9 4 0
4 6 4
6 3 3
2 4 5
22
11 10 9
12 8 10
2 6 5
9 10 7
8 15 6
16 3 6
15 6 7
7 3 14
8 10 15
11 13 10
16 6 2
12 10 13
10 7 15
16 3 2
3 4 1
14 7 9
11 9 4
3 6 7
5 6 8
14 4 3
3 1 2
9 4 14
7
0 7
1 7
1 16
2 10
3 9
4 16
5 16

*/