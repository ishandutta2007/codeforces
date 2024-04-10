//Mobius_Treap
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
const int N = int(1e5)+10;
int ans[26],cnt[26],vis[N];
int main()
{
  int m;si(m);
  string s;cin>>s;
  int n = SZ(s);
  for(auto c : s)
    cnt[c-'a']++;
  for(int i=0;i<26;i++){
    deque<int> pos;
    int last = -1;
    for(int j=0;j<n;j++){
      if(s[j]-'a' == i)pos.push_back(j);
      while(!pos.empty() && pos.front() <= j-m)pos.pop_front();
      if(j < m-1)continue;
      if(last > j-m)vis[j]=1;
      if(vis[j])continue;
      if(pos.empty())continue;
      last = pos.back();
      if(last > j-m){
        vis[j]=1;
        ans[i]++;
      }
    }
  }
  int mx = -1;
  for(int i=0;i<26;i++)
    if(ans[i])
      mx = i;
  for(int i=0;i<mx;i++)
    ans[i] = cnt[i];
  for(int i=0;i<26;i++)
    for(int j=0;j<ans[i];j++)
      printf("%c",'a'+i);
  puts("");
	return 0;
}