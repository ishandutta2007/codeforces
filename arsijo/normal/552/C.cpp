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
const int MAX = 400010;
const ld E = 1e-11;

void no(){
	cout << "NO";
	exit(0);
}

int main() {

	sync;

	int w, m;
	cin >> w >> m;

	int a = 0;
	while(m != 0){
		int b = (m % w) + a;
		a = 0;
		m /= w;
		if(b <= 1){
			continue;
		}else if(b >= w - 1){
			a = 1;
			continue;
		}else{
			no();
		}
	}

	cout << "YES";

}