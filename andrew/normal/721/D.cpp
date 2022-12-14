#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ll long long
#define ple pair <ll, pll>

using namespace std;
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

vector <pll> v[MAXN];
vector <ll> va;
string s1,s2,s3;
set <pll> st;
set <ll> s;
char cc[MAXN];
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> k >> x;
    for(i = 1; i <= n; i++){
            cin >> a[i];
            if(a[i] < 0)sc++;
            b[i] = a[i];
    }
    if(sc % 2 == 0){
        ll mn = 1e18;
        for(i = 1; i <= n; i++)mn = min(mn, abs(a[i]));
        bool fl = 0;
        for(i = 1; i <= n; i++)if(a[i] == mn){
            while(k && a[i] >= 0){
                a[i] -= x;
                k--;
            }
            fl = 1;
            break;
        }
        for(i = 1; i <= n; i++)if(abs(a[i]) == mn){
            while(fl == 0 && k && a[i] <= 0){
                k--;
                a[i] += x;
            }
            break;
        }
    }
    for(i = 1; i <= n; i++)st.insert(m_p(abs(a[i]), i));
    while(k--){
        set <pll> :: iterator it = st.begin();
        m = it -> se;
        st.erase(it);
        if(a[m] < 0)a[m] -= x; else
        a[m] += x;
        st.insert(m_p(abs(a[m]), m));
    }
    for(i = 1; i < n; i++)cout << a[i] << " ";
    cout << a[i] << "\n";
    return 0;
}