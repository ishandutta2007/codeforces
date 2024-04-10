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

const int maxn = 500500;

int n,q,p;
int r[maxn], t[maxn], a[maxn];

int main() {
	scanf("%d", &n);
	FOR(i,n) scanf("%d", &a[i]);
	a[n]=a[n-1];
	a[n+1]=2;
	int cnt = 2;
	FORI(i,n+1) {
		if (a[i] == a[i-1]) {
			cnt++;
		} else {
			t[q++] = cnt;
			cnt = 1;
		}
	}
	int res = 0, len = 0;
	FOR(i,q) {
		if (t[i]==1) {
			len++;
		} else {
			if (len%2==1) {
				res = max(res, len/2+1);
				r[p-1] += t[i]+len;
				len = 0;
			} else {
				res = max(res, len/2);
				r[p] = t[i];
				if (len>0) {
					r[p-1] += len/2;
					r[p] += len/2;
				}
				p++;
			}
			len=0;
		}
	}
	printf("%d\n", res);
	r[0]--;
	r[p-1]--;
	FOR(i,p) while (r[i]--) printf("%d ", (i+a[0])%2);
	printf("\n");
	return 0;
}