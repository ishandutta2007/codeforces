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

char s[1000100], t[1000100];
int main() {
	scanf("%s%s", s, t);
	int n,m,posn=-1,posm=-1;
	for (n=0;s[n];n++) ;
	for (m=0;t[m];m++) ;
	for (int i = 0; i < n; i++) if (s[i]!='0') {
		posn=i;
		break;
	}
	for (int i = 0; i < m; i++) if (t[i]!='0') {
		posm=i;
		break;
	}
	if (posm==-1) {
		if (posn==-1) printf("=\n");
		else printf(">\n");
		return 0;
	}
	if (posn==-1) {
		printf("<\n");
		return 0;
	}
	if (n-posn!=m-posm) {
		if (n-posn<m-posm) printf("<\n");
		else printf(">\n");
		return 0;
	}
	for (int i = 0; i < n-posn; i++) {
		if (s[i+posn] != t[i+posm]) {
			if (s[i+posn]<t[i+posm]) printf("<\n");
			else printf(">\n");
			return 0;
		}
	}
	printf("=\n");
	return 0;
}