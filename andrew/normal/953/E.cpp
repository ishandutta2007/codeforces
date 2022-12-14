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
set <ll> pz;
set <pll> st;
set <pll> se;
set <ll> s;
char cc;
ll a[MAXN],b[MAXN],c[MAXN],a1,b1,c1,i,j,n,m,k,ans,sc,x;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for(i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(i = 1; i <= n; i++){
        pz.insert(i);
        ll x = 0;
        if(i < n && a[i] == a[i + 1])x = -1;
        st.insert(m_p(x, i));
        c[i] = x;
    }
    set <pll> :: iterator itt,itt1;
    set <ll> :: iterator it,it1;
    while(1){
        itt = st.begin();
        pll xe = *itt;
        if(xe.fi == 0)break;
        st.erase(itt);
        ll xx = *(pz.upper_bound(xe.se));
        st.erase(m_p(c[xx],xx));
        st.insert(m_p(0ll,xx));
        //cout << xe.se << " " << xx << endl;
        c[xx] = 0;
        b[xe.se] = 1;
        pz.erase(xe.se);
        a[xx]++;
        ll le = 0, ri = 0;
        it = pz.upper_bound(xx);
        if(it != pz.end())ri = *it;
        if(a[ri] == a[xx]){
            st.erase(m_p(c[xx],xx));
            c[xx] = -1;
            st.insert(m_p(c[xx],xx));
        }
        it = pz.find(xx);
        if(it != pz.begin()){
            --it;
            le = *it;
        }
        //cout << a[le] << " " << a[xx] << endl;
        if(a[le] == a[xx]){
            st.erase(m_p(c[le],le));
            c[le] = -1;
            st.insert(m_p(c[le],le));
        }
    }
    for(i = 1; i <= n; i++)if(!b[i])va.p_b(a[i]);
    ll nn = va.size();
    cout << nn << endl;
    for(i = 0; i < nn; i++)cout << va[i] << " ";
    cout << endl;
    return 0;
}