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
set <ll> s;
map < string , ll > mp;
string s2,s1,s3;
char cc;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k1,k;
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);

    cin >> n;
    ll fl=0;
    for(i=0;i<n;i++)
    {
        cin >> cc;
        if(i==n-1)break;
        if(cc=='?')
        {
            cin >> cc;
            ll h=cc-'a';
            a[h]=-1;
            if(fl==1)ans++;
        }else
        if(cc=='.')
        {
            cin >> s1;
            for(j=0;j<s1.size();j++)
            {
                ll h=s1[j]-'a';
                a[h]=-1;
            }
        }else
        if(cc=='!')
        {
            k1++;
            for(j=0;j<26;j++)b[j]=0;
            cin >> s1;
            if(fl==1)ans++;
            for(j=0;j<s1.size();j++)
            {
                ll h=s1[j]-'a';
                if(a[h]==0)a[h]=1;
                if(a[h]==1)b[h]=1;
            }
            for(j=0;j<26;j++)if(b[j]==0)a[j]=-1;
        }
            sc=0;
            for(j=0;j<26;j++)if(a[j]==1)sc++;
            if(sc==1)fl=1;
            sc=0;
            for(j=0;j<26;j++)if(a[j]==0)sc++;
            if(sc==1)fl=1;
    }
    cout << ans << endl;
    return 0;
}