#include <bits/stdc++.h>

#define F first
#define S second
#define pii pair<int, int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e5 + 10;

int d[N], b[N];
ll sum = 0;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k; cin >> n >> k;
	for(int i=1; i<=n; i++)
		for(int j=2*i; j<=n; j+=i)
			d[j] ++, sum ++;
	if(sum < k)return cout << "No\n", 0;

	ll ps = 0;
	for(int i=1; i<=n; i++){
		ps += d[i];
		if(ps >= k){n = i; break;}
	}
	vector<int> ans;
	for(int i=1; i<=n; i++){
		int degree = d[i] + (n / i) - 1 - b[i];
		if(ps - degree < k){
			ans.pb(i);
			continue;
		}
		ps -= degree;
		for(int j=2*i; j<=n; j+=i)
			b[j] ++;
	}
	if(ps > k)return cout << "No\n", 0;
	cout << "Yes\n" << ans.size() << '\n';
	for(auto x : ans)
	    cout << x << ' '; cout << endl;
}