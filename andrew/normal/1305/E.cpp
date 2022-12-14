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
#define fout(x) {cout << x << "\n"; return;}
#define ifn(x) if(!(x))

using namespace std;
typedef long long ll;
typedef long double ld;
const ll N = 2e6;
const ll MAXN = 1123456;
const ll inf = 1e18;
const ll M = 59051;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}


ll cnt[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL


    ll n, m;
    cin >> n >> m;

    if(n < 3){
        if(m > 0)vout(-1);
        for(int i = 1; i <= n; i++)cout << i << " ";
        cout << "\n";
        return 0;
    }

    vector <ll> ans(n + 1);

    ans[1] = 1;
    ans[2] = 2;

    for(int i = 3; i <= n; i++){
        if((i - 1) / 2 < m){
            m -= (i - 1) / 2;
            ans[i] = i;
        }else{
            for(int j = 1; j < i; j++)
                for(int j1 = j + 1; j1 < i; j1++)cnt[ans[j] + ans[j1]]++;
            for(int step = i; step <= 1e5; step++)if(m == cnt[step]){
                ans[i] = step;
                ll temp = 1e9;
                for(int j = n; j > i; j--){
                    ans[j] = temp;
                    temp -= ans[i] + 1;
                }
                for(int i = 1; i <= n; i++)cout << ans[i] << " ";
                cout << "\n";
                return 0;
            }
            cout << "-1\n";
            return 0;
        }
    }

    vout(-1);

    return 0;

}