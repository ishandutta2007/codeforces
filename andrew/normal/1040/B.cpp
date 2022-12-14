#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double

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

    ll n, k;
    cin >> n >> k;
    if(n == 1){
        cout << "1\n1\n";
        return 0;
    }
    if(k == 0){
        cout << n << "\n";
        for(int i = 1; i <= n; i++)cout << i << " ";
        return 0;
    }
    if(k * 2 + 1 >= n){
        cout << "1\n";
        cout << (n + 1) / 2 << endl;
        return 0;
    }
    ll mn = 1e18;
    ll dop = k * 2 + 1;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(i - 1 > k)continue;
            if(n - j > k)continue;
            if(j - i - 1 < 2 * k)continue;
            ll len = j - i - 2 * k - 1;
            if(len % (dop) == 0)mn = min(mn, len / dop + 2);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(i - 1 > k)continue;
            if(n - j > k)continue;
            if(j - i - 1 < 2 * k)continue;
            ll len = j - i - 2 * k - 1;
            if(len % (dop) == 0)if(len / dop + 2 == mn){
                vector <ll> ans;
                ans.p_b(i);
                ans.p_b(j);
                ll pos = i + 2 * k + 1;
                while(pos != j){
                    ans.p_b(pos);
                    pos += 2 * k + 1;
                }
                sort(all(ans));
                cout << ans.size() << endl;
                for(auto i : ans)cout << i << " ";
                return 0;
            }
        }
    }
    return 0;
}
/*
4 2 2
1 2 2 1
*/