#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

int a[200200];
int n;
set < pii > S;
vector < int > v[200200];

vector < int > ans;
void dfs(int x){
	ans.pb(v[x].back());
	v[x].pop_back();
	if(v[x+1].size() > 0){
		dfs(x+1);
	}
	else if(x >= 2){
		x++;
		x -= 3;
		while(x >=0 && v[x].size() == 0) x-=3;
		if(x >= 0 ) dfs(x);
	}
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    	v[a[i]].pb(i+1);
    }
    int cur = 0;

    if(v[0].size() > 0) dfs(0);
    
    if(ans.size() == n) {
    	cout << "Possible\n";
    	for(int i = 0; i < n; i++)
    		cout << ans[i] << " ";
		cout << endl;
    }
    else cout << "Impossible\n";




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}