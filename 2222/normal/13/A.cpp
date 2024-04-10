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

int n, res;

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	cin >> n;
	FOR (i, 2, n) 
		for (int x = n; x; x /= i) res += x % i;
	n -= 2;
	cout << res / __gcd(n, res) << "/" << n / __gcd(n, res) << endl;
	return 0;
}