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
ll c,sc,n,m,i,j,a[10000],b[100000],a1,b1,c1;
int main() {

    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> a1 >> b1;
    while(1)
    {
        if(a1<1 or b1<1)break;
        if(a1==1 && b1==1)break;
        if(a1>b1)
        {
            a1-=2;
            b1++;
        }else
        {
            a1++;
            b1-=2;
        }
        i++;
    }
    cout << i << endl;
    return 0;
}