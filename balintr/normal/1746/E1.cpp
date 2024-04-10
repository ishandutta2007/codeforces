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
#define dbgArr(arr, n) {cerr << #arr; FR(_i, n) cerr << ' ' << (arr)[_i]; cerr << endl;}

int n;
set<int> st;

bool qry(const vi &v){
    cout << "? " << SZ(v);
    for(int a : v) cout << ' ' << a;
    cout << endl;

    string str; cin >> str;
    return str == "YES";
}

void guess(int x){
    cout << "! " << x << endl;
    string str; cin >> str;
    if(str == ":)") exit(0);
}

int main(){
    boost();
    cin >> n;
    FR(i, n) st.insert(i+1);

    while(SZ(st) >= 4){
        vi vec1;
        auto it = st.begin();
        FR(i, SZ(st)/2) vec1.pb(*it), ++it;
        bool res1 = qry(vec1);

        vi vec2;
        for(int a : st) if(res1 != binary_search(ALL(vec1), a)) vec2.pb(a);
        vec2.resize(SZ(vec2)/2);
        bool res2 = qry(vec2);

        it = st.begin();
        while(it != st.end()){
            bool claimIn1 = res1 == binary_search(ALL(vec1), *it);
            bool claimIn2 = res2 == binary_search(ALL(vec2), *it);
            if(!claimIn1 && !claimIn2) it = st.erase(it);
            else ++it;
        }
    }

    if(SZ(st) == 3){
        int a = *st.begin();
        int b = *++st.begin();
        int c = *++++st.begin();

        bool res1 = qry({a});

        if(res1){
            bool res2 = qry({b});
            if(res2) st.erase(c);
            else st.erase(b);
        }
        else {
            bool res2 = qry({a});

            if(res2){
                guess(a);
                if(qry({b})) guess(b);
                else guess(c);
            }
            else st.erase(a);
        }
    }

    assert(SZ(st) <= 2);
    for(int a : st) guess(a);
}