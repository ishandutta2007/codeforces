#include <bits/stdc++.h>
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
typedef long long ll;
ll binpow(ll a,ll n)
{
    ll res=1;
    while(n)
    {
        if(n%2)res*=a;
        a*=a;
        n/=2;
    }
    return res;
}
template <typename T>
T sqr(T x)
{
    return x*x;
}
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
const ll shl=1;
const ll MAXN=1123456;
vector <pll> v[MAXN];
set <pll> st;
set <string> s;
map < string , ll > mp;
string s2,s1,s3,ss1,ss2,se;
char cc;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> s1 >> s2;
    for(i=0;i<s1.size();++i)
    {
        ss1+=s1[i];
        ss2.clear();
        for(j=0;j<s2.size();j++)
        {
            ss2+=s2[j];
            se=ss1+ss2;
            s.insert(se);
        }
    }

    set <string > :: iterator it=s.begin();
    cout << *it << endl;
    return 0;
}