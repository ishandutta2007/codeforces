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
const ll N = 1e6 + 100;
const int inf = 1e8;
const ll mod = 998244353;

const int M = 1e6;
const int T = 262144;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

int last[N + 10];

void pre_calc(){
    last[1] = 1;
    for(int i = 2; i <= N; i++)if(!last[i]){
        for(int j = i; j <= N; j += i)last[j] = i;
    }
}

void solve(){
    int n;
    cin >> n;
    map <int, int> mp;

    for(int i = 1; i <= n; i++){
        int x, mul = 1;
        cin >> x;
        while(x != 1){
            int c = 0, p = last[x];
            while(x % p == 0){
                x /= p;
                c++;
            }
            if(c % 2) mul *= p;
        }
        mp[mul]++;
    }
    int ans_0, ans_1, to_0;
    ans_0 = ans_1 = to_0 = 0;
    for(auto i : mp){
        ans_0 = max(ans_0, i.se);
        if(i.fi != 1 && i.se % 2 == 0)to_0 += i.se;
    }
    mp[1] += to_0;
    for(auto i : mp){
        ans_1 = max(ans_1, i.se);
    }
    int q;
    cin >> q;
    while(q--){
        long long w;
        cin >> w;
        if(!w)cout << ans_0 << "\n";
        else cout << ans_1 << "\n";
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    pre_calc();

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}