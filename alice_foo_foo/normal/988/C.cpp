#include<bits/stdc++.h>
using namespace std;

const int N = 200000 + 10;

vector <int> a[N];
map <int, int> f[2];
int n, k;

int main() {
	cin >> k;
	for(int i = 1; i <= k; i++) {
		scanf("%d", &n);
		int sum = 0;
		for(int j = 1; j <= n; j++) {
			int tmp;
			scanf("%d", &tmp);
			sum += tmp;
			a[i].push_back(tmp); 
		}
		for(int j = 0; j < n; j++) {
			if(f[0][sum - a[i][j]] == 0) {
				f[0][sum - a[i][j]] = i;
				f[1][sum - a[i][j]] = j + 1;
			}
			else {
				if(f[0][sum - a[i][j]] == i) continue;
				cout << "YES" << endl;
				cout << f[0][sum - a[i][j]] << " " << f[1][sum - a[i][j]] << endl;
				cout << i << " " << j + 1;
				return 0;
			}
		}
	}
	cout << "NO";
	return 0;
}