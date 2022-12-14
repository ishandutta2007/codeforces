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
const int N = 3e5;
const int M = 1e7;
const ll inf = 1e18;
const int mod = 998244353;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

using namespace std;

vector <int> v[N], all;

bool f[N], us[N], is_cycle[N];

void dfs(int x){
    if(f[x])return;
    f[x] = 1;
    all.p_b(x);
    for(auto to : v[x]){
        dfs(to);
    }
}

void solve(){
    int n;
    cin >> n;
    vector <int> a(n + 1), ans(n + 1);
    for(int i = 1; i <= n; i++){
        us[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(!us[a[i]]){
            us[a[i]] = 1;
            ans[i] = a[i];
        }
    }
    vector <int> va, vb;
    for(int i = 1; i <= n; i++){
        if(!ans[i])va.p_b(i);
        if(!us[i])vb.p_b(i);
    }
    if(sz(va) == 1){
        if(va[0] == vb[0]){
            int x = a[va[0]];
            vb[0] = x;
            for(int i = 0; i < n; i++){
                if(ans[i] == x){
                    ans[i] = va[0];
                    break;
                }
            }
        }
    }
    vector <int> vc;
    for(int i = 0; i < sz(va); i++){
        if(va[i] == vb[i]){
            vc.p_b(i);
        }
    }
    for(int i = 1; i < sz(va); i += 2){
        swap(va[i], va[i - 1]);
    }
    for(int i = 0; i < sz(va); i++){
        if(va[i] == vb[i]){
            if(i == 0){
                swap(va[1], va[0]);
            }else{
                swap(va[i], va[0]);
            }
        }
    }
    for(int i = 0; i < sz(va); i++){
        ans[va[i]] = vb[i];
    }
    int answer = 0;
    for(int i = 1; i <= n; i++)if(a[i] == ans[i]){
        answer++;
    }
    cout << answer << "\n";
    for(int i = 1; i <= n; i++)cout << ans[i] << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;
    //t = 1;

    while(t--){
        solve();
    }

    return 0;
}