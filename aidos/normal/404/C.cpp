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
#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define sc second
#define pii pair<int,int>
#define pis pair<int, string>
#define psi pair<string, int>
using namespace std;
int a[111000], b[111000], n, k;
vector < int > v[111000];
vector < pii > ans;
int main () {
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    cin >> n >> k;
    for(int i = 0; i<n; i++){
    	cin >> b[i];
    	a[b[i]]++;
    }
    if(a[0] != 1){
    	cout << -1;
    	return 0;
    }
    for(int i = 1; i < n; i++){
    	if(a[i] > a[i-1] * 1ll*(k-1) && i != 1 || (i == 1 && a[1] > k)){
    		cout << -1;
    		return 0;
    	}
    }
    memset(a, 0, sizeof(a));
    for(int i=0; i<n; i++){
    	v[b[i]].pb(i);
    }
    for(int i = 1; i < n; i++){
    	for(int j=0; j < v[i].size(); j++){
    		int y = v[i][j], x = v[i-1][v[i-1].size()-1];
    		ans.pb(mp(x, y));
    		a[x]++;
    		a[y]++;
    		if(a[x] == k) v[i-1].pop_back();
    	}
    }
    cout << ans.size() << endl;
    for(int i = 0; i<ans.size(); i++)
    	cout << ans[i].ff+1 << " " << ans[i].sc+1 << endl;
    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}