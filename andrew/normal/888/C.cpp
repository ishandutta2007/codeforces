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
ll l,r,c,sc,n,m,i,j,a[MAXN],a1,b1,c1,ans,x,k,b[100001][26];
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
    cin >> s;
    n=s.size();
    for(i=1;i<=n;i++)
    {
        for(j=0;j<26;j++)b[i][j]=b[i-1][j];
        ll x=s[i-1]-'a';
        b[i][x]++;
    }
    l=1;
    r=n;
    ans=n;
    while(l<r)
    {
        ll c=(l+r)/2;
        ll fl1=0;
        for(i=0;i<26;i++)
        {
            ll fl=0;
            for(j=1;j<=n-c+1;j++)if(b[j+c-1][i]-b[j-1][i]==0)
            {
                fl=1;
                break;
            }
            //cout << i << " " << fl << endl;
            if(fl==0)fl1=1;
        }
        //cout << l << " " << r << " " << c << " " << fl1 << endl;
        if(fl1==1)
        {
            ans=min(ans,c);
            r=c;
        }else l=c+1;
    }
    cout << ans << endl;
    return 0;
}