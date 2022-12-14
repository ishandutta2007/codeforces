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

vector <ll> v[MAXN],va;
string s1,s2,s3;
map <ll, ll> mp;
set <ll> s;
char cc;
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for(i = 1; i <= n / 2; i++){
        cin >> x;
        a[x] = i;
    }
    ll uk = 1;
    ans = 1e18;
    while(uk <= 2){
        ll sc = 0;
        for(i = 1; i <= n; i++)b[i] = a[i];
        ll j = 1;
        for(i = uk ; i <= n; i += 2){
            while(1)
            {
                if(b[j]){
                    b[j] = 0;
                    sc += abs(j - i);
                    break;
                }
                j++;
            }
        }
        ans = min(ans, sc);
        ++uk;
    }
    vout(ans);
    return 0;
}