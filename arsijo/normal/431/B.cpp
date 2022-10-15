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
#define mod % 1000000007
typedef pair<int, int> ii;
typedef long long ll;
typedef long double ld;
typedef map<int, int>::iterator mit;
const int MAX = 1e5;
const ld E = 1e-11;

int ar[5][5], a[5], ans = INT_MIN;
bool used[5];

void update(int pos = 0, int sum = 0){
	if(pos == 5){
		ans = max(ans, sum);
		return;
	}
	for(int i = 0; i < 5; i++){
		if(!used[i]){
			used[i] = true;
			a[pos] = i;
			int s = sum;
			if(pos != 0){
				int j = a[pos - 1];
				s += ar[i][j] + ar[j][i];
				if(pos >= 3)
					s += ar[i][j] + ar[j][i];
			}
			update(pos + 1, s);
			used[i] = false;
		}
	}
}

int main() {

	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			cin >> ar[i][j];

	ms(used);
	update();
	cout << ans;

}