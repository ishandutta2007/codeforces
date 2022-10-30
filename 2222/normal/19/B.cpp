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

int n;
pii a[2222];

long long F[2222][4422];

ll f(int i, int j) {
	if (i + j >= n) return 0;
	if (i == n) return -1ull/4;
	ll &res = F[i][j + 2222];
	if (res < 0) {
		res = f(i + 1, j - 1);
		res = min(res, f(i + 1, j + a[i].X) + a[i].Y);
	}
	return res;
}

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	cin >> n;
	REP (i, n) cin >> a[i].X >> a[i].Y;
	CL(F, -1);
	cout << f(0, 0) << endl;
	return 0;
}