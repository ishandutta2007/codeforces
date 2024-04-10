#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define io input; output;
#define x first
//#define y second
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
const int MAX = 1e5;
const ld E = 1e-11;

int main() {

	sync;

	int n, t;
	cin >> n >> t;

	vector<int> v[t + 1];

	while(n--){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}

	for(int i = 1; i < t; i++){
		sort(v[i].rbegin(), v[i].rend());
		if(v[i].size() % 2 == 1)
			v[i].push_back(0);
		for(int j = 0; j < (int) v[i].size(); j += 2)
			v[i + 1].push_back(v[i][j] + v[i][j + 1]);
	}

	sort(v[t].rbegin(), v[t].rend());
	cout << v[t][0];


}