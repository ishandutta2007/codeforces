#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 100005
#define INF 101111111111111
#define NINF -INF-1
#define F(i, n) for(ll i =0;i<n;i++)
using namespace std;
template<typename T, typename D> ostream& operator<<(ostream& os, const pair<T, D> V){return os << "(" << V.x << ";" << V.y << ")";}
template<typename T> ostream& operator<<(ostream& os, const vector<T> V){os << "array: " << endl; for(auto i:V)os << i << " "; return os << endl;}
template<typename T, size_t S> ostream& operator<<(ostream& os, const array<T, S> V){os << "vector: " << endl; for(auto i:V)os << i << " "; return os << endl;}
string s;
array<ll, 26> t[4*N];
array<ll, 26> t_merge(array<ll, 26> tl, array<ll, 26> tr){
    array<ll, 26> res;
    for(ll i = 0;i<26;i++) res[i] = tl[i] + tr[i];
    return res;
}
void build(ll v, ll tl, ll tr){
    if(tl == tr){
        t[v][s[tl-1]-'a'] = 1;
        return;
    }
    ll tm = (tl+tr)>>1;
    build(v*2, tl, tm);
    build(v*2+1, tm+1, tr);
    t[v] = t_merge(t[v*2], t[v*2+1]);
}
char update(ll v, ll tl, ll tr, ll pos, char val){
    if(tl == tr && tl == pos){
        char to_ret = s[tl-1];
        t[v][to_ret-'a']--;
        t[v][val-'a']++;
        s[tl-1] = val;
        return to_ret;
    }
    ll tm = (tl+tr)>>1;
    if(tl <= pos && pos <= tm){
        char to_ret = update(v*2, tl, tm, pos, val);
        t[v][to_ret-'a']--;
        t[v][val-'a']++;
        return to_ret;
    }
    if(tm+1 <= pos && pos <= tr){
        char to_ret = update(v*2+1, tm+1, tr, pos, val);
        t[v][to_ret-'a']--;
        t[v][val-'a']++;
        return to_ret;
    }
}
array<ll, 26> xnull = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
array<ll, 26> get(ll v, ll tl, ll tr, ll l, ll r){
    if(l > tr || r < tl || l > r || tl > tr) return xnull;
    if(tl == l && tr == r) return t[v];
    ll tm = (tl+tr)>>1;
    return t_merge(get(v*2, tl, tm, l, min(r, tm)), get(v*2+1, tm+1, tr, max(l, tm+1), r));
}
ll t_diffc(array<ll, 26> x){
    ll r = 0;
    for(ll i= 0;i<26;i++){
        if(x[i] > 0) r++;
    }
    return r;
}
main(){
    FAST;
    cin >> s;
    ll n = s.length();
    build(1, 1, n);
    ll q, qt;
    cin >> q;
    while(q--){
        cin >> qt;
        if(qt == 1){
            ll pos;
            char c;
            cin >> pos >> c;
            update(1, 1, n, pos, c);
        }else{
            ll l, r;
            cin >> l >> r;
            cout << t_diffc(get(1, 1, n, l, r)) << endl;
        }
    }
}