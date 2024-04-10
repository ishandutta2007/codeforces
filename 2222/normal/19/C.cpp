#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)		(a).begin(),(a).end()
#define sz(a)		int((a).size())
#define FOR(i,a,b)	for(int i=a;i<b;++i)
#define REP(i,n)	FOR(i,0,n)
#define UN(v)		sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)		memset(a,b,sizeof a)
#define pb			push_back
#define X			first
#define Y			second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int n, w;
int a[111111];
map<int, vi> F;

bool check (int i, int j) {
	w = 0;
	for (int k = j - i; k--; ++i, ++j, ++w)
		if (a[i] != a[j]) return false;
	return true;
}

vector <pii> q;

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	cin >> n;
	REP (i, n) {
		scanf("%d", a + i);
		F[a[i]].pb(i);
	}
	for (map<int, vi> :: iterator v = F.begin(); v != F.end(); ++v) {
		vi &V = v->Y;
		REP (j, sz(V)) REP (i, j) q.pb(pii(V[j] - V[i], V[i]));
	}
	sort(all(q));
	int l = 0;
	for (vector<pii> :: iterator i = q.begin(); i != q.end(); ++i) 
		if (i->Y >= l && i->X + i->X + i->Y <= n) {
			if (check(i->Y, i->Y + i->X))
				l = i->X + i->Y;
			else {
				i += w - 1;
			}
		}
	cout << (n - l) << endl;
	for (int i = l; i < n; ++i) {
		if (i != l) printf(" ");
		printf("%d", a[i]);
	}
	cout << endl;
	return 0;
}