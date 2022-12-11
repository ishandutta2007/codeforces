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

const int N = 1000100;

char s[N], res[N];
int n;
int len;
int c[3];

int main() {
	scanf("%s", s);
	for (n=0; s[n]; n++) ;
	int i=0;
	for (i = 0; i+1 < n-i-2; i += 2) {
		c[0]=c[1]=c[2]=0;
		c[s[i]-'a']++;
		c[s[i+1]-'a']++;
		c[s[n-i-1]-'a']++;
		c[s[n-i-2]-'a']++;
		if (c[0] >= 2) res[i/2]='a';
		else if (c[1] >= 2) res[i/2]='b';
		else res[i/2]='c';
		len++;
	}
	int pos = len;
	if (i <= n-i-1) res[pos++] = s[i];
	for (int j = len-1; j >= 0; j--) res[pos++] = res[j];
	printf("%s\n", res);
	return 0;
}