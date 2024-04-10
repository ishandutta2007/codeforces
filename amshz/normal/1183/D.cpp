# include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int xn = 2e5+10;
int a[xn];

int main(){
	int qq;
	cin >> qq;
	while (qq--){
		int n;
		cin >> n;
		map <int, int> cnt, mp;
		for (int i=0; i<n; i++) cin >> a[i], cnt[a[i]]++;
		for (int i=1; i<=n; i++) mp[cnt[i]]++;
		int p = n;
		int t = 0;
		ll ans = 0;
		for (int i=n; i>=0; i--){
			t += mp[i];
			if (t > 0){
				t--;
				ans += i;
			}
		}
		//cout << "ans : ";
		cout << ans << endl;
	}
}