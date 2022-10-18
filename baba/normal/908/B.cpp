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

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

char A[200][200], s[3];
int sx, sy, ex, ey;
map<char, int> dx, dy;
bool ok(int n, int m, int len){
  auto good = [&](int i, int j){
    return i >= 0 && i < n && j >= 0 && j < m && A[i][j] != '#';
  };
  int x = sx, y = sy;
  REP(i, len){
    x += dx[s[i]];
    y += dy[s[i]];
    if(!good(x, y))return false;
    if(A[x][y] == 'E')return true;
  }
  return A[x][y] == 'E';
}
int main()
{
  int n, m;
  si(n);si(m);
  REP(i, n)scanf("%s", A[i]);
  scanf("%s", s);
  int len = strlen(s);
  VI temp = {0, 1, 2, 3};
  int ans = 0;
  REP(i, n)REP(j, m)if(A[i][j] == 'S')sx = i, sy = j;
  REP(i, n)REP(j, m)if(A[i][j] == 'E')ex = i, ey = j;
  do{
    dx.clear();dy.clear();
   dx[temp[0] + '0'] = 0;
   dx[temp[1] + '0'] = 0;
   dx[temp[2] + '0'] = +1;
   dx[temp[3] + '0'] = -1;
   dy[temp[0] + '0'] = +1;
   dy[temp[1] + '0'] = -1;
   dy[temp[2] + '0'] = 0;
   dy[temp[3] + '0'] = 0;
   if(ok(n, m, len))ans++;
   
  }while(next_permutation(ALL(temp)));
  dout(ans);

	return 0;
}