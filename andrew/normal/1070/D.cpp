#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
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
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, k;
    cin >> n >> k;
    vector <ll> a(n + 1);
    for(int i = 1; i <= n; i++)cin >> a[i];
    ll us = 0, where = 0, whow = k;
    for(int i = 1; i <= n; i++){
        if(where){
            if(a[i] <= whow){
                whow = 0;
                where = 0;
            }else{
                a[i] -= whow;
                us += a[i] / k;
                a[i] %= k;
                where = 0;
                if(a[i]){
                    us++;
                    where = i;
                    whow = k - a[i];
                }
            }

        }else{
            us += a[i] / k;
            a[i] %= k;
            where = 0;
            if(a[i]){
                us++;
                where = i;
                whow = k - a[i];
            }
        }
    }
    cout << us << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}