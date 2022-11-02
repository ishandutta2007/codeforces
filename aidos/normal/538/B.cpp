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
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;



int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int t = 1000000;

    int n;
    cin >> n;
    vector < int > v;
    while(n > 0){
    	int x = n/t;
    	for(int i = 0; i < x; i++){
    		v.pb(t);
    	}
    	n %= t;
    	t/=10;
    }

    vector < int > ans;
    for(int j = 0; j < v.size(); ){
    	int k = j;
    	while( j < v.size() && v[k] == v[j]) j++;
    	if(ans.size() < j - k){
    		int x = j - k - ans.size();
    		for(int i = 0; i < ans.size(); i++)
    			ans[i] += v[k];
			for(int  i = 0; i<x; i++){
				ans.pb(v[k]);
			}
    	}
    	else {
    		int x = j - k;
    	    for(int  i = 0; i<x; i++){
				ans[i] += v[k];
			}
    	}
    }
    cout << ans.size() << endl;
    forit(it, ans){
    	cout << *it << " ";
    }



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}