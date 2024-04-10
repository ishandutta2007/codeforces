#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
ll mod = 998244353;

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define F first
#define S second
#define INF 100000000
#define todo(v) v.begin(),v.end()
#define eps 0.000000001

vector<int> z(string s) {
  int n = s.size();
  vector<int> z(n);
  int x = 0, y = 0;
  for (int i = 1; i < n; i++) {
    z[i] = max(0,min(z[i-x],y-i+1));
    while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
      x = i; y = i+z[i]; z[i]++;
    }
  }
  return z;
}


int main()
{
	int n;
	cin>>n;
	string res;
	string s;
	string pedazoQueSirve;
	F0(k,n){
		cin>>s;
		pedazoQueSirve = res.substr(max(0,(int) res.size()- (int) s.size()),min(s.size(), res.size()));
		string aux = s + pedazoQueSirve;
		vi zarr = z(aux);
		int in = zarr.size();
		REP(i,s.size(),zarr.size()-1){
			if(zarr[i] + i == zarr.size()) {
				in = i;
				break;
			}
		}
		in = zarr.size()-in;
		res += s.substr(in,s.size()-in);
	}
	cout<<res<<'\n';
	return 0;
}