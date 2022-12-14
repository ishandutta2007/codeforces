#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
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
vector <int> a;
ll b[MAXN];
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n, k;
    cin >> n >> k;
    a.resize(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    int l = 1, r = n;

    while(l < r){
        int c = (l + r) >> 1;
        if(c == l)c++;
        for(int i = 0; i < n; i++)b[a[i]] = 0;
        bool ok = 0;
        int kol = 0;
        for(int i = 0; i < c; i++){
            if(!b[a[i]])kol++;
            b[a[i]]++;
        }
        if(kol <= k)ok = 1;
        for(int i = 0; i < n - c; i++){
            if(b[a[i]] == 1)kol--;
            b[a[i]]--;
            if(!b[a[i + c]])kol++;
            b[a[i + c]]++;
            if(kol <= k)ok = 1;
        }
        if(!ok)r = c - 1; else l = c;
    }

    int kol = 0;
    for(int i = 0; i < n; i++)b[a[i]] = 0;
    for(int i = 0; i < l; i++){
        if(!b[a[i]])kol++;
        b[a[i]]++;
    }
    if(kol <= k)return cout << 1 << " " << l << endl, 0;
    for(int i = 0; i < n - l; i++){
        if(b[a[i]] == 1)kol--;
        b[a[i]]--;
        if(!b[a[i + l]])kol++;
        b[a[i + l]]++;
        if(kol <= k)return cout << i + 2 << " " << i + 2 + l - 1 << endl, 0;
    }
}