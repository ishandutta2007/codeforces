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

bool b[222][222];
int x=111,y=111;

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	string s;
	cin>>s;
	b[x][y]=true;
	int k=0;
	REP(i,sz(s)){
		if(s[i]=='L')--x;
		if(s[i]=='R')++x;
		if(s[i]=='U')--y;
		if(s[i]=='D')++y;
		if(b[x][y]){ k=-10000; break; }
		b[x][y]=true;
	}
	REP(i,221)REP(j,222){
		if(b[i][j] && b[i+1][j])++k;
		if(b[j][i] && b[j][i+1])++k;
	}
	if(k==sz(s))puts("OK");
	else puts("BUG");
	return 0;
}