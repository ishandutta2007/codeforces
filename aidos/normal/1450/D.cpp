// In the name of GOD

#include <bits/stdc++.h>

using namespace std;

#define nl "\n"
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second
#define sz(x) (int)x.size()
typedef long long ll;

const int N = 3e5 + 5;
const ll M = 1ll * 1e17 + 9;

int n, a[N], b[N];
int t[N * 4];
void build(int v, int l, int r){
    if(l == r){
        t[v] = a[l];
        return;
    }
    int m = l + (r - l) / 2;
    build(v + v, l, m);
    build(v + v + 1, m + 1, r);
    t[v] = min(t[v + v], t[v + v + 1]);
}
int get(int v, int tl, int tr, int l, int r){
    if(tl > r || l > tr) return M;
    if(l <= tl && tr <= r) return t[v];
    int m = (tl + tr) / 2;
    return min(get(v + v, tl, m, l, r), get(v + v + 1, m + 1, tr, l, r));
}
bool check(int x){
    vector<int> u(n+1, 0);
    for(int i = 1; i + x - 1 <= n; ++i){
        int r = i + x - 1;
        u[get(1, 1, n, i, r)] = 1;
    }
    for(int i = 1; i <= n-x+1; i++)
        if(!u[i]) return false;
    return true;
}
void solve(){
    cin >> n;
    int bad = 1;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        b[i] = a[i];
    }
    build(1, 1, n);
    int l = 2, r = n;
    int ok = n + 1;
    while(l <= r){
        int m = (l + r) / 2;
        if(check(m)){
            ok = m;
            r = m - 1;
        } else{
            l = m + 1;
        }
    }
    sort(b + 1, b + n + 1);
    for(int i = 1; i <= n; ++i){
        if(b[i] != i){
            bad = 0;
            break;
        }
    }
    cout << bad;
    for(int i = 2; i < ok; ++i){
        cout << 0;
    }
    for(int i = ok; i <= n; ++i){
        cout << 1;
    }

    cout << nl;
}
int main(){

    #ifdef NotIdeal
     //freopen("inA.txt", "r", stdin);
    // freopen("", "w", stdout);
    #endif // NotIdeal
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int q = 1;
    cin >> q;
    while(q--){
        solve();
    }
    return 0;
}