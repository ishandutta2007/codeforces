#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

ll n, k, A, x[N], c[N], ans;
multiset <ll> s;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> x[i];  
	cin >> A;
	for(int i = 1; i <= n; ++i){
		cin >> c[i];
	} 
	for(int i = 1; i <= n; ++i){
		s.insert(c[i]);
		while((int)s.size() > 0 && k < x[i]){
			ll y = *s.begin();
			s.erase(s.begin());
			ans += y;
			k += A;
		}
		if(k < x[i]){
			cout << -1;
			return 0;
		}
	}
	cout << ans;
	return 0;
}