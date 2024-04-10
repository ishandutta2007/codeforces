#include<algorithm>
#include<bitset>
#include<cctype>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

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

int qpow(int a, int n) {
	if (n==0) return 1;
	int b=qpow(a,n/2);
	b = 1LL*b*b%1000000007;
	if (n&1) b=1LL*a*b%1000000007;
	return b;
}

int n,m,q;
char s[1000100];
int t[1000100], p[1000100];
bool ok[1000100];



int main() {
	scanf("%d%d", &n, &q);
	scanf("%s", s);
	FOR(i,q) {
		scanf("%d", &p[i]);
		p[i]--;
	}
	for (m = 0; s[m]; m++) ;
	t[0]=0;
	int k=0;
	for (int i = 1; i < m; i++) {
		while (k>0 && s[k] != s[i]) k=t[k-1];
		if (s[k] == s[i]) k++;
		t[i] = k;
	}
	int L = m, P = m;
	while (L>0) {
		while (t[L-1] < P) {
			P--;
		}
		ok[P]=true;
		L=t[L-1];
	}
	//FOR(i,m) printf("%d ", t[i]); printf("\n");
	//FOR(i,m) printf("%d ", ok[i]); printf("\n");
	p[q] = n;
	FOR(i,q) if (p[i+1]-p[i] < m && !ok[m-p[i+1]+p[i]]) {
		printf("0\n");
		return 0;
	}
	int sum=p[0];
	FOR(i,q) if (p[i+1]-p[i] > m) sum += p[i+1]-p[i]-m;
	int res = qpow(26,sum);
	printf("%d\n",res);
	return 0;
}