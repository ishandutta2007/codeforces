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

int n, k;

bool isPrime(int n) {
	for (int x = 3; x * x <= n; ++x)
		if (n % x == 0) return false;
	return true;
}

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	cin >> n >> k;
	vector <int> p(1, 2);
	for (int i = 3; i <= n; i += 2)
		if (isPrime(i)) p.pb(i);
	for (vi :: iterator x = p.begin(); x != p.end(); ++x) {
		for (vi :: iterator i = p.begin(), j = i + 1; j < p.end(); ++i, ++j)
			if (*i + *j + 1 == *x) {
				--k;
				break;
			}
	}
	puts (k > 0 ? "NO" : "YES");
	return 0;
}