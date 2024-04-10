#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <sstream>
#include <tuple>
#include <vector>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 3e6;
const int M = 1e7;
const ll inf = 1e18;
const long long mod = 1e9 + 7;
const long long N = 3e5 + 10;


template <typename T> void vout(T s){cout << s << endl;exit(0);}

void solve(){
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i + 1 < n; i++){
        if(a[i] == 0 && a[i + 1] == 1){
            for(int j = 0; j <= i; j++){
                cout << j + 1 << " ";
            }
            cout << n + 1 << " ";
            for(int j = i + 1; j < n; j++){
                cout << j + 1 << " ";
            }
            cout << "\n";
            return;
        }
    }
    if(a[0] == 1){
        cout << n + 1;
        for(int i = 1; i <= n; i++){
            cout << " " << i;
        }
        cout << "\n";
        return;
    }
    if(a[n - 1] == 0){
        for(int i = 1; i <= n; i++){
            cout << i << " ";
        }
        cout << n + 1 << "\n";
        return;
    }
    cout << "-1\n";
}

int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    //t = 1;
    while(t--){
        solve();
    }

    return 0;
}