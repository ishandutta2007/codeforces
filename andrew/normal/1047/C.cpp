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

ll pod[15000001];
const int N = 15000000;
int lp[N+1];
vector<int> pr;

void kek(){

    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin >> n;
    vector <ll> a(n);
    ll k = 0;
    kek();
    for(int i = 0; i < n; i++){
        cin >> a[i];
        k = __gcd(k, a[i]);
    }
    for(int i = 0; i < n; i++){
        ll x = a[i] / k;
        while(x != 1){
            ll prost = lp[x];
            while(x % prost == 0)x /= prost;
            pod[prost]++;
        }
    }
    ll mx = 0;
    for(int i = 1; i <= N; i++)mx = max(mx, pod[i]);
    if(mx == 0)vout(-1);
    cout << n - mx << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}