#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;  
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());          
          
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;

const ll   N     =  3e5+8;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int test = 1, n, k;
string s;
char op[4] = {'(','{','[','<'}, cl[4] = {')','}',']','>'};

void solve(){
	cin>>s;
	n = s.size();
	int ct = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '(' or s[i] == '{' or s[i] == '[' or s[i] == '<') ct++;
		else ct--;
		if(ct < 0){
			deb1("Impossible")
			return;
		}
	}
	if(ct){
		deb1("Impossible")
		return;
	}
	stack <char> ch;
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '(' or s[i] == '{' or s[i] == '[' or s[i] == '<'){
			ch.push(s[i]);
		}
		else{
			char t = ch.top(); ch.pop();
			int f = 0;
			for(int j = 0; j < 4; j++){
				if(cl[j] == s[i] and op[j] == t){
					f = 1;
				}
			}
			if(f == 0) ans++;
		}
	}
	deb1(ans)
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}