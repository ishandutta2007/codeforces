//Tanuj Khattar
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
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

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


int main(){
  int n,k,m,a,i,j, cnt[102], latest[102], ans[102], rem;
  vector < pair<II, int> > ar(102);
  scanf("%d %d %d %d", &n, &k, &m, &a);
  for(i=0;i< n;i++){
    cnt[i] = 0;
    latest[i] = -1;
  }
  for(i = 0; i< a;i++){
    scanf("%d", &j);
    j--;
    cnt[j]++;
    latest[j] = -i;
  }
  for(i = 0;i < n;i++){
    ar[i].S = i;
    ar[i].F.F = cnt[i];
    ar[i].F.S = latest[i];
  }
  //sort and rev
  sort(ar.begin(), ar.begin()+n);
  reverse(ar.begin(), ar.begin()+n);
  //

  for(i = 0;i < n;i++){
    //    trace(ar[i].F.F, ar[i].F.S, ar[i].S);
    ans[i] = 2;
  }
  rem = m -a;

  if(rem == 0){
    for(i = 0;i < n;i++){
      if(i < k && ar[i].F.F > 0){
	ans[ar[i].S] = 1;
      }
      else{
	ans[ar[i].S] = 3;
      }
    }
    for(i = 0;i < n;i++){
      printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
    
  }
  
  for(i = 0;i < n;i++){
    if(i < k){
      //      trace("i<k", ar[i].F.F, ar[i].F.S, ar[i].S);
      int trem = rem;
      if(ar[i].F.F == 0){
	if(n == 1){
	  ans[ar[i].S] = 1;
	}
	else{
	  continue;
	}
      }
      j = i+1;
      while(j < n && j <= k){
	pair<II, int> tmp;
	tmp = ar[j];
	tmp.F.S = -m;
	while(trem > 0 && tmp < ar[i]){
	  tmp.F.F++;
	  trem--;
	}
	if(tmp < ar[i])
	  break;
	j++;
      }
      if(j <= k){
	ans[ar[i].S] = 1;
      }
      
    }
    else{
      //      trace("i>=k", ar[i].F.F, ar[i].F.S, ar[i].S);
      pair<II, int> tmp;
      tmp = ar[i];
      tmp.F.F += rem;
      tmp.F.S = -m;
      //      trace("tmp", tmp.F.F, tmp.F.S, tmp.S);
      //      trace("ar[i]", ar[i].F.F, ar[i].F.S, ar[i].S);
      if(tmp < ar[k - 1]){
	ans[ar[i].S] = 3;
      }
    }
  }

  for(i = 0;i < n;i++){
    printf("%d ", ans[i]);
  }
  printf("\n");
  return 0;
}