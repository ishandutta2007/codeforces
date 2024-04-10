#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 3e5 + 10;

int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	vector<pair<int,int> > opes;
	for (int i = 1; i <= n; i++){
		if (i == a[i])
			continue;
		if (a[i] - i >= n / 2){
			opes.push_back({i, a[i]});
			swap(a[i], a[a[i]]);
		}
		else{
			if (n - i >= n / 2){
				opes.push_back({i, n});
				if (n - a[i] >= n / 2){
					opes.push_back({a[i], n});
					swap(a[i], a[n]);
					swap(a[n], a[a[n]]);
				}
				else{
					opes.push_back({1, n});
					opes.push_back({1, a[i]});
					opes.push_back({1, n});
					swap(a[i], a[n]);
					swap(a[1], a[n]);
					swap(a[1], a[a[1]]);
					swap(a[1], a[n]);
				}
			}
			else{
				opes.push_back({i, 1});
				opes.push_back({1, a[i]});
				opes.push_back({i, 1});
				swap(a[i], a[a[i]]);
			}
		}
		i --;
	}
	cout << opes.size() << '\n';
	for (auto it : opes)
		cout << it.first << " " << it.second << '\n';
}