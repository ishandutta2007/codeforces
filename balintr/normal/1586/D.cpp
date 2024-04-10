    #include <bits/stdc++.h>
    using namespace std;
     
    typedef unsigned uint;
    typedef long long ll;
    typedef unsigned long long ull;
    typedef pair<int, int> pii;
    typedef pair<ll, ll> pll;
    typedef vector<int> vi;
    typedef vector<pii> vpii;
    typedef complex<double> cmplx;
    template <typename T> using minPq = priority_queue<T, vector<T>, greater<T>>;
    #define boost() cin.sync_with_stdio(0); cin.tie(0)
    #define pb push_back
    #define eb emplace_back
    #define fs first
    #define sn second
    #define ALL(v) (v).begin(), (v).end()
    #define LAST(v) (v)[SZ(v)-1]
    #define SZ(v) ((int) (v).size())
    #define ms(a, x) memset(a, x, sizeof(a))
    template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
    inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
    inline constexpr ll lg2(ll x){return 64 - __builtin_clzll(x);} // Num used bits
    const int INF = 0x3f3f3f3f;
    const ll LLINF = 0x3f3f3f3f3f3f3f3f;
    const double PI = acos(-1);
     
    const int MN = 105;
    int arr[MN];
    int n;
    int nxt[MN];
     
    int main(){
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cout << '?';
            for (int j = 1; j <= n; ++j) {
                cout << (i == j ? " 1" : " 2");
            }
            cout << endl;
            int res; cin >> res;
            if(res != i) nxt[res] = i;
     
            cout << '?';
            for (int j = 1; j <= n; ++j) {
                cout << (i == j ? " 2" : " 1");
            }
            cout << endl;
            cin >> res;
            if(res != i) nxt[i] = res;
        }
     
        int a = nxt[0];
        for(int i = 1; i <= n; ++i){
            arr[a] = i;
            a = nxt[a];
        }
        
        cout << '!';
        for(int i = 1; i <= n; ++i) cout << ' ' << arr[i];
        cout << endl;
    }