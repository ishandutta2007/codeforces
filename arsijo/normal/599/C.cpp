#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define endl "\n"
#define def(f) make(#f);
typedef long long ll;
typedef unsigned int ui;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
#ifdef LOCAL
typedef double ld;
#else
typedef long double ld;
#endif
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
typedef pair<string, string> ss;
const ld E = 1e-8;
const ll MOD = 1e9 + 7;
#define mod % MOD

#ifdef LOCAL
//#define DEBUG
#endif

const int MAX = 1e5;

#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

int main() {

    sync;
#ifdef LOCAL
    input;
#else

#endif

    int n;
    cin >> n;

    int ar[n];
    for(int i = 0; i < n; i++)
    cin >> ar[i];

    int suf_max[n], suf_min[n];
    suf_max[n - 1] = suf_min[n - 1] = ar[n - 1];
    for(int i = n - 2; i >= 0; i--){
    	suf_max[i] = max(suf_max[i + 1], ar[i]);
    	suf_min[i] = min(suf_min[i + 1], ar[i]);
    }

    int ans = 1;
    int mi = ar[0], ma = ar[0];
    for(int i = 1; i < n; i++){
    	//cout << ar[i] << " " << mi << " " << ma << " " << suf_max[i] << " " << suf_min[i] << endl;
    	if(suf_min[i] >= ma){
    		ans++;
    	}
    	mi = min(mi, ar[i]);
    	ma = max(ma, ar[i]);
    }

    cout << ans;

}