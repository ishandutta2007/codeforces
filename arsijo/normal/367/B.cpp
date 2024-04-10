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
map<int, int> b;
void add(int pos, int val){
	b[pos] += val;
	if(!b[pos])
		b.erase(pos);
}

int main() {

	sync;

#ifdef LOCAL
	srand(time(NULL));
	input;
#else

#endif

	int n, m, p;
	//cin >> n >> m >> p;
	scanf("%d%d%d", &n, &m, &p);

	if((ll) m * p > n){
		cout << 0;
		return 0;
	}

	vector<int> ans;
	ans.reserve(n);

	int ar[n];
	for(int i = 0; i < n; i++){
	//	cin >> ar[i];
		scanf("%d", &ar[i]);
	}

	map<int, int> f;
	int a;
	for(int i = 0; i < m; i++){
		//cin >> a;
		scanf("%d", &a);
		f[a]--;
	}


	int g = p * (m - 1);

	for(int i = 0; i < p; i++){

		b = f;

		for(int j = i, sum = 0; j < n; j += p){
			add(ar[j], 1);
			sum++;
			if(sum > m){
				add(ar[j - p * m], -1);
				sum--;
			}
			if(b.empty())
				ans.push_back(j + 1 - g);
		}

	}

	sort(ans.begin(), ans.end());
	//cout << ans.size() << endl;
	printf("%d\n", ans.size());
	for(int i = 0; i < (int) ans.size(); i++)
		printf("%d ", ans[i]);
		//cout << ans[i] << " ";

}