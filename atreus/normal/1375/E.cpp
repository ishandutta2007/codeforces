#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
typedef complex<ld> point;
const int maxn = 1000 + 5;

int a[maxn];
vector<int> inv[maxn];
pair<int,int> b[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		b[i] = {a[i],i};
	}
	sort(b, b+n);
	for (int i = 0; i < n; i++)
		a[b[i].second] = i+1;
	int cinv = 0;
	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			if (a[j] < a[i])
				inv[i].push_back(j), cinv ++;
	cout << cinv << '\n';
	for (int i = 0; i < n; i++){
		sort(inv[i].begin(), inv[i].end(), [](int x, int y){
			return make_pair(a[x],x) > make_pair(a[y],y);
		});
		for (auto it : inv[i]){
			cout << i+1 << " " << it+1 << '\n';
			swap(a[i], a[it]);
		}
	}
	for (int i = 0; i < n-1; i++)
		assert(a[i] <= a[i+1]);
}