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
set <ll> s[200000];
map < string , ll > mp;
string s2,s3;
set <ll> s1;
char cc;
ll v[MAXN],c[MAXN],sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n;
    for(i=0;i<=n;i++)
    {
        cin >> a[i];
        c1+=a[i];
    }
    ll l=0;

    for(i=0;i<=n;i++)
    {

        v[i]=l+1;
        for(j=0;j<a[i];j++)
        {
            l++;
            if(i==0)b[l]=0;else b[l]=v[i-1];
            //++it;
            //if(it==s[i].end())--it;
        }
    }
    l=1;
    ll fl=0;
    for(i=1;i<=c1;i++)c[i]=b[i];
    for(i=1;i<=n;i++)
    {
       for(j=0;j<a[i];j++)
       {
           l++;
           if(a[i-1]>1 && a[i]>1)
           {
               //cout  << a[i-1] << " " << v[i-1] << endl;
               c[l]=v[i-1]+1;
               fl=1;
               goto l1;
           }
       }

    }
    l1:
    if(fl==0)vout("perfect");
    cout << "ambiguous" << endl;
    for(i=1;i<=c1;i++)cout << b[i] << " ";cout << endl;
    for(i=1;i<=c1;i++)cout << c[i] << " ";cout << endl;
    return 0;
}