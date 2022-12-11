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

const int maxn = 111;

int s[maxn], a[maxn][maxn], poss[maxn];

int main() {
	int n,C=0,J=0;
	scanf("%d", &n);
	FOR(i,n) {
		scanf("%d", &s[i]);
		FOR(j,s[i]) scanf("%d", &a[i][j]);
	}
	FOR(i,n) {
		FOR(j,s[i]/2) C += a[i][j];
		for (int j = (s[i]+1)/2; j < s[i]; j++) J += a[i][j];
	}
	int cnt = 0;
	FOR(i,n) if (s[i] & 1) {
		poss[cnt++] = a[i][s[i]/2];
	}
	sort(poss, poss+cnt, greater<int>());
	FOR(i,cnt) {
		if (i&1) J += poss[i];
		else C += poss[i];
	}
	printf("%d %d\n", C, J);
	return 0;
}