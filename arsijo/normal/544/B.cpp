#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define io input; output;
#define x first
#define y second
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define print2(ar, n, m) for(int i = 0; i < n; i++){ for(int j = 0; j < m; j++) cout << ar[i][j]; cout << endl; }
#define print(ar, n) for(int i = 0; i < n; i++) cout << ar[i] <<  " ";
#define sqr(a) ((a) * (a))
#define endl "\n"
//#define mod % 1000000007
typedef pair<int, int> ii;
typedef long long ll;
typedef long double ld;
const int MAX = 1e5;
const ld E = 1e-9;

int main(){

	int n, k;
	cin >> n >> k;

	bool ar[n + 1][n + 1];
	ms(ar);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(k > 0 && !ar[i - 1][j] && !ar[i][j - 1]){
				ar[i][j] = true;
				k--;
			}

	if(k == 0){
		cout << "YES" << endl;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++)
				cout << (ar[i][j] ? 'L' : 'S');
			cout << endl;
		}
	}else{
		cout << "NO";
	}

}