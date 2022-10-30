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
#define N 300000
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
#define stopit {cout << ":(";exit(0);}
ll n;
short type[N];
vector<ll> as;
void prepare(ll l, ll r){
    ll x = 0;
    for(;l<=r;l++){
        type[l] = x+1;
        x++;
        x&=1;
    }
}
ll opens = 0, close = 0;
void generate_(ll pos, vector<ll> last_close, ll open = 0){
    if(pos >= n) return;
    if(type[pos]!=0) generate_(pos+1, last_close, open + (type[pos]==1 ? 1 : (-1)));
    else{
        if(open < 0){
            ll x = last_close.size() - 1;
            while(x>=0 && open < 0){
                type[last_close[x]] = 1;
                last_close.erase(last_close.end()-1);
                x--;
                open+=2;
            }
        }
        if(open == 0){
            type[pos] = 1;
            generate_(pos+1, last_close, open+1);
        }else if(open > 0){
            type[pos] = 2;
            last_close.pb(pos);
            generate_(pos+1, last_close, open-1);
        }
    }
}
void generate_old(ll pos, ll done){
    if(pos >= n-1) return;
    if(type[pos]!=0) generate_old(pos+1, done);
    else{
        if(done < (n-1)/2 - opens) type[pos] = 1;
        else type[pos] = 2;
        generate_old(pos+1, done+1);
    }
}
void check(){
    ll cnt = 0;
    for(ll i =0;i<n;i++){
        if(type[i] == 1) cnt++;
        else if(type[i] == 2) cnt--;
        if((cnt == 0 && i!=n-1) || cnt < 0) {stopit;}
    }
    if(cnt != 0) {stopit;}
}
main(){
    FAST;
    cin >> n;
    if(n%2==1)stopit;
    for(ll i =0;i<n;i++){
        char c;
        cin >> c;
        if(c == '(') type[i] = 1;
        if(c == ')') type[i] = 2;
        if(c == '(' || c == ')') as.pb(i);
        if(i > 0 && i < n-1){
            if(c == '(') opens++;
            if(c == ')') close++;
        }
    }
    if(type[0] == 2 || type[n-1] == 1){
        cout << ":(";
        exit(0);
    }else{
        type[0] = 1;
        type[n-1] = 2;
        /*reverse(itr(as));
        ll lst = n-1;
        for(auto i : as){
            if(i == 0 || i == n-1) continue;
            if(type[i] == 1 && type[lst] == 2){
                if((lst - i + 1)%2==1) {
                    cout << ":(";
                    exit(0);
                }else{
                    prepare(i+1, lst-1);
                }
            }
            if(type[i] == 1 && type[lst] == 1){
                if((lst - i + 1)%2==0) {
                    cout << ":(";
                    exit(0);
                }else{
                    prepare(i+1, lst-1);
                }
            }
        }*/
        vector<ll> emp;
        generate_old(1, 0);
    }
    check();
    for(ll i =0;i<n;i++) if(type[i] == 1) cout << "(";else cout << ")";
}