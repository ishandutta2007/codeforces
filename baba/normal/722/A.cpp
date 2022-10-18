//_/\_MajorKaks_/\_
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

bool check12(int i,int j,int k,int l)
{
  if(k>=6)
    return false;
  if(i==0 && j==0)
    return false;
  if(i==1 && j>=3)
    return false;
  if(i>=2)
    return false;
  return true;
}
bool check24(int i,int j,int k,int l){
  if(k>=6)
    return false;
  if(i==2 && j>=4)
    return false;
  if(i>=3)
    return false;
  return true;
}
int main()
{
  int f;
  cin>>f;
  string s;
  cin>>s;
  string ans = s;
  int mindiff = 123456;
  for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
      for(int k=0;k<10;k++)
        for(int l=0;l<10;l++){
          if(f==12){
            if(check12(i,j,k,l))
            {
              int diff = (s[0]==i+'0'?0:1) + (s[1]==j+'0'?0:1) + (s[3]==k+'0'?0:1) + (s[4]==l+'0'?0:1);   
              if(diff<mindiff)
                mindiff = diff, ans[0] = i+'0',ans[1]=j+'0',ans[3] = k+'0',ans[4] = l+'0';
            }
          }
          else{
            if(check24(i,j,k,l))
            {
              int diff = (s[0]==i+'0'?0:1) + (s[1]==j+'0'?0:1) + (s[3]==k+'0'?0:1) + (s[4]==l+'0'?0:1);   
              if(diff<mindiff)
                mindiff = diff, ans[0] = i+'0',ans[1]=j+'0',ans[3] = k+'0',ans[4] = l+'0';
            }
          }
        }
  cout << ans << endl;
  return 0;
}