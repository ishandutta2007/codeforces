#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

ll power(ll a, ll b){
	if (b == 0)
		return 1;
	ll ret = power(a, b / 2);
	ret = ret * ret % mod;
	if (b & 1)
		ret = ret * a % mod;
	return ret;
}	

int a[maxn], x[maxn], ans[maxn];
vector <int> query[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++){
		int l;
		cin >> l >> x[i];
		query[l].push_back(i);
	}
	
	set <int> s;
	s.insert(0);
	for (int i = 1; i <= n; i++){
		if (s.find(a[i]) == s.end()){
			vector <int> tmp;
			for (auto it : s)
				tmp.push_back(it ^ a[i]);
			for (auto it : tmp)
				s.insert(it);
		}
		for (auto Query : query[i]){
			if (s.find(x[Query]) == s.end()){
				ans[Query] = 0;
				continue;
			}
			else{
				int cnt = log2(s.size());
				ans[Query] = power(2, i - cnt); 
			}
		}
	}
	for (int i = 1; i <= m; i++){
		cout << ans[i] << '\n';
	}
}