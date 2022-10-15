#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
//#define x first
//#define y second
#define mod % 1000000007
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef map<int, int>::iterator mit;
const ll MAX = 1000;
typedef ll array[MAX][MAX];
const ld E = 1e-11;

int ar[100][100];

void add(int x, int y, int val){
	for(int i = 0; i <= x; i++)
		for(int j = 0; j <= y; j++)
			ar[i][j] += val;
}

int main() {

	int n, m;
	cin >> n >> m;

	char s[n][m];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> s[i][j];

	int ans = 0;

	for(int i = n - 1; i >= 0; i--)
		for(int j = m - 1; j >= 0; j--){
			if(s[i][j] == 'W'){
				if(ar[i][j] != 1){
					add(i, j, 1 - ar[i][j]);
					ans++;
				}
			}else{
				if(ar[i][j] != -1){
					add(i, j, - 1 - ar[i][j]);
					ans++;
				}
			}
		}

	cout << ans;

}