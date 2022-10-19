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
#define ms(a, x) memset(a, x, sizeof(a))
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 32 - __builtin_clzll(x);} // Num used bits
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

const int MN = 2e5 + 5;
int t, n;
bool arr[MN];
int prv1s[MN], cont0s[MN];
vi ans;

void apply(int a){
    ans.pb(a);
    int v = arr[a] ^ arr[a+1] ^ arr[a+2];
    arr[a] = arr[a+1] = arr[a+2] = v;
}

void solveLeft(int start){
    for (int i = start-1; i >= 0; --i) {
        if(!arr[i]) continue;
        if(arr[i-1]) apply(i-1);
        else {
            apply(i-2);
            if(arr[i]) apply(i-1);
        }
    }
}

void solveRight(int start){
    for (int i = start+1; i < n; ++i) {
        if(!arr[i]) continue;
        if(arr[i+1]) apply(i-1);
        else {
            apply(i);
            if(arr[i]) apply(i-1);
        }
    }
}

int main(){
    boost();
    cin >> t;
    while(t--){
        cin >> n;
        ans.clear();
        prv1s[0] = 0;

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            prv1s[i] += arr[i];
            prv1s[i+1] = prv1s[i];

            if(arr[i]) cont0s[i] = 0;
            else cont0s[i] = i ? cont0s[i-1] + 1 : 1;
        }
        for (int i = n-2; i >= 0; --i) {
            if(arr[i] == 0) cont0s[i] = max(cont0s[i], cont0s[i+1]);
        }

        if(prv1s[n-1] & 1){
            cout << "NO\n";
            continue;
        }

        if(cont0s[0] == n){
            cout << "YES\n0\n";
            continue;
        }

        if(!arr[0]) solveRight(0);
        else if(!arr[n-1]) solveLeft(n-1);
        else {
            for (int i = 0; i < n; ++i) {
                if(arr[i]) continue;
                if(prv1s[i] % 2 == 0){
                    solveLeft(i);
                    solveRight(i);
                    break;
                }
                if(cont0s[i] & 1){
                    for(int a = i + cont0s[i] - 1; a >= i; a -= 2){
                        apply(a-1);
                    }
                    solveLeft(i-1);
                    solveRight(i+1);
                    break;
                }
            }
        }

        if(ans.size() == 0){
            cout << "NO\n";
            continue;
        }

        for (int i = 0; i < n; ++i) {
            assert(!arr[i]);
        }

        cout << "YES\n" << ans.size() << '\n';
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i]+1 << " \n"[i == ans.size() - 1];
        }
    }
}