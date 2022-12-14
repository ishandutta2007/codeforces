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
map < string , ll > mp;
set <ll> kek;
string s2,s1,s3;
char cc;
ll c[MAXN],sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
multiset <ll> s,ss;
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n;
    for(i=0;i<n;i++)cin >> a[i];
    for(i=0;i*i<=1e10;i++)kek.insert(i*i);
    for(i=0;i<n;i++)
    {
        k=sqrt(a[i]);
        while(k*k<a[i])k++;
        while(k*k>a[i])k--;
        b[i]=k;
        if(k*k==a[i])a1++;else b1++;
    }
    for(i=0;i<n;i++)if(b[i]*b[i]==a[i])
    {
        k=a[i];
        c[i]=1e18;
        while(k>0)
        {
            c1=sqrt(k);
            while(c1*c1<k)c1++;
            while(c1*c1>k)c1--;
            if(c1*c1!=k)break;
            k--;
        }
        if(k!=0)c[i]=a[i]-k;
        k=a[i];
        while(1)
        {
            c1=sqrt(k);
            while(c1*c1<k)c1++;
            while(c1*c1>k)c1--;
            if(c1*c1!=k)break;
            k++;
        }
        c[i]=min(c[i],k-a[i]);
        s.insert(c[i]);
    }else
    {
        c[i]=1e18;
        set <ll> :: iterator it;
        it=kek.lower_bound(a[i]);
        c[i]=abs(*it-a[i]);
        if(it!=kek.begin())--it;
        c[i]=min(c[i],abs(*it-a[i]));
        ss.insert(c[i]);
    }
    ll r1=0,r2=0;

    while(a1>n/2)
    {
        multiset <ll> :: iterator it=s.begin();
        r1+=*it;
        s.erase(it);
        a1--;
    }
    while(b1>n/2)
    {
        multiset <ll> :: iterator it=ss.begin();
        r2+=*it;
        ss.erase(it);
        b1--;
    }
    //cout << r1 << " " << r2 << endl;
    cout << max(r1,r2) << endl;
    return 0;
}