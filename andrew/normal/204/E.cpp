#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
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
 
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 4e5;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template <typename T> void vout(T s){cout << s << endl;exit(0);}
 
string s;
int p[N + 5][19];
vector <pll> b;
ll cnt[MAXN], pos[MAXN], stn;
pll d[MAXN];
vector <ll> v[MAXN];
 
void build_suffix_array(){
    ll n = s.size();
    b.resize(n + 2);
    pll last = {0, 0};
    for(auto i : s)if(i != '#')cnt[i - 'a'] = 1;
    for(int i = 1; i < 26; i++)cnt[i] += cnt[i - 1];
    for(int i = 0; i < n; i++){
            if(s[i] == '#')p[i][0] = cnt[25];
            else p[i][0] = cnt[s[i] - 'a'] - 1;
    }
 
    for(int step = 1; step <= 18; step++){
        for(int i = 0; i < n; i++)cnt[i] = 0;
        for(int i = n - 1; i >= 0; i--){
            ll j = i + pw(step - 1);
            j %= n;
            b[i] = {p[i][step - 1], p[j][step - 1]};
            cnt[p[i][step - 1]]++;
            v[p[j][step - 1]].p_b(i);
        }
 
        for(int i = 1; i < n; i++){
            cnt[i] += cnt[i - 1];
        }
 
        for(int i = n - 1; i >= 0; i--){
            for(auto j : v[i]){
                pos[--cnt[p[j][step - 1]]] = j;
            }
            v[i].clear();
        }
 
        stn = 0;
 
        for(int i = 0; i < n; i++){
            if(!stn || last != b[pos[i]]){
                stn++;
                p[pos[i]][step] = stn - 1;
                last = b[pos[i]];
            }else p[pos[i]][step] = stn - 1;
        }
 
    }
}
 
struct node{
    int t;
    node *l, *r;
    node(): t(0), l(r=nullptr){}
};
 
struct root{
    node *v;
};
 
root clr, Clr;
 
vector <root> V;
 
void build(node *v, int tl, int tr){
    if(tl != tr){
        v -> l = new node();
        v -> r = new node();
        int tm = (tl + tr) >> 1;
        build(v -> l, tl, tm);
        build(v -> r, tm + 1, tr);
    }
}
 
int Pos, val;
 
void modify(node *_new, node *old, int tl, int tr){
    if(tl == tr)_new -> t = val;
    else{
        int tm = (tl + tr) >> 1;
        _new -> l = old -> l;
        _new -> r = old -> r;
        _new -> t = old -> t;
        if(Pos <= tm){
            _new -> l = new node();
            modify(_new -> l, old -> l, tl, tm);
        }else{
            _new -> r = new node();
            modify(_new -> r, old -> r, tm + 1, tr);
        }
        _new -> t = (_new -> l) -> t + (_new -> r) -> t;
    }
}
 
int get(node *v, int tl, int tr, int l, int r){
    if(l > r)return 0;
    if(tl == l && tr == r)return v -> t;
    int tm = (tl + tr) >> 1;
    return get(v -> l, tl, tm, l, min(r, tm)) + get(v -> r, tm + 1, tr, max(l, tm + 1), r);
}
 
int Last[N + 5];
pii What[N + 5];
 
vector <int> Where[100001];
int Lcp[MAXN];
int Sp[N + 5][19], st[N + 5];
 
int get(int l, int r){
    return min(Sp[l][st[r - l + 1]], Sp[r - pw(st[r - l + 1]) + 1][st[r - l + 1]]);
}
 
bool FT[27];
int KoL[27];
 
int POZ[MAXN];
 
bool cmp(int a, int b){
    return (p[a][18] < p[b][18]);
}
 
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
 
    ll n, k;
    cin >> n >> k;
    vector <string> a(n);
    ll uk = 0;
 
    for(int i = 1; i <= N + 2; i++){
        while(pw(uk + 1) < i)uk++;
        st[i] = uk;
    }
 
    for(int i = 0; i < n; i++)cin >> a[i];
 
    for(int i = 0; i < n; i++){
        Where[i].resize(a[i].size());
        for(int j = 0; j < 26; j++)FT[j] = 0;
        for(int j = 0; j < a[i].size(); j++){
            s += a[i][j];
            FT[a[i][j] - 'a'] = 1;
            What[s.size()] = {i, j};
            Where[i][j] = s.size();
        }
        s += "#";
        for(int j = 0; j < 26; j++)KoL[j] += FT[j];
    }
 
 
    build_suffix_array();
 
    ll M = s.size();
 
    for(int i = 0; i < M; i++)POZ[i] = i;
    sort(POZ, POZ + M, cmp);
    for(int i = 0; i < M; i++){
        int j = POZ[i];
        if(s[j] == '#')continue;
        Where[What[j + 1].fi][What[j + 1].se] = i + 1;
    }
 
    for(int i = 0; i < M - 1; i++){
        int res = 0;
        for(int j = 18; j >= 0; j--)if(max(POZ[i + 1], POZ[i]) + pw(j) + res < M && p[POZ[i] + res][j] == p[POZ[i + 1] + res][j]){
            res |= pw(j);
        }
        Lcp[i] = res;
        Sp[i + 1][0] = Lcp[i];
    }
 
    for(int j = 1; j <= 18; j++)
    for(int i = 1; i <= M; i++){
        if(i + pw(j) - 1 > M)break;
        Sp[i][j] = min(Sp[i][j - 1], Sp[i + pw(j - 1)][j - 1]);
    }
 
    clr.v = new node();
 
    build(clr.v, 1, M);
    V.p_b(clr);
 
    for(int step = 1; step <= M; step++){
        int i = POZ[step - 1];
        if(s[i] == '#'){
            V.p_b(V.back());
            continue;
        }
        int j = What[i + 1].fi;
        if(!Last[j]){
            clr.v = new node();
            Pos = step;
            val = 1;
            modify(clr.v, V.back().v, 1, M);
            Last[j] = step;
            V.p_b(clr);
        }else{
            clr.v = new node();
            Pos = Last[j];
            val = 0;
            modify(clr.v, V.back().v, 1, M);
 
            Clr.v = new node();
            Last[j] = step;
            Pos = Last[j];
            val = 1;
            modify(Clr.v, clr.v, 1, M);
            V.p_b(Clr);
        }
    }
 
    ll ans = 0;
 
    int nw = 0, le, ri, l, r;
 
    for(int i = 0; i < n; i++){
        ans = 0;
        int R = 0;
        for(int L = 0; L < a[i].size(); L++){
            if(R < L)R++;
            while(R < a[i].size() - 1){
                nw = R + 1;
                le = Where[i][L], ri = Where[i][L];
                l = ri, r = M;
                while(l < r){
                    int c = (l + r + 1) >> 1;
                    if(get(ri, c - 1) >= nw - L + 1)l = c; else r = c - 1;
                }
                ri = l;
                l = 1, r = le;
                while(l < r){
                    int c = (l + r) >> 1;
                    if(get(c, le - 1) < nw - L + 1)l = c + 1; else r = c;
                }
                le = l;
                if(get(V[ri].v, 1, M, le, ri) >= k)R = nw;
                else break;
            }
            if(L == R){
                if(KoL[a[i][L] - 'a'] >= k)ans++;
            }else ans += R - L + 1;
        }
        cout << ans << " ";
    }
    cout << "\n";
 
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}