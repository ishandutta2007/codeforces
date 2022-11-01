#include<bits/stdc++.h>

using namespace std;

typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;

#define pb push_back
#define ctz __builtin_ctz
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,x,cur,maxsofar = -1;
  set<ll> s;
  cin>>n>>x;
  vll biggest(x+5,-1);
  ll blocker=x,mininvolved=1;
  for(int i=0;i<n;++i) {
  	cin>>cur;
  	auto it = s.upper_bound(cur);
  	if(it != s.end()) {
  		biggest[cur] = max(maxsofar, biggest[cur]); // we free this guy, need to consume till him
  		blocker = min((*it), blocker); // can't consume from blocker+1 onwards
  		//db2(cur, *it);
  		mininvolved=max(mininvolved,cur); // first consumption must be this much or more
  	}
  	s.insert(cur);
  	maxsofar = max(maxsofar, cur);
  }
  ll rightptr = mininvolved, ans=0;
  //db2(mininvolved, blocker);
  for(ll i=1;i<=x;++i) {
  	if(i > blocker) break;
  	ans += (x-rightptr+1);
  	//db(ans);
  	rightptr = max(rightptr, biggest[i]);
  	rightptr = max(rightptr, i+1);
  }
  cout<<ans<<endl;

}