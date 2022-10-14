// 
// 
// 
// 
// 
// 


#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long int
#define ll long long int
#define fi(n) for(int i=0;i<n;i++)
#define fj(n) for(int j=0;j<n;j++)
#define W(x) int x;cin>>x;while(x--)
#define fr(n) for(int i=n-1;i>=0;i--)
#define mp make_pair
#define fo(i,a,n) for(int i=a;i<n;i++)
#define ps(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define vi vector<int>
#define deb(x) cout<<#x<<"="<<x<<endl;
#define all(a) (a).begin(),(a).end()
#define pii pair<int,int>
#define sortall(x) sort(all(x))
#define mk(arr,n,type)  type *arr=new type[n];
#define vpi vector<pair<int,int> >
#define setbits(x) __builtin_popcountll(x)
#define zerbits(x) __builtinctzll(x)
#define mod 1000000007
#define inf 1e18
#define sz(x) (int)x.size()
#define vs vector<string>
#define itr(a) for(auto it=a.begin();it!=a.end();it++)
#define f first
#define s second
#define INT_SIZE 32
int mpow(int exp, int base);
//I don't know what the funciton aeh() does but it speeds up my mess
void aeh()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
int diff(string p,string q)
{
  int cnt=0;
  for(int i=0;i<p.size();i++)
  {
    if(p[i]!=q[i])
      cnt++;
  }
  return cnt;
}
int32_t main()
{
  aeh();
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
    string s;cin>>s;
    string p="";
    for(int i=0;i<n/3;i++)
    {
      p+="RGB";
    }  
    string key="RGB"; 
    p+=key.substr(0,n%3);
    vector<string>a;
    a.pb(p);
    // deb(p)
    p+=key.substr(n%3,1);
    p.erase(0,1);
    a.pb(p);
    // deb(p)
    if(p[p.size()-1]=='R')
      p+="G";
    else if(p[p.size()-1]=='B')
      p+="R";
    else if(p[p.size()-1]=='G')
      p+="B";
    p.erase(0,1);
    a.pb(p);
    int cnt=0;
    for(int i=0;i<3;i++)
    {
      vi diff(n+1);
      for(int j=0;j<n;j++)
      {
        diff[j+1]=(s[j]==a[i][j])?1:0;
      }
      for(int j=1;j<=n;j++)
      {
        diff[j]+=diff[j-1];
      }
      // fj(n+1)
      // cout<<diff[j]<<" ";
      // cout<<endl;
      for(int j=k;j<n+1;j++)
      {
        cnt=max(cnt,diff[j]-diff[j-k]);
        // deb(cnt)
      }
    }
    cout<<k-cnt<<"\n";
  }
}

int mpow(int base, int exp)
{
  base %= mod;
  int result = 1;
  while (exp > 0)
  {
    if (exp & 1)result = (result * base) % mod;
    base = (base * base) % mod;
    exp >>= 1;
  }
  return result;
}