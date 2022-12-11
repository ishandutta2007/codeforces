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

int chk[333];
char s[55];
int main() {
	chk['a'] = chk['e'] = chk['i'] = chk['o'] = chk['u'] = chk['1'] = chk['3'] = chk['5'] = chk['7'] = chk['9'] = 1;
	scanf("%s", s);
	int res=0;
	for(int i=0;s[i];i++) if (chk[s[i]]) res++;
	printf("%d\n", res);
	return 0;
}