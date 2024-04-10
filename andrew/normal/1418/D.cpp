#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair <ll, ll>
#define pii pair <int, int>
#define m_p make_pair
#define all(x) x.begin(), x.end()
#define sqr(x) ((x) * (x))
#define pw(x) (1ll << x)
#define ifn(x) if(!(x))
#define fout(x) {cout << x << "\n"; return;}
#define sz(x) (int)x.size()

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
const int M = 3000 + 5;
const ll inf = 1e18;
const ll mod = 1e9 + 7;

template <typename T> void vout(T s) {cout << s << endl; exit(0);}

int _nxt[N][2][26];
int pref[N][2];

void add(ll &a, ll b){
    a += b;
    if(a >= mod)a -= mod;
}

int main(){

    ios_base :: sync_with_stdio(0);
    cin.tie(0);    

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, q;
    cin >> n >> q;

    set <ll> s;
    multiset <ll> st;

    set <ll> :: iterator l, r;

    ll ans = 0;

    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        if(s.empty()){
            s.insert(x);
        }else{
            r = s.upper_bound(x);
            if(r == s.begin()){
                st.insert(*r - x);
            }else{
                l = r;
                l--;
                if(r != s.end())st.erase(st.find(*r - *l));
                st.insert(x - *l);
                if(r != s.end())st.insert(*r - x);
            }
            s.insert(x);
        }
    }

    ans = *--s.end() - *s.begin();
    if(sz(st))ans -= *--st.end();
    cout << ans << "\n";
    while(q--){
        int t;
        ll x;
        cin >> t >> x;
        if(t == 1){
            if(s.empty()){
                s.insert(x);
            }else{
                r = s.upper_bound(x);
                if(r == s.begin()){
                    st.insert(*r - x);
                }else{
                    l = r;
                    l--;
                    if(r != s.end())st.erase(st.find(*r - *l));
                    st.insert(x - *l);
                    if(r != s.end())st.insert(*r - x);
                }
                s.insert(x);
            }
        }else{
            r = s.upper_bound(x);
            l = s.lower_bound(x);
            if(r != s.end())st.erase(st.find(*r - x));
            if(l != s.begin()){
                --l;
                if(r != s.end())st.insert(*r - *l);
                st.erase(st.find(x - *l));
            }
            s.erase(x);
        }
        if(s.empty())cout << "0\n";
        else{
            ans = *--s.end() - *s.begin();
            if(sz(st))ans -= *--st.end();
            cout << ans << "\n";
        }
    }
  
    return 0;
}