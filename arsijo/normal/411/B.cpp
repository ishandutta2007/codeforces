#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define io input; output;
#define x first
#define y second
#define ll long long
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define print(ar, n, m)	for(int i = 0; i < n; i++){ for(int j = 0; j < m; j++) cout << ar[i][j]; cout << endl; }
#define ld long double
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1e9+7
const int MAX = 1e9;
const ld E = 1e-11;
typedef pair<int, int> ii;

int main() {

	sync;

	int n, m, k;
	cin >> n >> m >> k;

	bool block[k];
	ms(block);

	int ar[n][m];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> ar[i][j];

	int ans[n];
	ms(ans);

	for(int i = 0; i < m; i++){
		set<int> s1, s2;
		for(int j = 0; j < n; j++)
			if(ans[j] == 0 && ar[j][i] != 0){
				if(block[ar[j][i] - 1]){
					ans[j] = i + 1;
					continue;
				}
				if(s1.find(ar[j][i]) != s1.end())
					s2.insert(ar[j][i]);
				s1.insert(ar[j][i]);
			}
		for(int j = 0; j < n; j++)
			if(ans[j] == 0)
				if(s2.find(ar[j][i]) != s2.end())
					ans[j] = i + 1;
		for(set<int>::iterator it = s2.begin(); it != s2.end(); it++)
			block[*it-1] = true;
	}

	for(int i = 0; i < n; i++)
		cout << ans[i] << endl;

}