#include <bits/stdc++.h>
  #include<string.h>
  using namespace std;
  #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #define endl "\n"
  #define Max(x,y,z) max(x,max(y,z))
  #define Min(x,y,z) min(x,min(y,z))
  #define fr(i,s,e) for(i=s;i<e;i++)
  #define rf(i,s,e) for(i=s-1;i>=e;i--)
  #define pb push_back
  #define eb emblace_back
  #define mp make_pair
  #define ff first
  #define ss second
  #define ll long long
  #define trace1(x)                cerr<<#x<<": "<<x<<endl
  #define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
  #define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
  #define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
  #define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
  #define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
  #define vl vector<long long>
   
  #define vi vector<int> 
  #define vii vector< vector<int> >
  #define vll vector< vector<long long> >
  #define vpi vector< pair<int,int> >   
  #define vpl vector< pair<ll,ll> >   
  typedef pair<pair<int, ll>,int> P;
   #define mod %1000000007
   //#define p 41
  bool less_vectors(const vector<int>& a,const vector<int>& b) 
  {
     return a.size() > b.size();
  }
   
  ll gcd(ll a,ll b)
{
if(a%b==0)
     return b;
     else
          return gcd(b,a%b);
}
class compr
{
     public:
bool operator()(pair<pair<int,ll>,int>  p1,pair<pair<int,ll>,int> p2)
  {
     if(p1.ff.ss!=p2.ff.ss)
          return p1.ff.ss>p2.ff.ss;
          else
               if(p1.ss!=p2.ss)
               return p1.ss>p2.ss;
               else
                    return p1.ff<p2.ff;
               
  }

};
ll fastexpo(ll a,ll b)
{
     //trace2(a,b);
     ll res=1;
     while(b>0)
     {
          if(b%2==1)
               res=(((res)mod)*((a)mod))mod;
          a=(((a)mod)*((a)mod))mod;
          b/=2;
     }
     //trace1(res);
     return res;
}
ll fastexpom(ll a,ll b,ll m)
{
ll res=1;
     while(b>0)
     {
          if(b%2==1)
               res=(((res)%m)*((a)%m))%m;
          a=(((a)%m)*((a)%m))%m;
          b/=2;
     }
     return res;
}
ll modinv(ll a,ll m=1000000007)
{
return fastexpom(a,m-2,m);
}

int main()
{
     IOS;
     #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     #endif
     int n;
     cin>>n;

     vector<vector<int> > lis(n);
     int ct=0;
     vi v(n);
     for(int i=0;i<n;i++)
     {
          cin>>v[i];
     }
     lis[0].pb(v[0]);
     for(int i=1;i<n;i++)
     {
          int lo=0;
          int hi=ct;
         // trace1(i);
          while(lo<hi)
          {
               int mid=(lo+hi)>>1;
            //   trace2(mid,lis[mid].back());
               if(v[i]>(lis[mid].back()))
               {
                    hi=mid;
               }
               else
                    lo=mid+1;
          }

          if(v[i]>lis[lo].back())
               lis[lo].pb(v[i]);
          else
          {
               ct++;
               lis[ct].pb(v[i]);
          }
      //    trace4(lo,lis[lo].back(),ct,lis[0].size());
     }
    // trace1(lis[0].back());
     for(int i=0;i<=ct;i++)
     {
          for(int j=0;j<lis[i].size();j++)
               {
                   // trace3(i,)
                    cout<<lis[i][j]<<" ";
               }
          cout<<endl;
     }



return 0;
}