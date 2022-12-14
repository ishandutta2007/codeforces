#include <bits/stdc++.h>
#define ll long long
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
const ll shl=1;
vector <ll> tt[1000];
set <ll> ss;
map < string , ll > mp;
string s,s1;
char cc;
ll binpow(ll a,ll n)
{
    ll res=1;
    while(n!=0)
    {
        if(n%2==1)res*=a;
        a*=a;
        n/=2;
    }
    return res;
}
ll mx,c,sc,n,m,i,j,a[10000],b[100000],a1,b1,c1;
int main() {

    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n;
    while(cin>>s)
    {
        m=s.size();
        sc=0;
        for(i=0;i<m;i++)if(s[i]<'a')sc++;
        mx=max(mx,sc);
    }
    cout << mx << endl;
    return 0;
}