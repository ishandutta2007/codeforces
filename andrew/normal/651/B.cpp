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
char cc;
multiset <ll> s;
ll dp[MAXN],c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
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
   for(i=0;i<n;i++)
   {
       cin >> a[i];
       s.insert(a[i]);
   }
   set <ll> s1;
   set <ll> :: iterator it;
   while(!s.empty())
   {
       s1.clear();
        for(i=0;i<n;i++)if(s.find(a[i])!=s.end())s1.insert(a[i]);
        ans+=s1.size()-1;
        while(!s1.empty())
        {
            it=s1.begin();
            s.erase(s.find(*it));
            s1.erase(it);
        }
   }
   cout << ans << endl;
        return 0;
}