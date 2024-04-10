#include <bits/stdc++.h>
#define p_b push_back
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
set <ll> s;
map < string , ll > mp;
string s2,s1,s3;
char cc;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ll p;
    cin >> n >> m >> c;
    for(i=1;i<=n;i++)b[i]=min(i,c);
    while(m--)
    {
        cin >> x;
        ll k=0;
        if(x<=c/2)
        {
             for(i=1;i<=n;i++)if(a[i]==0 or a[i]>x){k=i;break;}
             if(k==0)k=1;
        }else
        {
            for(i=n;i>0;i--)if(a[i]==0 or a[i]<x){k=i;break;}
            if(k==0)k=n;
        }
        a[k]=x;
        cout << k << endl;
        ll fl1=0;
        for(i=1;i<=n;i++)if(a[i]==0 or a[i]<a[i-1])fl1=1;
        if(fl1==0)break;
    }
    return 0;
}