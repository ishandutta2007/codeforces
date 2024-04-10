#include <vector>
#include <cstring>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <complex>
#include <memory.h>
#ifdef __ASD__
#include <windows.h>
#endif
using namespace std;
#define all(a) a.begin(),a.end()
#define forn(i,n) for(int i=0;i<(n);++i)
#define fornn(i,n) for(i=0;i<(n);++i)
#define lng long long
#define SQ(a) ((a)*(a))
#define forv(i,v) for(int i=0;i<(int)v.size();++i)
#define mp make_pair
#define pb push_back
#define ABS(a) ((a)<0?-(a):(a))
#define iinf 1000000000
#define linf SQ(1LL*iinf)
#define left asdleft
#define prev asdprev
#define hash asdhash
#define eps 1e-8
#define y1 asdy1
#define y2 asdy2
#define EQ(a,b) abs((a)-(b))<eps
#define PI 3.1415926535897932384626433832795
#define DEG2RAD PI/180
#define ulng unsigned lng
const double dinf = 1e200;
void mytimer(string task){
#ifdef __ASD__
	static LARGE_INTEGER prev;	LARGE_INTEGER cur,freq;	QueryPerformanceCounter(&cur);	QueryPerformanceFrequency(&freq);	if(task!="")		cout<<task<<" took "<<(cur.QuadPart-prev.QuadPart)*1.0/freq.QuadPart<<endl;	prev=cur;
#endif
}
void ext(int c){
#ifdef __ASD__
	exit(c);
#endif
}

int gcd(int a,int b){
	return a?gcd(b%a,a):b;
}

struct item{
	lng a;
	int l;
	int c;
	int ind;
	void read(){
		lng t;
		cin>>a>>t>>c;
		l=t-a+1;
	}
	bool operator<(const item &b)const{
		return c<b.c;
	}
};

int M,N,K;
item items[60];

lng dp[60][60][110];
pair<int,int> prev[60][60][110];

#define taska "four"
int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
	//freopen(taska".in","r",stdin);freopen(taska".out","w",stdout);
#endif

	//ios_base::sync_with_stdio(false);

	cin>>M>>N>>K;
	forn(i,N){
		items[i].read();
		items[i].ind=i+1;
	}
	sort(items,items+N);

	forn(n,N){
		forn(v,items[n].l)
			dp[n][1][v]=items[n].a+v;
		for(int m=2;m<=M;++m){
			forn(v,items[n].l){
				forn(nn,n){
					if(items[nn].c==items[n].c)
						continue;
					
					lng val;
					
					val=items[n].a+v-K;
					val-=items[nn].a;
					if(val>=0&&val<items[nn].l){
						int vv=(int)val;
						if(dp[nn][m-1][vv]>0){
							lng t=dp[nn][m-1][vv]+items[n].a+v;
							if(t>dp[n][m][v]){
								dp[n][m][v]=t;
								prev[n][m][v]=mp(nn,vv);
							}
						}
					}

					lng tt=items[n].a+v;
					if(tt%K)
						continue;

					val=tt/K;
					val-=items[nn].a;
					if(val>=0&&val<items[nn].l){
						int vv=(int)val;
						if(dp[nn][m-1][vv]>0){
							lng t=dp[nn][m-1][vv]+items[n].a+v;
							if(t>dp[n][m][v]){
								dp[n][m][v]=t;
								prev[n][m][v]=mp(nn,vv);
							}
						}
					}
				}
			}
		}
	}

	pair<lng,pair<int,int> > res(0,mp(0,0));

	forn(n,N)
		forn(s,items[n].l)
			res=max(res,mp(dp[n][M][s],mp(n,s)));

	if(res.first==0){
		cout<<"NO";
		return 0;
	}

	cout<<"YES"<<endl;

	pair<int,int> p=res.second;
	vector<pair<int,lng> > resv;
	int m=M;
	while(true){
		resv.pb(mp(items[p.first].ind,items[p.first].a+p.second));
		if(m==1)
			break;
		p=prev[p.first][m][p.second];
		--m;
	}

	reverse(all(resv));

	forv(i,resv)
		cout<<resv[i].first<<' '<<resv[i].second<<'\n';

	return 0;
}