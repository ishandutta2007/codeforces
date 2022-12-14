#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

int last[maxn], a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	memset(last, -1, sizeof last);
	while (t --){
		int n;
		cin >> n;
		int answer = -1;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			if (last[a[i]] == -1){
				last[a[i]] = i;
				continue;
			}
			if (answer == -1 or answer > i - last[a[i]] + 1)
				answer = i - last[a[i]] + 1;
			last[a[i]] = i;
		}
		cout << answer << '\n';
		for (int i = 0; i < n; i++)
			last[a[i]] = -1;
	}
}