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
//#define x first
//#define y second
#define mod % 1000000007
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef map<int, int>::iterator mit;

#define DEBUG 0
#if DEBUG == 1
const int MAX = 5e3 + 1;
#else
const int MAX = 5e6 + 1;
#endif
const ld E = 1e-11;


int main() {

	sync;

	ll sum[MAX];
	ms(sum);

	for(int i = 2; i < MAX; i++)
		if(sum[i] == 0){
			sum[i] = 1;
			for(int j = 2; j * i < MAX; j++){
				int a = j * i;
				while(a != 1 && a % i == 0){
					sum[j * i]++;
					a /= i;
				}
			}
		}

	for(int i = 3; i < MAX; i++)
		sum[i] += sum[i - 1];

	int t;
	cin >> t;

	while(t--){
		int l, r;
		cin >> r >> l;
		cout << sum[r] - sum[l] << endl;
	}

}