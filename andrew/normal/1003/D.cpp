#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
T sqr(T x){
    return x * x;
}

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n, m, x;
    cin >> n >> m;
    vector <ll> a(50);
    vector <ll> b(50);
    for(int i = 0; i < n; i++){
        cin >> x;
        ll kol = 0;
        while(x != 1){
            kol++;
            x >>= 1;
        }
        a[kol]++;
    }
    while(m--){
        ll x, ans = 0;
        cin >> x;
        for(int i = 0; i < 50; i++)b[i] = a[i];
        for(int i = 0; i <= 40; i++)if((1ll << i) & x){
            ll mb = 1;
            for(int j = i; j >= 0; j--){
                //cout << (1ll << j) << " " << mb << " " << b[j] << endl;
                if(b[j] >= mb){
                    ans += mb;
                    b[j] -= mb;
                    mb = 0;
                    break;
                }
                ans += b[j];
                mb = (mb - b[j]) << 1;
                b[j] = 0;
            }
            if(mb){
                ans = -1;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
/*
5 1
1 1 1 1 2
4
*/