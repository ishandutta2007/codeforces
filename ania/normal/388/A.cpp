#include<algorithm>
#include<bitset>
#include<cctype>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>

using namespace std;

#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

int x[111], a[111];

int main() {
	int n;
	scanf("%d", &n);
	FOR(i,n) scanf("%d", &x[i]);
	sort(x,x+n);
	int cnt = 0;
	FOR(i,n) {
		int pos = 0;
		while (a[pos] > x[i]) pos++;
		a[pos]++;
		if (pos == cnt) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}