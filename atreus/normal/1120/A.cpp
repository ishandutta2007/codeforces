#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 5e5 + 10;

int a[maxn], b[maxn], x[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int m, k, n, s;
	cin >> m >> k >> n >> s;
	for (int i = 0; i < m; i++)
		cin >> a[i];
	int cnt = 0;
	for (int i = 0; i < s; i++){
		cin >> x[i];
		b[x[i]] ++;
		if (b[x[i]] == 1)
			cnt ++;
	}
	int r = 0;
	for (int l = 0; l < m; l++){
		r = max(r, l);
		while (cnt > 0 and r < m){
			b[a[r]] --;
			if (b[a[r]] == 0)
				cnt --;
			r ++;
		}
		if (cnt == 0){
			if (l / k + 1 + (m - r) / k >= n){
				cerr << "# " << l << " " << r << endl;
				vector<int> ans;
				for (int i = 0; i < l % k; i++)
					ans.push_back(i);
				memset(b, 0, sizeof b);
				for (int i = 0; i < s; i++)
					b[x[i]] ++;
				for (int i = l; i < r; i++){
					if (b[a[i]] > 0 or k - s > 0){
						k --;
						if (b[a[i]] > 0){
							b[a[i]] --;
							s --;
						}
					}
					else
						ans.push_back(i);
				}
				cout << ans.size() << endl;
				for (auto it : ans)
					cout << it + 1 << " ";
				cout << endl;
				return 0;
			}
		}
		b[a[l]] ++;
		if (b[a[l]] == 1)
			cnt ++;
	}
	cout << -1 << endl, 0;
}