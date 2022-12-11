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

map<int,int> M;

int nim(int n) {
	if (M.find(n) != M.end()) return M[n];
	if (n%2==1 && n>6) return 0;
	if (n%2==1) return M[n] = nim(n-1)==0 ? 1 : 0;
	int a = nim(n/2), b = nim(n-1);
	if (a!=0 && b!=0) return M[n]=0;
	if (a!=1 && b!=1) return M[n]=1;
	return M[n]=2;
}
int main () {
	int n,k,a,res=0;
	scanf("%d%d", &n, &k);
	k %= 2;
	M[0]=0;
	M[1]=1;
	FOR(i,n) {
		scanf("%d", &a);
		if (k&1) {
			res ^= nim(a);
		} else {
			if (a<3) res ^= a;
			else res ^= 1-(a&1);
		}
		//printf("res=%d\n",res);
	}
	printf("%s\n", res==0 ? "Nicky" : "Kevin");
	return 0;
}