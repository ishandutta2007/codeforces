#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) ((int)((x).size()))
#define IN(x,y) ((y).find((x)) != (y).end())
#define DBG(v) cerr<<#v<<" = "<<(v)<<endl;
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

int n, t[1000100];

int main() {
	scanf("%d", &n);
	int L = 0, R = n-1;
	for (int i = 1; i <= n; i += 2) {
		t[L] = t[R] = i;
		L++; R--;
	}
	t[n] = n;
	L = n+1; R = 2*n-1;
	for (int i = 2; i <= n; i += 2) {
		t[L] = t[R] = i;
		L++; R--;
	}
	for (int i = 0; i < 2*n; i++) printf("%d ", t[i]);
	printf("\n");
	return 0;
}