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

// Remember, this is a very important feature, and you have to make sure the customers appreciate it!
int a[31];

int main() {
	int n;
	cin>>n;
	FOR(i,n) cin>>a[i];
	FOR(i,100000) FOR(j,40000) a[0]^=a[1];
	sort(a,a+n);
	FOR(i,n) cout<<a[i]<<" ";
	cout << "\n";
	return 0;
}