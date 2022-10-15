#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define ms(x) memset(x, 0, sizeof(x));
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define y1 ngsdf
#define sqr(a) ( (a) * (a) )
#define x first
#define y second
#define sync ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
typedef pair<int, int> ii;
typedef long long ll;
typedef long double ld;
const ld E = 1e-9;
const int MAX = 1e6 + 1;

int main() {

	int a1 = 0, b1 = 0, a2 = 0, b2 = 0, n;
	cin >> n;
	while(n--){
		int a, b, c;
		cin >> a >> b >> c;
		if(a == 1){
			a1 += b;
			a2 += 10;
		}else{
			b1 += b;
			b2 += 10;
		}
	}

	cout << (a1 * 10 / a2 >= 5 ? "LIVE" : "DEAD") << endl;
	cout << (b1 * 10 / b2 >= 5 ? "LIVE" : "DEAD") << endl;

}