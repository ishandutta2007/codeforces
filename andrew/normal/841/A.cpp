#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define fi first
#define se second
#define p_b push_back
#define m_p make_pair
#define endl "\n"
#define pll pair<ll,ll>
const ll maxn=1000000;
string ans;
map <char,ll> mp;
string s;
vector <ll> tt[1000000];
char cc;
ll mx,xx,stn,a[maxn],b[maxn],c,a1,b1,c1,n,r,m,x,i,j,sc,k,v[maxn];
template <typename T>
T sqr(T a)
{
    return a*a;
}
ll gcd(ll a,ll b)
{
    while(a>0 && b>0)a>b?a%=b:b%=a;
    return a+b;
}
void vout(string s)
{
    cout << s << endl;
    exit(0);
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    cin >> s;
    for(i=0;i<n;i++)
    {
        cc=s[i];
        mp[cc]++;
        mx=max(mx,mp[cc]);
    }
    if(mx>k)vout("No");
    vout("Yes");
    return 0;
}