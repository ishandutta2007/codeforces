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

    bool res = true;

    int n, m;
    cin >> n >> m;

    int ans[m];
    vector<int> vec[n + 1];

    for(int i = 0; i < n; i++){
    	int a;
    	cin >> a;
    	vec[a].push_back(i + 1);
    }

    for(int i = 0; i < m; i++){
    	int a;
    	cin >> a;
    	if(vec[a].empty()){
    		cout << "Impossible";
    		exit(0);
    	}
    	if(vec[a].size() > 1){
    		res = false;
    		continue;
    	}
    	ans[i] = vec[a][0];
    }

    if(res){
    	cout << "Possible" << endl;
    	for(int i = 0; i < m; i++)
    		cout << ans[i] << " ";
    }else{
    	cout << "Ambiguity";
    }

}