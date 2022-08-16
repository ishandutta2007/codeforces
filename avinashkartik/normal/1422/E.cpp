#include<bits/stdc++.h>

using namespace std;
 
#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first                 
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()           
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  1e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, sz[N];
string s;
string ans[N];

void solve(){
	cin >> s;
	n = s.size();
	string res = "", prv = "";
	int f = 0;
	for(int i = n - 1; i >= 0; i--){
		if(f == 1){
			if(prv.size() == 0 or prv.back() != s[i]) prv += s[i];
			res += s[i];
			f = 0;
		} else {
			if(res.size() == 0){
				if(prv.size() == 0 or prv.back() != s[i]) prv += s[i];
				res += s[i];
			} else if(s[i] == res.back()){
				if(prv.size() == 1 or prv[prv.size()-2] < s[i]){
					f = 1;
					res.pop_back();
					if(res.size() == 0 or prv.back() != res.back()) prv.pop_back(); 
				} else {
					if(prv.size() == 0 or prv.back() != s[i]) prv += s[i];
					res += s[i];
				}
			} else {
				if(prv.size() == 0 or prv.back() != s[i]) prv += s[i];
				res += s[i];
			}
		}
		if(res.size() <= 10) ans[i + 1] = res;
		else{
			string tmp = "#";
			for(int j = res.size() - 1; j >= res.size() - 5; j--) tmp += res[j];
			tmp += "...";
			tmp += res[1];
			tmp += res[0];
			ans[i + 1] = tmp;
		}
		sz[i + 1] = res.size();
	}
	for(int i = 1; i <= n; i++){
		if(ans[i][0] != '#'){
			reverse(all(ans[i]));
			deb2(sz[i], ans[i])
		}
		else{
			cout << sz[i] << " ";
			for(int j = 1; j < ans[i].size(); j++) cout << ans[i][j];
			newl;
		}
	}
}

int main(){
	//GODSPEED;
	int test = 1;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}