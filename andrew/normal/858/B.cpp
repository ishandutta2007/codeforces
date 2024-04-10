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
const ll maxn=1000000;
vector <ll> tt[1000];
set <ll> s;
map < string , ll > mp;
string s1;
char cc;
pll a[1000000],b[1000000];
ll mj,l,c,sc,n,m,i,j,a1,b1,c1,ans,x,k;
void vout(string s)
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
    cin >> n >> m;
    if(n==1)
    {
        cout << "1" << endl;
        return 0;
    }
    for(i=0;i<m;i++)cin >> a[i].fi >> a[i].se;
    for(i=0;i<m;i++)if(a[i].fi==n)
    {
        cout << a[i].se << endl;
        return 0;
    }
    sort(a,a+m);
    /*for(i=0;i<m-1;i++)if(a[i].fi<=m && m<=a[i+1].fi && a[i].se==a[i+1].se)
    {
        cout << a[i].se << endl;
        return 0;
    }*/
   for(i=1;i<=1000;i++)
   {
       sc=0;
       for(j=0;j<m;j++)
       {
           c1=(a[j].fi/i);
            if(a[j].fi%i!=0)c1++;
            if(c1!=a[j].se)
            {
                sc=1;
                break;
            }
       }
       if(sc==0)
       {
           c1=n/i;
           if(n%i!=0)c1++;
           s.insert(c1);
       }
   }
   if(s.size()!=1)vout("-1");
    set <ll> :: iterator it=s.begin();
    c1=*it;
    cout << c1 << endl;
    return 0;
}