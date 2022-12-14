#include <bits/stdc++.h>
#define ll long long
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
vector <ll> tt[1000];
pll a[1000000];
string s,s1;
ll st1[1000000],stn1,st[1000000],c,v,t1,t2,stn,mx,mp[1000000],i,j,n,m,k,sc,dp,x,b[100000],a1,b1,c1,ans;
int main() {

    // set < ll > :: iterator kek=s.begin;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
   cin >> n;
   t1=1e18;
   t2=0;
   stn=1;
   stn1=1;
   st[1]=1e18;
   for(i=0;i<n;i++)
   {
       cin >> x;
       if(x==1)
       {
           cin >> c;
           v=c;
       }
       if(x==2)
       {
            while(st1[stn1]==1)stn1--,sc++;
       }
       if(x==3)
       {
           stn++;
           cin >> c;
           st[stn]=c;
       }
       if(x==4)stn1++,st1[stn1]=0;
       if(x==5)
       {
           stn++;
           st[stn]=1e18;
       }
       if(x==6)
       {
           stn1++;
           st1[stn1]=1;
       }
      while(v>st[stn])stn--,sc++;
   }
   cout << sc << endl;
    return 0;
}