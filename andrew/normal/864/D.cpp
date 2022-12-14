#include <bits/stdc++.h>
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
typedef long long ll;
vector <ll> tt[1000];
map <ll,ll> mp,mp1;
template <typename T>
T next_int() {
    T x = 0, p = 1;
    char ch;
    do { ch = getchar(); } while(ch <= ' ');
    if(ch == '-') {
        p = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return p * x;
}
ll stn,p[1000000],i,j,n,m,k,sc,s,dp[1000000],x,a[1000000],b[1000000],a1,b1,c1,ans;
void fout(string s)
{
    cout << s << endl;
    fflush(stdout);
}
void vout(string s)
{
    cout << s << endl;
    exit(0);
}
template <typename T>
T sqr(T x)
{
    return x*x;
}
ll gcd(ll a,ll b)
{
    while(a>0 && b>0)a>b?a%=b:b%=a;
    return a+b;
}
int main() {

    // set < ll > :: iterator kek=s.begin;
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(i=0;i<n;i++)cin >> a[i];
    for(i=0;i<n;i++)
    {
        x=a[i];
        mp[x]++;
    }
    stn=1;
    for(i=0;i<n;i++)if(mp[a[i]]>1)
    {
        while(mp[stn]>0)stn++;
        if(mp1[a[i]]==0 && stn>a[i])
        {
            mp1[a[i]]=1;
            continue;
        }
        mp[a[i]]--;
        a[i]=stn;
        stn++;
        ans++;
    }
    cout << ans << endl;
    for(i=0;i<n;i++)cout << a[i] << " ";
    cout << endl;
    return 0;
}