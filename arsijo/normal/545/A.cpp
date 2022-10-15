#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define print2(ar, n, m) for(int i = 0; i < n; i++){ for(int j = 0; j < m; j++) cout << ar[i][j]; cout << endl; }
#define print(ar, n) for(int i = 0; i < n; i++) cout << ar[i] <<  " ";
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef pair<int, int> ii;
typedef long long ll;
typedef long double ld;
typedef map<int, int>::iterator mit;
const int MAX = 2e5;
const ld E = 1e-11;

int main() {

	sync;

	int n;
	cin >> n;

	bool bol[n];
	ms(bol);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			int a;
			cin >> a;
			if(a == 1 || a == 3)
				bol[i] = true;
			if(a == 2 || a == 3)
				bol[j] = true;
		}

	vector<int> ans;
	for(int i = 0; i < n; i++)
		if(!bol[i])
			ans.push_back(i + 1);

	cout << ans.size() << endl;
	for(int i = 0; i < (int) ans.size(); i++)
		cout << ans[i] << " ";


}