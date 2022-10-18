#include<bits/stdc++.h>
 
using namespace std;

#define int int64_t

signed main() {
	//freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int used[n];
	fill(used, used + n, 0);
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(!used[i]) {
			ans++;
			for(int j = i; j < n; j++) {
				if(a[j] % a[i] == 0) {
					used[j] = 1;
				}
			}
		}
	}
	cout << ans << endl;
}