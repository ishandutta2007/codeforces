#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define pp(a, b) pb(mp(a, b))
#define get_bit(n, k) n&(1<<k)
#define endl '\n'
#define vl vector<ll>
#define PI 3.1415926535897932384626433832795
#define rad(deg) deg*PI/180
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200000
#define INF LLONG_MAX
#define NINF -INF-1
#define PAIR_OUT_PRE "("
#define PAIR_OUT_BTW ";"
#define PAIR_OUT_PST "), "
#define ARRAY_OUT_PRE "data: "
#define ARRAY_OUT_BTW ", "
#define ARRAY_OUT_PST endl
using namespace std;
template<typename T, typename D> ostream& operator<<(ostream& os, const pair<T, D> V){return os << PAIR_OUT_PRE << V.x << PAIR_OUT_BTW << V.y << PAIR_OUT_PST;}
template<typename T> ostream& operator<<(ostream& os, const vector<T> V){os << ARRAY_OUT_PRE; for(auto i:V)os << i << ARRAY_OUT_BTW; return os << ARRAY_OUT_PST;}
template<typename T, size_t S> ostream& operator<<(ostream& os, const array<T, S> V){os << ARRAY_OUT_PRE; for(auto i:V)os << i << ARRAY_OUT_BTW; return os << ARRAY_OUT_PST;}
/*--func--*/
template<typename T> ull fast_log(T a){ull c = 0;while((a>>(++c)) > 0);return c-1;}
map<char, vl> a1, a2;
ll c1[26], c2[26];
main(){
    FAST;
    ll n;
    char c;
    cin >> n;
    vector<ll> q_left, q_right;
    for(ll i =0;i<n;i++){
        cin >> c;
        a1[c].pb(i);
        if(c=='?') q_left.pb(i);
    }
    for(ll i =0;i<n;i++){
        cin >> c;
        a2[c].pb(i);
        if(c=='?') q_right.pb(i);
    }
    vector<pll> pairs;
    vector<ll> neozn_left, neozn_right;
    for(char i='a';i<='z';i++){
        for(ll j = 0;j<max(a1[i].size(), a2[i].size());j++){
            if(j < a1[i].size() && j < a2[i].size()){
                pairs.pp(a1[i][c1[i-'a']], a2[i][c2[i-'a']]);
                c1[i-'a']++;
                c2[i-'a']++;
            }else{
                if(j < a1[i].size()) neozn_left.pb(a1[i][j]);
                if(j < a2[i].size()) neozn_right.pb(a2[i][j]);
            }
        }
    }
    ll qrc=0, qlc=0;
    for(ll i = 0;i<min(q_right.size(), neozn_left.size());i++) pairs.pp(neozn_left[i], q_right[qrc++]);
    for(ll i = 0;i<min(q_left.size(), neozn_right.size());i++) pairs.pp(q_left[qlc++], neozn_right[i]);
    while(qrc!=q_right.size() && qlc!=q_left.size()){
        pairs.pp(q_left[qlc++], q_right[qrc++]);
    }
    cout << pairs.size() << endl;
    for(auto i : pairs){
        cout << i.x+1 << " " << i.y+1 << endl;
    }
}