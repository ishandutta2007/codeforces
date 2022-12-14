#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const int mod = 998244353;

int cnt[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		for (int j = 0; j < 20; j++)
			if (x & (1 << j))
				cnt[j] ++;
	}
	ll answer = 0;
	for (int i = 0; i < n; i++){
		int x = 0;
		for (int j = 0; j < 20; j++){
			if (cnt[j]){
				x |= (1 << j);
				cnt[j] --;
			}
		}
		answer += 1ll * x * x;
	}
	cout << answer << endl;
}