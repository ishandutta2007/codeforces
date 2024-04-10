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
#define mod % 1000000007
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef map<int, int>::iterator mit;
const ld E = 1e-4;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 1e5 + 1;
//#define DEBUG
#else
const ll MAX = 1e6 + 1;
#endif

int main() {

	sync;

#ifdef LOCAL
	srand(time(NULL));
	input;
#else

#endif

	int n;
	cin >> n;

	int ar[n + 2];
	for(int i = 1; i <= n; i++)
		cin >> ar[i];
	ar[n + 1] = INT_MAX;

	int next[n + 2], prev[n + 2];
	for(int i = 0; i <= n + 1; i++){
		next[i] = i + 1;
		prev[i] = i - 1;
	}

	int pos = prev[n + 1];
	vector<int> kll;
	bool killed[n + 2];
	ms(killed);
	bool bol = false;
	while(pos > 0){
		int pr = prev[pos];
		if(pr <= 0)
			break;
		if(ar[pr] > ar[pos]){
			int nxt = next[pos];
			prev[nxt] = pr;
			next[pr] = nxt;
			killed[pos] = true;
			kll.push_back(pr);
			bol = true;
		}
		pos = pr;
	}

	int ans = 0;

	while(bol){
		bol = false;
		ans++;
		vector<int> vec;

		for(int i = 0; i < (int) kll.size(); i++){
			int v = kll[i];
			if(killed[v] || next[v] > n)
				continue;
			if(ar[v] > ar[next[v]]){
				killed[next[v]] = true;
				int nxt = next[next[v]];
				prev[nxt] = v;
				next[v] = nxt;
				vec.push_back(v);
				bol = true;
			}
		}

		kll.clear();
		kll.insert(kll.end(), vec.begin(), vec.end());

	}

	cout << ans << endl;

}