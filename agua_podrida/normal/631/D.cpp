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
typedef pair<ll,char>  psi;
typedef vector<psi> vpsi;
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

vector<int> z(vpsi s) {
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


int main(){
	int n, m;
	cin>>n>>m;
	vpsi t;
	vpsi s;
	vpsi s2;

	F0(i,n){
		string p;
		cin>>p;
		char c;
		ll num;

		c = p.back();
		p.pop_back();
		p.pop_back();
		num = stoi(p);

		if(i!=0){
			if(c==t.back().second){
				t.back().first += num;
			}
			else{
				t.pb(mp(num,c));
			}
		}
		else{
			t.pb(mp(num,c));
		}
	}

	F0(i,m){
		string p;
		cin>>p;
		char c;
		ll num;

		c = p.back();
		p.pop_back();
		p.pop_back();
		num = stoi(p);

		if(i!=0 && c==s.back().second){
			s.back().first += num;
		}
		else{
			s.pb(mp(num,c));
		}
	}

	ll res = 0;
	if(s.size() > 2){
		for(int i = 1; i < s.size()-1; i++){
			s2.pb(s[i]);
		}
		s2.pb(mp(-1,'-'));
		vpsi aux = s2;
		aux.insert(aux.end(), t.begin(), t.end());
		F0(i, t.size()){
		//cout<<t[i].first<<' '<<t[i].second<<'\n';
	}
	F0(i, s2.size()){
		//cout<<s2[i].first<<' '<<s2[i].second<<'\n';
	}
		vi zarr = z(aux);
		//F0(i,aux.size()){
		//	cout<<zarr[i]<<' ';
		//}
		//cout<<'\n';
		F0(i, zarr.size()){
			//cout<<(zarr[i] == s2.size()-1) << (i>s2.size()) << (t[i-1-s2.size()].second == s[0].second) << (t[i-1-s2.size()].first >= s[0].first) << (t[i+1].second == s.back().second) << (t[i+1].first >= s.back().first)<<'\n';
			//cout << t[i-1].second << " " << s[0].second << '\n';
			if(zarr[i] == s2.size()-1 && i>s2.size() && t[i-1-s2.size()].second == s[0].second && t[i-1-s2.size()].first >= s[0].first && t[i-1].second == s.back().second && t[i-1].first >= s.back().first) res++;
			//cout << res << '\n';
		}

	}
	else if(s.size() == 2){
		F0(i,t.size()-1){
			if(t[i].second == s[0].second && t[i].first >= s[0].first && t[i+1].second == s.back().second && t[i+1].first >= s.back().first) res++;
		}
	}
	else{
		F0(i,t.size()){
			if(t[i].second == s[0].second && t[i].first >= s[0].first) res+=t[i].first-s[0].first+1;
		}
	}
	/*
	F0(i, t.size()){
		cout<<t[i].first<<' '<<t[i].second<<'\n';
	}
	F0(i, s.size()){
		cout<<s[i].first<<' '<<s[i].second<<'\n';
	}
	*/
	cout<<res<<'\n';
	

}