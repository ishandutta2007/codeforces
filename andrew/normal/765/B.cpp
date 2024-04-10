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
    string s1;
    string s2;
    cin >> s1;
    ll fl=0;
    ll mx=0;
    for(i=0;i<s1.size();i++){if(!b[s1[i]-'a'])b[s1[i]-'a']=i+1;mx=max(mx,ll(s1[i]-'a'));}
    for(i=0;i<mx+1;i++)
    {
        if(!b[i])vout("NO");
        if(i!=0 && b[i]<b[i-1])vout("NO");
    }
    vout("YES");
        return 0;
}