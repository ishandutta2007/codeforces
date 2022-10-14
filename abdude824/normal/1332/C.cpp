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
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
    string s;cin>>s;
    //So basically, hamei kuch aisa krna h:
    //let there be string s1, then our s should be like:
    //s1+s1+s1+s1+... whre s1 is a palindrome of length k
    //first condition n%k==0
    //make a string which requires least number of characters
    vector<vector<int>> a;
    //S would be a k letter word
    // hamei S ke har position ko aisa fill krna h jisse least number of 
    // modifications hon
    
    //abaaba
    //a should be 
    //ab
    //aa
    //ba
    string S="";
    fi(k)
    S+="a";
    for(int i=0;i<k/2;i++)
    {
      vi cnt(26);
      for(int j=i;j<n;j+=k)
      {
        cnt[s[j]-'a']++;
      }
      for(int j=k-i-1;j<n;j+=k)
      {
        cnt[s[j]-'a']++;
      }
      int mx=-1;
      int p;
      fj(26){
        if(mx<cnt[j])
        {
          p=j;
        }
        mx=max(cnt[j],mx);
      }
      S[i]='a'+p;
      S[k-i-1]='a'+p;

    }
    if(k%2)
    {
      vi cnt(26);
      for(int j=k/2;j<n;j+=k)
      {
        cnt[s[j]-'a']++;
      }
      int mx=-1;
      int p;
      fj(26){
        if(mx<cnt[j])
        {
          p=j;
        }
        mx=max(cnt[j],mx);
      }
      S[k/2]='a'+p;
    }
    string ans="";
    fi(n/k)
    ans+=S;
    int cnt=0;
    // deb(ans)
    fi(n)
    if(ans[i]!=s[i])cnt++;
    cout<<cnt<<endl;


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