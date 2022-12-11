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

int a[33];
char res[100100];

int main() {
	int n;
	scanf("%d", &n);
	FOR(i,n) scanf("%d", &a[i]);
	int pos=-1, len = 0, q = 0;
	FOR(i,n) len+=a[i];
	int g = 0;
	FOR(i,n) g = __gcd(g,a[i]);
	FOR(i,n) if (a[i]/g%2==1) {
		if (pos!=-1) {
			if (g%2==1) {
				printf("0\n");
				FOR(j,n) while (a[j]--) res[q++]='a'+j;
				printf("%s\n", res);
				return 0;
			}
			g /= 2;
			break;
		}
		pos=i;
	}
	int l2 = len/g;
	FOR(i,n) a[i]/=g;
	FOR(i,n) {
		if (a[i]%2==1) { res[l2/2]='a'+i; a[i]--; }
		while (a[i]) {
			res[q]='a'+i;
			res[l2-1-q]='a'+i;
			q++;
			a[i] -= 2;
		}
	}
	FORI(i,g-1) FOR(j,l2) res[l2*i+j] = res[j];
	printf("%d\n%s\n", l2%2?g:2*g, res);
	return 0;
}