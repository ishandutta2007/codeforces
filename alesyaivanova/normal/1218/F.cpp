#include <bits/stdc++.h>
 
#define int long long
 
#define pii pair<int, int>
 
#define x1 x1228
#define y1 y1228
 
#define left left228
#define right right228
 
#define pb push_back
#define eb emplace_back
 
#define mp make_pair                                                                
                                                                                                                                        
#define ff first                                                                  
#define ss second   
 
#define matr vector<vector<int> > 
 
#define all(x) x.begin(), x.end()
 
 
using namespace std;
typedef long long ll; 
typedef long double ld; 
                                                                                                   
const int maxn = 3e5 + 7, mod = 998244353, inf = 1e18, MAXN = 1e6 + 7;
const double eps = 1e-9;
mt19937 rnd(time(0));
int n, k, add; 
int a[maxn]; 
int b[maxn]; 

void solve() { 
    cin >> n >> k; 
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> add; 
    for (int i = 0; i < n; ++i) cin >> b[i];  
    multiset<int> ms; 
    int ans = 0; 
    for (int i = 0; i < n; ++i) {
        ms.insert(b[i]); 
        if (k < a[i]) {
            int ptr = (a[i] - k + add - 1) / add; 
            if (ms.size() < ptr) {
                cout << "-1";
                return; 
            }           
            k += ptr * add; 
//            cout << i << " " << ptr << " " << k << endl; 
            for (int j = 0; j < ptr; ++j) {
                auto v = ms.begin(); 
                ms.erase(v);
                ans += (*v);  
            }
        }
    }
    cout << ans; 
}                                
   
signed main() {
#ifdef LOCAL
    freopen("TASK.in", "r", stdin);
    freopen("TASK.out", "w", stdout);
#else 
    
#endif // LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20); 
    cout << fixed; 
    int t = 1; 
    for (int i = 0; i < t; ++i) {              
        solve();
    }
    return 0;
}