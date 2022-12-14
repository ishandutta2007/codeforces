#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 100000 + 5;
const int mod = 1e9 + 7;

pair<int,int> a[maxn];
ll par[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= m; i++)
			cin >> a[i].first >> a[i].second;
		sort(a+1, a+m+1);
		reverse(a+1, a+m+1);
		for (int i = 1; i <= m; i++)
			par[i] = par[i-1] + a[i].first;
		ll answer = 0;
		if (n <= m)
			answer = par[n];
		for (int i = 1; i <= m; i++){
			int A = a[i].first, B = a[i].second;
			int lo = 0, hi = m+1;
			while (hi-lo > 1){
				int mid = (lo+hi) >> 1;
				if (a[mid].first > B)
					lo = mid;
				else
					hi = mid;
			}
			if (lo < n){
				if (lo >= i)
					answer = max(answer, par[lo] + 1ll*(n-lo)*B);
				else
					answer = max(answer, par[lo] + A + 1ll*(n-lo-1) * B);
			}
		}
		cout << answer << '\n';
	}
}