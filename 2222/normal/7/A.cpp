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

char s[9][9];
char c[9][9];

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	REP(i,8)gets(s[i]);
	int res=100;
	REP(p,256){
		int k=0;
		REP(i,8){
			if(p&1<<i){
				++k;
				REP(j,8)c[i][j]='B';
			}else REP(j,8)c[i][j]='W';
		}
		REP(i,8)
			REP(j,8)
				if(s[i][j]=='B' && c[i][j]=='W'){
					++k;
					REP(x,8)c[x][j]='B';
				}
		REP(i,8)REP(j,8)
			if(s[i][j]!=c[i][j])k=100;
		res=min(res,k);
	}
	cout<<res<<endl;
	return 0;
}