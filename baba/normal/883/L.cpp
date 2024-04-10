//TooWeakTooSlow
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

//#define TRACE

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

const int N = int(2e5)+10;
set<pair<LL, int>> S[N];
set<int> pos;
set<pair<LL, int>> busyCars;
int freq[N], carIdx[N];
LL waitTime[N], T[N], lastAvail[N];
int A[N], B[N], lastTrip[N];
set<LL> times;
void insert(int p, int id, LL ct){
  freq[p]++;
  if(freq[p] == 1){
    pos.insert(p);
  }
  S[p].insert({ct, id});
}
void remove(int p, int id){
  freq[p]--;
  if(freq[p] == 0){
    pos.erase(p);
  }
  S[p].erase({lastAvail[id], id});
}
LL INF = LL(1e18);
int getFinalPos(int l, int x, int r){
  if(l < -N || r > N)return l < -N ? r : l;
  if(x - l != r - x)return x - l < r - x ? l : r;
  if(S[l].begin()->F != S[r].begin()->F)return S[l].begin()->F < S[r].begin()->F ? l : r;
  return S[l].begin()->S < S[r].begin()->S ? l : r;
}
bool assign(int idx, LL ct){
  if(pos.empty())return false; //no cars available
  //at least one car is available
  //Find the nearest cars position
  int prv = -N - 1, nxt = +N + 1;
  auto it = pos.upper_bound(A[idx]);
  if(it != pos.end()){
    nxt = *it;
  }
  if(it != pos.begin()){
    it--;prv = *it;
  }
  //We have position prv and nxt. Find the closest one
  int finalPos = getFinalPos(prv, A[idx], nxt);
  assert(finalPos >= 0 && finalPos <= N);
  //Assign the best taxi standing at finalPos to idx
  carIdx[idx] = S[finalPos].begin()->S;
  waitTime[idx] = ct + abs(A[idx] - finalPos) - T[idx];
  //Remove taxi from the structure and push into busyCars with appropriate ending time.
  remove(finalPos, carIdx[idx]);
  busyCars.insert({ct + abs(A[idx] - finalPos) + abs(A[idx] - B[idx]), carIdx[idx]});
  lastTrip[carIdx[idx]] = idx;
  lastAvail[carIdx[idx]] = ct + abs(A[idx] - finalPos) + abs(A[idx] - B[idx]);
  times.insert(lastAvail[carIdx[idx]]);
  return true;
}
void freeCar(LL ct){
  //free the topmost car in busyCars
  assert(!busyCars.empty() && busyCars.begin()->F <= ct);
  auto car = *busyCars.begin();busyCars.erase(busyCars.begin());
  int idx = car.S;
  LL avTime = car.F;
  assert(lastAvail[idx] == avTime && ct == avTime);
  int endPos = B[lastTrip[idx]];
  insert(endPos, idx, ct);
}
int main()
{
  int n, k, m;
  si(n);si(k);si(m);
  LL ct = 0;
  REP(i, k){
    int pos;si(pos);
    insert(pos, i + 1, ct);
  }
  REP(i, m){
    sll(T[i]);si(A[i]);si(B[i]);
    times.insert(T[i]);
  }
  int idx = 0;
  while(!times.empty()){
    ct = *times.begin();
    times.erase(times.begin());
    while(!busyCars.empty() && busyCars.begin()->F <= ct){
      freeCar(ct);
    }
    while(idx < m && T[idx] <= ct && assign(idx, ct)){
      idx++;
    }
  }
  trace(idx);
  assert(idx == m);
  REP(i, m)printf("%d %lld\n",carIdx[i], waitTime[i]);
	return 0;
}