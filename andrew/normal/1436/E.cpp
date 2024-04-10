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
#define fout(x) {cout << x << "\n"; return; }
 
using namespace std;
typedef long long ll;
typedef long double ld;
const ll N = 1e5 + 5;
const ll M = 1e5 + 2;
const int inf = 1e8;
const ll mod = 1e9 + 7;
 
template <typename T> void vout(T s){cout << s << endl;exit(0);}
 
int t[4 * N];
 
void modify(int v, int tl, int tr, int pos, int val){
    if(tl == tr)t[v] = val;
    else{
        int tm = (tl + tr) >> 1;
        if(pos <= tm)modify(v << 1, tl, tm, pos, val);
        else modify(v << 1 | 1, tm + 1, tr, pos, val);
        t[v] = min(t[v << 1 | 1], t[v << 1]);
    }
}
 
int find(int v, int tl, int tr, int k){
    if(tl == tr)return tl;
    int tm = (tl + tr) >> 1;
    if(t[v << 1] < k){
        return find(v << 1, tl, tm, k);
    }
    return find(v << 1 | 1, tm + 1, tr, k);
}
 
int last[2 * N];
 
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
 
    map <int, bool> mp;
 
    int n;
    cin >> n;
 
    vector <int> a(n + 1);
 
    for(int i = 1; i <= n; i++)cin >> a[i];
 
    for(int i = 1; i <= n; i++){
        int x = a[i];
        if(last[x] + 1 < i){
            mp[find(1, 1, M, last[x] + 1)] = 1;
        }
        modify(1, 1, M, a[i], i);
        last[x] = i;
    }
 
    for(int i = 1; i <= M; i++)if(last[i] && last[i] != n){
            mp[find(1, 1, M, last[i] + 1)] = 1;
        }
 
    mp[find(1, 1, M, 1)] = 1;
 
    for(int i = 1; ; i++)if(!mp[i])vout(i);
    return 0;
}