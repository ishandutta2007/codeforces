#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define fi first
#define se second

int n,t;
char s[200100];

int main() {
	scanf("%d%d%s", &n, &t, s);
	int pos=-1;
	FOR(i,n) if (s[i]=='.') pos=i;
	if (pos==-1) {
		printf("%s\n", s);
		return 0;
	}
	for (int i=pos+1; i<n; i++) {
		if (s[i]>='5') {
			FOR(j,t) {
				if (s[i]<'5') break;
				if (i-1 == pos) {
					s[i-2]++;
					s[i-1]=0;
					s[i]=0;
					i-=2;
					break;
				} else {
					s[i-1]++;
					s[i]=0;
					i--;
				}
			}
			while (i>0 && s[i]>'9') {
				s[i] -= 10;
				s[i-1]++;
				i--;
			}
			if (s[0]>'9') {
				s[0]-=10;
				printf("1");
			}
			printf("%s\n", s);
			return 0;
		}
	}
	printf("%s\n", s);
	return 0;
}