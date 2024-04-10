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

const int maxn = 100100;

int n,m;
int t[maxn], x[maxn], l[maxn], c[maxn], val[maxn];
long long len[maxn];

int main() {
	scanf("%d", &m);
	FOR(i,m) {
		scanf("%d", &t[i]);
		if (t[i] == 1) scanf("%d", &x[i]);
		else scanf("%d%d", &l[i], &c[i]);
	}
	int pos = 0;
	FOR(i,m) {
		//printf("i = %d, t = %d\n", i, t[i]);
		if (t[i] == 1) {
			if (i == 0) len[i] = 1;
			else len[i] = len[i-1] + 1;
			if (pos < maxn) {
				//printf("val[%d] = %d\n", pos, x[i]);
				val[pos++] = x[i];
			}
		} else {
			len[i] = len[i-1] + l[i] * c[i];
			int it = 0, cnt = 0;
			while (pos < maxn) {
				//printf("val[%d] = val[%d] = %d\n", pos, it, val[it]);
				val[pos] = val[it];
				it++;
				pos++;
				if (it == l[i]) {
					it = 0;
					cnt++;
					if (cnt == c[i]) break;
				}
			}
		}
	}
	int cur = 0;
	long long q;
	scanf("%d", &n);
	FOR(i,n) {
		scanf("%I64d", &q);
		while (len[cur] < q) cur++;
		if (t[cur] == 1) printf("%d ", x[cur]);
		else {
			q -= len[cur-1];
			q--;
			q %= l[cur];
			printf("%d ", val[q]);
		}
	}
	printf("\n");
}