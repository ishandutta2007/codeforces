#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int mod = (int)1e9 + 7;
int n;
set<pair<int, int> > S;
map<int, int> M;
int a[200100];
vector< pair<int, int> > ans;
int dp[200200];
int main () {
	cin >> n;
	
	for(int i = 1; i < n; i++) {
		scanf("%d", &a[i]);
		M[a[i]]++;
	}
	for(int i = 1; i <= n; i++) {
		if(M[i] == 0) S.insert(mp(i, i));
		dp[i] = i;
	}
	for(int i = n-1; i > 0; i--) {
		if(S.size() == 0) {
			cout << -1 << "\n";
			return 0;
		}
		pair<int, int> x = *S.begin();
		S.erase(S.begin());
		ans.push_back(mp(a[i], x.s));
		M[a[i]]--;
		dp[a[i]] = max(dp[a[i]], x.f);
		if(M[a[i]] == 0) {
			S.insert(mp(dp[a[i]], a[i]));
		}
	}
	cout << a[1] << "\n";
	for(int i = n-2; i >=0; i--) {
		cout << ans[i].f << " " << ans[i].s << "\n";
	}
 	return 0;
}