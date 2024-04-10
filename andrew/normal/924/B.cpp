#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
//#define endl "\n"
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

vector <ll> v[MAXN],va;
string s1,s2,s3;
multiset <ll> s;

char cc;
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,x;
map <ll,ll> mp;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll U;
    cin >> n >> U;
    long double ans = 0;
    bool fl = 0;
    for(i = 1; i <= n; i++)cin >> a[i];
    for(i = 1; i < 3; i++)s.insert(a[i]);
    multiset <ll> :: iterator it, it1;
    for(i = 3; i <= n; i++){
        if(s.size())it = s.begin();
        while(s.size() > 0 && a[i] - *it > U){
            if(s.size() > 2){
                it1 = it;
                ++it1;
                fl = 1;
                long double k = a[i - 1], i1 = *it, j1 = *it1;
                ans = max(ans, (k - j1) / (k - i1));
            }
            s.erase(it);
            //if(s.size() == 0)break;
            it = s.begin();
        }
        s.insert(a[i]);
    }
    while(!s.empty()){
            it = s.begin();
            if(s.size() > 2){
                it1 = it;
                ++it1;
                fl = 1;
                long double k = a[i - 1], i1 = *it, j1 = *it1;
                //cout << k << " " << i1 << " " << j1 << endl;
                ans = max(ans, (k - j1) / (k - i1));
            }
            s.erase(it);
            it = s.begin();
        }

    if(!fl)vout("-1");
    cout << fixed << setprecision(9) << ans << endl;
    return 0;
}