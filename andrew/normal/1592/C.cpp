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
const int MAXN = 1123456;
const int M = pw(16);
const long long mod = 1e9 + 7;
const int N = 2e5;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

int a[N], s[N], cnt[N];
vector <int> v[N];
string ans = "NO";

void dfs(int x, int p = 0){
    s[x] = a[x];
    for(auto to : v[x])if(to != p){
        dfs(to, x);
        s[x] ^= s[to];
    }
}

void go(int x, int p = 0, bool f = 0){
    int c = 0;
    cnt[x] = 0;
    if(f && s[x] == s[1]){
        ans = "YES";
    }
    f |= (s[x] == 0);
    for(auto to : v[x])if(to != p){
        go(to, x, f);
        if(cnt[to]){
            c++;
        }
    }
    if(c == 2){
        ans = "YES";
    }
    c = min(c, 1);
    cnt[x] = c;
    if(s[x] == s[1]){
        cnt[x] = 1;
    }
}

void solve(){
    int n, k;
    cin >> n >> k;
    ans = "NO"; 

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    dfs(1);
    if(k > 2){
        go(1);
    }

    if(s[1] == 0){
        ans = "YES";
    }

    cout << ans << "\n";
    for(int i = 1; i <= n; i++){
        v[i].clear();
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}