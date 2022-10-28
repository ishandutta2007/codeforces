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
vii g(101);
vii ng(101);
  int pl;
vi vis(101);
void dfs(int s,int p)
{
     vi::iterator it=g[s].begin();
    // trace2(p,s);
     ng[p].pb(s);
     int j=0;
     for(;it!=g[s].end();it++)
     {
         // trace3(*it,s,j);
          j++;
          if(*it!=0 && *it!=p && !vis[*it])
          {
               vis[*it]=1;
               dfs(*it,s);

               ng[s].pb(*it);
          }
          else
               if(*it==0)
               {
                    pl=s;
               }
     }
     return ;
}
vector<pair<int,int> > ans;
int main()
{
     IOS;
     #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     #endif
     int n;
     cin>>n;
     int l;
     int r;

     for(int i=0;i<n;i++)
     {
          cin>>l>>r;
          g[l].pb(i+1);
          g[i+1].pb(r);

     }
   
     for(int i=0;i<g[0].size();i++)
     {
       //   trace3(pl,i,g[0][i]);
          if(i==0)
               pl=g[0][i];
          else
               ng[pl].pb(g[0][i]);
          vis[g[0][i]]=1;
          dfs(g[0][i],i?pl:0);
          if(i==g[0].size()-1)
               ng[pl].pb(0);
     }
     ans.resize(n+1);
     for(int i=1;i<=n;i++)
     {
      //    trace2(i,ng[i][0]);
          ans[i].ss=ng[i][0];
          ans[ng[i][0]].ff=i;
     }
     for(int i=1;i<=n;i++)
          cout<<ans[i].ff<<" "<<ans[i].ss<<endl;


return 0;
}