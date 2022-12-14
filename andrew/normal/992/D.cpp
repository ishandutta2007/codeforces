#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define next ku
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
ll k, p[MAXN];
ll a[MAXN], next[MAXN];
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin >> n >> k;
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i <= n; i++)next[i] = i;
    for(int i = n - 1; i >= 0; i--)if(a[i] == 1)next[i] = next[i + 1];
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll sc = 0, pr = 1;
        ll l = i;
        while(l < n){
            if(sc != 0 && pr / sc > 1e9)break;
            if(next[l] != l){
                ll sc1 = sc, pr1 = pr;
                sc += next[l] - l;

                    ll le = 1, ri = next[l] - l;
                    while(le < ri){
                        ll c = (le + ri) >> 1;
                        if(pr1 / (sc1 + c) > k || pr1 / (sc1 + c) == k && pr1 % (sc1 + c))le = c + 1; else ri = c;
                    }
                    ll c = le;
                    if(pr1 == (sc1 + c) * k)ans++;

                l = next[l];
            }
            if(l == n)break;
            if(1e18 / pr < a[l])break;
            pr *= a[l];
            sc += a[l];
            if(pr == k * sc)ans++;
            l++;
        }
    }
    vout(ans);
}