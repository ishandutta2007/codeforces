#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1000 + 10;
const int mod = 1e9 + 7;

int d[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int n, v;
		cin >> n >> v;
		if (n == 1){
			cout << "Ayush\n";
			continue;
		}
		d[v] = 0;
		for (int i = 1; i < n; i++){
			int x, y;
			cin >> x >> y;
			d[x] ++, d[y] ++;
		}
		if (d[v] == 1 or (n - 1) & 1)
			cout << "Ayush\n";
		else
			cout << "Ashish\n";
	}
}