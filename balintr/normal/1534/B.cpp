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
#define sc second
#define ALL(v) (v).begin(), (v).end()
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}

const int MN = 4e5 + 5;
int t, n;
int arr[MN];

int main(){
    boost();
    cin >> t;
    while(t--){
        ll val = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        arr[n+1] = 0;

        for (int i = 0; i <= n; ++i) {
            val += abs(arr[i+1] - arr[i]);
        }
        for (int i = 1; i <= n; ++i) {
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) val -= min(arr[i] - arr[i-1], arr[i] - arr[i+1]);
        }
        cout << val << '\n';
    }
}