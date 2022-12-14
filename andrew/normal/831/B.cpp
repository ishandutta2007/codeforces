#include <bits/stdc++.h>
#define ll long long
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
const ll shl=1;
vector <ll> tt[1000];
set <ll> ss;
map < string , ll > mp;
string s,s1,s2,ans;
char cc;
ll i1,c,sc,n,m,i,j,a[10000],b[100000],a1,b1,c1,x,k;
int main() {

    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
   cin >> s1 >> s2;
   getline(cin,s);
   getline(cin,s);
   for(i=0;i<s.size();i++)
   {
       cc=s[i];
       x=cc;
       if(cc-48<10)
       {
           ans+=cc;
           continue;
       }
       if(x<97)
       {
           cc=s[i]+32;
           x=s1.find(cc);
           cc=s2[x]-32;
           ans=ans+cc;
           continue;
       }
       x=s1.find(cc);
       ans=ans+s2[x];
   }
   cout << ans << endl;
    return 0;
}