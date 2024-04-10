#include <bits/stdc++.h>


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
#define fout(x) {cout << x << "\n"; return;}
#define ifn(x) if(!(x))

using namespace std;
typedef long long ll;
typedef long double ld;
const ll N = 2e5 + 100;
const ll MAXN = 1123456;
const ll inf = 1e18;
const ll M = 59051;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    string s;
    ll n;
    cin >> s;
    n = sz(s);

    set <ll> st;
    for(int i = 0; i < sz(s); i++)if(s[i] == '(')st.insert(i);
    vector <ll> v;

    for(int i = sz(s) - 1; i >= 0; i--)if(s[i] == ')'){
        if(*st.begin() <= i){
            v.p_b(i);
            v.p_b(*st.begin());
            st.erase(st.begin());
        }
    }

    if(v.empty())vout(0);
    cout << "1\n" << sz(v) << "\n";
    sort(all(v));
    for(auto i : v)cout << i + 1 << " ";
    cout << "\n";
    return 0;

}