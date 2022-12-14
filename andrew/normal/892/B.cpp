#include <bits/stdc++.h>
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
typedef long long ll;
template <typename T>
T sqr(T x)
{
    return x*x;
}
const ll shl=1;
const ll MAXN=1123456;
vector <ll> tt[1000];
set <ll> ss;
map < string , ll > mp;
string s,s1;
char cc;
ll mxj,c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
int main() {

    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n;
    for(i=0;i<n;i++)cin >> a[i];
    ll r=(n-1)-a[n-1];
    for(i=n-2;i>=0;i--)
    {
        if(r<=i)ans++;
        r=min(r,i-a[i]);
    }
    cout << n-ans << endl;
    return 0;
}