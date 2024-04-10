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
#define ms(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int) (v).size())
#define lbv(v, x) (lower_bound((v).begin(), (v).end(), x) - (v).begin())
#define ubv(v, x) (upper_bound((v).begin(), (v).end(), x) - (v).begin())
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
#define FR(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define dbg(x) {cerr << #x << ' ' << x << endl;}
#define dbgArr(arr, n) {cerr << #arr; FR(_i, n) cerr << ' ' << arr[_i]; cerr << endl;}

int t, n;
string str;
int lst[26];
int freq[26];

bool solve(){
    cin >> str;
    n = SZ(str);
    ms(lst, -1);

    FR(i, n){
        char ch = str[i] -= 'a';
        ms(freq, 0);
        FOR(j, lst[ch]+1, i) if(freq[str[j]]++) return false;
        lst[ch] = i;
    }

    FR(ch, 26){
        if(lst[ch] == -1) continue;
        ms(freq, 0);
        FOR(j, lst[ch]+1, n) if(freq[str[j]]++) return false;
    }

    return true;
}

int main(){
    boost();
    cin >> t;
    while(t--){
        cout << (solve() ? "YES\n" : "NO\n");
    }
}