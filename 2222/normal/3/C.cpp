#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)		(a).begin(),(a).end()
#define sz(a)		int((a).size())
#define FOR(i,a,b)	for(int i=a;i<b;++i)
#define REP(i,n)	FOR(i,0,n)
#define UN(v)		sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)		memset(a,b,sizeof a)
#define pb			push_back
#define X			first
#define Y			second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

char a[3][4],s[3][3];

bool check(int x,int y){
	bool h=true,v=true;
	REP(i,3){
		if(s[x][i]!=s[x][y])h=false;
		if(s[i][y]!=s[x][y])v=false;
	}
	if(h||v)return true;
	h=v=true;
	REP(i,3){
		if(s[i][i]!=s[x][y])h=false;
		if(s[2-i][i]!=s[x][y])v=false;
	}
	return v||h;
}

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	vector<pii> p;
	REP(i,3){
		cin>>a[i];
		REP(j,3)if(a[i][j]!='.')p.pb(pii(i,j));
	}
	sort(all(p));
	bool first=false,second=false,w=false;
	do {
		bool ok=true;
		char c='X',t='0';
		REP(i,sz(p)){
			int x=p[i].X,y=p[i].Y;
			if(a[x][y]!=c)ok=false;
			swap(c,t);
		}
		if(ok){
			(c=='X'?first:second)=true;
			REP(i,3)REP(j,3)s[i][j]='.';
			bool won=false;
			REP(i,sz(p)){
				int x=p[i].X,y=p[i].Y;
				s[x][y]=a[x][y];
				if(won){ ok = false; break; }
				if(check(x,y)) won = true;
			}
			w|=won;
			if(ok){
				if(won){
					puts(c=='X'?"the second player won":"the first player won");
					return 0;
				}else if(sz(p)==9){
					puts("draw");
					return 0;
				}
			}
		}
	}while(next_permutation(all(p)));
	if(!w && first!=second)
		puts(first?"first":"second");
	else puts("illegal");
	return 0;
}