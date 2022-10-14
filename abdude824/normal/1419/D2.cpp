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
 
int32_t main()
{
  aeh();
  // int t;cin>>t;
  // while(t--)
  // {
    int n;cin>>n;
    vector<int> a(n);
    fi(n){

      cin>>a[i];
    }
    sortall(a);
    int p=n-1;
    int cnt=0;
    vi ans;
    int ll2=(n-1)/2;
    reverse(a.begin(),a.begin()+ll2);
    // fi(n)cout<<a[i]<<" ";
    for(int i=0;i<n/2;i++)
    {
      if(p>(i))
        ans.pb(a[p]);
      ans.pb(a[i]);
      // if(a[p]>a[i]&&p!=i+1)cnt++;
      p--;
    }
    if(n%2)ans.pb(a[n/2]);
    fi(n-1)
    {
      if(i!=0)
      {
        if(ans[i]<ans[i+1]&&ans[i]<ans[i-1])
        {
          cnt++;
        }

      }
    }
    // fi(n)
    // {

    //   if(a[p]>a[i])
    //   {
    //     ans.pb(a[p]);
    //     ans.pb(a[i]);
    //     a[p]=-1;
    //     cnt++;
    //     p--;
    //   }
    //   else{
    //     for(int j=i;j<n&&a[j]!=-1;j++)
    //       ans.pb(a[j]);
    //     break;
    //   }
    // }   
    cout<<cnt<<endl;
    fi(ans.size())
    cout<<ans[i]<<" ";
  // }
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