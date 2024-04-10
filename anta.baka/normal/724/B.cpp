#include <bits/stdc++.h>
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
// head

bool can(vector<vector<int>> &a, int n, int m) {
	for(int i = 0; i < n; i++) {
		int cnt = 0;
		for(int j = 0; j < m; j++)
			if(a[i][j] != j+1)
				cnt++;
		if(cnt > 2)
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n,vector<int>(m));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	if(can(a,n,m)) {
		cout << "YES";
		return 0;
	}
	for(int j = 0; j < m; j++)
		for(int k = j+1; k < m; k++) {
			for(int i = 0; i < n; i++)
				swap(a[i][j], a[i][k]);
			if(can(a,n,m)) {
				cout << "YES";
				return 0;
			}
			for(int i = 0; i < n; i++)
				swap(a[i][j], a[i][k]);
		}
	cout << "NO";
}