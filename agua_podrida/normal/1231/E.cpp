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

bool esPermutacion(string a, string b){
	sort(todo(a));
	sort(todo(b));
	return a == b;
}

bool esSubsec(string s, string t, int l, int r){
	int j = 0;
	REP(i,l,r){
		while(j < s.size() and s[j] != t[i]) j++;
		j++;
	}
	return (j <= s.size());
}

int main(){
	int q;
	cin>>q;
	while(q--){
		int n;
		string s,t;
		cin>>n>>s>>t;
		if(!esPermutacion(s,t)){
			cout<<"-1\n";
			continue;
		}
		int res = 0;
		F0(i,n){
			REP(j,i,n-1){
				if(esSubsec(s,t,i,j)) res = max(res,j-i+1);
			}
		}
		cout<<n-res<<'\n';
	}
}