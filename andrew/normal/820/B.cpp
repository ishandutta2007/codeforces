#include <bits/stdc++.h>
#define ll long long
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
using namespace std;
vector <ll> tt[1000];
set <ll> ss;
map < string , ll > mp;
string s,s1;
char c,cc;
double kk,dd,pp,mx,m;
ll n,i,j,l1,l2,l3,a[1000000],b,v[1000000],a1,sc,l,sk,b1,c1;
int main() {
    ll v1,v0;
    // set < ll > :: iterator kek=s.begin;
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
   cin >> n >> dd;
   if(n==3)
   {
       cout << 1 << " " << 2 << " " << 3 << endl;
       return 0;
   }
   m=180*(n-2);
   m/=n;
   cout << n << " " << 1 << " ";
   kk=m;
   kk=kk/(n-2);
   ll mxj;
 //  dd=b;
   pp=m;
   mx=1e9;
   for(i=2;i<n;i++)//if(i!=1 and i!=n)
   {
      if(abs(dd-pp)<mx){mx=abs(dd-pp);mxj=i;}
//      cout << setprecision(10) << pp << endl;
      pp=pp-kk;
      //pp-=pp;
   }
   cout << mxj << endl;
    return 0;
}