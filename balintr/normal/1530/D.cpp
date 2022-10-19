#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, bool> pib;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<pib> vpib;
typedef int8_t int8;
typedef complex<double> cmplx;
template <typename T> using minPq = priority_queue<T, vector<T>, greater<T>>;
#define boost() cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 32 - __builtin_clzll(x);} // Num used bits
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

const int MN = 2e5 + 5;
int t, n;
int arr[MN], ans[MN];
int par[MN];

int main(){
    boost();
    cin >> t;
    while(t--){
        cin >> n;
        memset(ans, -1, n*sizeof(int));
        memset(par, -1, n*sizeof(int));

        int total = 0;
        vi sad, both;
        set<int> noPar;

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            arr[i]--;

            if(par[arr[i]] == -1){
                par[arr[i]] = i;
                ans[i] = arr[i];
                total++;
            }
            else {
                sad.pb(i);
            }
        }

        for (int i = 0; i < n; ++i) {
            if(par[i] == -1) noPar.insert(i);
        }
        for(int i : sad){
            if(par[i] == -1){
                both.pb(i);
                noPar.erase(i);
            }
        }

        for (int i = 0; i < both.size(); ++i) {
            ans[both[i]] = both[(i+1) % both.size()];
        }

        for(int i : sad){
            if(par[i] != -1){
                ans[i] = *noPar.begin();
                noPar.erase(noPar.begin());
            }
        }

        if(both.size() == 1){
            if(sad.size() == 1){
                int a = both[0];
                int b = par[arr[a]];
                swap(ans[a], ans[b]);
            }
            else {
                int a = both[0];
                int b;
                for(int i : sad){
                    if(par[i] != -1){
                        b = i;
                        break;
                    }
                }

                swap(ans[a], ans[b]);
            }
        }

        cout << total << '\n';
        for (int i = 0; i < n; ++i) {
            assert(ans[i] != i);
            cout << ans[i] + 1 << " \n"[i == n-1];
        }
    }
}