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
vector <string> v[MAXN];
multiset <ll> s;
char cc;
stringstream ss;
string s1,s2,s3,se;
ll ke,c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k,x1,r=0;
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
ll dp[MAXN][2];
bool fl[MAXN][2];
void check()
{
    multiset <ll> :: iterator it=s.begin();
    while(!s.empty())
    {
        it=s.begin();
        a1=*it;
        if(a1>k)return;
        k-=a1;
        ans-=2;
        s.erase(it);
    }
}
int main() {


    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
   fl[0][0]=1;
   cin >> n >> k;
   for(i=1;i<=n;i++)cin >> a[i];
   x=0;
   for(i=1;i<=n;i++)
   {
        if(a[i]<0 && x)s.insert(i-x-1);
        if(a[i]<0){sc++;x=i;}
   }
   if(sc==0)vout(0);
   if(sc>k)vout(-1);
   k-=sc;
   ans=sc*2;
   check();
   if(n-x<=k)ans--;
   cout << ans << endl;
    return 0;
}