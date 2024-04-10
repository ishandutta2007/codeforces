#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef double ld;
typedef map<int, int>::iterator mit;
typedef set<int>::iterator si;
const ld E = 1e-11;

#ifdef LOCAL
const ll MAX = 1001;
///#define DEBUG
#else
const ll MAX = 1e6 + 1;
#endif

int main() {

	sync;

#ifdef LOCAL
	input;
#ifdef DEBUG
//output;
#endif
#else

#endif

	bool find[MAX];
	ms(find);

	int n;
	cin >> n;

	char c[n];
	int ar[n];
	for(int i = 0; i < n; i++)
		cin >> c[i] >> ar[i];

	int g[n];
	ms(g);

	for(int i = 0; i < n; i++){
		if(c[i] == '+'){
			find[ar[i]] = true;
		}else{
			if(!find[ar[i]]){
				g[i]++;
			}
			find[ar[i]] = false;
		}
	}

	for(int i = n - 2; i >= 0; i--)
		g[i] += g[i + 1];

	int a = 0, e = 0;
	ms(find);
	for(int i = 0; i < n; i++){
		if(c[i] == '+'){
			a++;
			find[ar[i]] = true;
		}else{
			if(find[ar[i]])
				a--;
			find[ar[i]] = false;
		}
		e = max(e, a + g[i]);
	}

	cout << e;
}