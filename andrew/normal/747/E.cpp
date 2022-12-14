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
char cc;
stringstream ss;
string s1,s2,s3,se;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k,x1,r=0;
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
ll stn,mst;
void dfs(string s2,ll x)
{
    stn++;
    mst=max(mst,stn);
    v[stn].p_b(s2);
    ll i;
    for(i=0;i<x;i++)
 {
   se.clear();
   while(s1[r]!=',')se+=s1[r],r++;
   ss.clear();
   s3.clear();
   r++;
   x1=0;
   while(s1[r]!=',')s3+=s1[r],r++;
   ss<<s3;
   ss>>x1;
           r++;
   dfs(se,x1);
}
    stn--;
    return;

}
int main() {


    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
   cin >> s1;
   s1+=',';
   n=s1.size();
   while(r<n)
   {
   s2.clear();
   while(s1[r]!=',')s2+=s1[r],r++;
   ss.clear();
   s3.clear();
   r++;
   while(s1[r]!=',')s3+=s1[r],r++;
   ss<<s3;
   ss>>x;
       r++;
   dfs(s2,x);
   }
   cout << mst << endl;
   for(i=1;i<=mst;i++)
   {
ll       nn=v[i].size();
       for(j=0;j<nn;j++)cout << v[i][j] << " ";
       cout << endl;
   }
    return 0;
}