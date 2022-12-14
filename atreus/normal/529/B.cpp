#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e6 + 10;
const int mod = 1e9 + 9;
const int base = 11;

ll w[maxn], h[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> w[i] >> h[i];
	// sigma w[i] * max(h[i])
	ll answer = 1000000000;
	for (int H = 1; H <= 1000; H++){
		bool can = 1;
		for (int i = 0; i < n; i++)
			if (min(w[i], h[i]) > H)
				can = 0;
		if (can == 0)
			continue;
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (h[i] > H)
				cnt ++;
		if (cnt > n / 2)
			continue;
		int now = (n / 2) - cnt;
		vector<int> v;
		ll W = 0;
		for (int i = 0; i < n; i++){
			if (h[i] > H){
				W += h[i];
				continue;
			}
			if (w[i] <= H and h[i] <= H)
				v.push_back(h[i] - w[i]);
			W += w[i];
		}
		sort(v.begin(), v.end());
		for (int i = 0; now and i < v.size(); i++){
			if (v[i] > 0)
				break;
			W += v[i];
			now --;
		}
		answer = min(answer, W * H);
	}
	cout << answer << endl;
}