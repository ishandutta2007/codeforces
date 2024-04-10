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
const int mod = (int) 1e9 + 7;

using namespace std;

int n, k, p;
vector < int > ans[maxn];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> k >> p;
    vector < int > v[4];
    for(int i = 0, x; i < n; i++){
        cin >> x;
        v[x % 2].pb(x);
    }
    int ts = 0;
    for(int i = 0; i < p; i++){
        if( v[0].size() > 0){
            ans[ts].push_back(v[0].back());
            v[0].pop_back();
        }
        else if( v[1].size() > 1){
            ans[ts].push_back(v[1].back());
            v[1].pop_back();
            ans[ts].push_back(v[1].back());
            v[1].pop_back();
        }
        else {
            cout << "NO\n";
            return 0;
        }
        ts++;
    }
    for(int i = p; i<k; i++){
        if( v[1].size() > 0){
            ans[ts].push_back(v[1].back());
            v[1].pop_back(); 
        }
        else{
            cout << "NO\n";
            return 0;
        }
        ts++;
    }
    if( v[1].size() % 2){
        cout << "NO\n";
        return 0;
    }
    while(v[1].size()> 0){
        ans[0].push_back(v[1].back());
        v[1].pop_back();
    }
    while(v[0].size() > 0){
        ans[0].push_back(v[0].back());
        v[0].pop_back();
    }
    cout << "YES\n";
    for(int i = 0; i < k; i++){
        cout << ans[i].size() << " ";
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " " ;
        }
        cout << endl;
    }


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}