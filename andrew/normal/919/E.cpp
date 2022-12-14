#include <bits/stdc++.h>
#define p_b push_back
//#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
template <typename T>
T sqr(T x)
{
    return x * x;
}
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
ll log(ll a,ll b){
    ll res = 0;
    while(a){
        a /= b;
        res++;
    }
    return res;
}
const ll shl = 1;
const ll MAXN = 1123456;
ll v[MAXN];
vector <ll> va;
set <pll> st;
stringstream ss;
set <ll> s;
map < string , ll > mp;
string s2,s1,s3;
char cc;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k,p,r;
bool pod[MAXN];
ll ku[MAXN];
ll bp(ll a,ll n)
{
    ll res = 1;
    while(n)
    {
        if(n % 2)res *= a;
        res %= p;
        a *= a;
        a %= p;
        n /= 2;
    }
    return res;
}
void dfs(ll x){
    if(v[x])return;
    v[x] = r;
    dfs(b[x]);
    return;
}
void dfs1(ll x){
    if(pod[x])return;
    pod[x] = 1;
    va.p_b(x);
    dfs1(b[x]);
    return;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> a1 >> b1 >> p >> x;
  /* for(i = 1; i <= p; i++){
         c = i;
        for(j = 1; j <= p ; j++){
                cout << (c * bp(a1,c))%p << " ";
                c += p;
        }
        cout << endl;
    }*/
    for(i = 1; i < p; i++){
        c = (i * bp(a1,i)) % p;
        if(!a[c]){
            j = i;
            c1 = c;
            while(!a[c]){
               //     cout << c << " ";
                a[c] = 1;
                j += p;
                c = (j * bp(a1,j)) % p;
                b[c1] = c;
                c1 = c;
            }
          // cout << endl;
        }
    }
    for(i = 1; i < p; i++)if(!v[i]){
        r++;
        dfs(i);
    }
   // for(i = 1; i < p; i++)cout << v[i] << "kek ";cout << endl;
    for(i = 1; i < p; i++)if(v[i] == v[b1]){
            dfs1(i);
            break;
            }
    ll nn = va.size();
  //  cout << endl;
  //  for(i = 0; i < nn; i++)cout << va[i] << " ";
  //  cout << endl << endl;
    ll ke = 0;
    for(i = 0; i < nn; i++)ku[va[i]] = i;
    for(i = 0; i < nn; i++)if(va[i] == b1){
        ke = i;
        break;
    }
    for(i = 1; i < p; i++){
        c = (i * bp(a1,i)) % p;
        if(v[c] != v[b1])continue;
        ll l = ku[c];
        if(l <= ke)sc = ke - l; else sc = nn - l + ke;
        sc *= p;
        ll dpp = x - sc - i + 1;
        if(dpp > 0){
            ans++;
            dpp--;
        }else continue;
        //cout << dp
        ans += dpp / (p * nn);
    }
    cout << ans << endl;
    return 0;
}