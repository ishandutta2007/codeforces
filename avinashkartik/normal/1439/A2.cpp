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
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, m;
string s[N];

struct ans{
	int r[6];
	void print(){
		cout << r[0] << " " << r[1] << " " << r[2] << " " << r[3] << " " << r[4] << " " << r[5] << "\n";
	}
};

vector <ans> v;

void flip(int i, int j){
	if(s[i][j] == '1') s[i][j] = '0';
	else s[i][j] = '1';
}

void do1(int x, int y){
	int r[6] = {};
	r[0] = x, r[1] = y;
	flip(x, y);
	r[2] = x + 1, r[3] = y;
	flip(x + 1, y);
	if(s[x][y + 1] == '1'){
		r[4] = x, r[5] = y + 1;
		flip(x, y + 1);
	} else {
		r[4] = x + 1, r[5] = y + 1;
		flip(x + 1, y + 1);
	}
	ans u;
	for(int k = 0; k < 6; k++) u.r[k] = r[k] + 1;
	v.pb(u);
}

void do2(int x, int y){
	int ct = 0, f = 0;
	int r[6] = {};
	for(int i = 0; i <= 1; i++){
		for(int j = 0; j <= 1; j++){
			if(s[x + i][y + j] == '0'){
				r[2 * ct] = x + i;
				r[2 * ct + 1] = y + j;
				ct++;
				flip(x + i, y + j);
			} else if(f == 0) {
				r[2 * ct] = x + i;
				r[2 * ct + 1] = y + j;
				ct++;
				flip(x + i, y + j);
				f++;
			}
		}
	}
	ans u;
	for(int k = 0; k < 6; k++) u.r[k] = r[k] + 1;
	v.pb(u);
}

void do3(int x, int y){
	int ct = 0;
	int r[6] = {};
	for(int i = 0; i <= 1; i++){
		for(int j = 0; j <= 1; j++){
			if(s[x + i][y + j] == '1'){
				r[2 * ct] = x + i;
				r[2 * ct + 1] = y + j;
				ct++;
				flip(x + i, y + j);
			}
		}
	}
	ans u;
	for(int k = 0; k < 6; k++) u.r[k] = r[k] + 1;
	v.pb(u);
}

void calc(int x, int y){
	int ct = 0;
	for(int i = 0; i <= 1; i++){
		for(int j = 0; j <= 1; j++){
			ct += s[x + i][y + j] - '0';
		}
	}
	if(ct == 1){
		do1(x, y);
		do2(x, y);
		do3(x, y);
	} else if(ct == 2){
		do2(x, y);
		do3(x, y);
	}
}

void solve(){
	cin >> n >> m;
	v.clear();
	for(int i = 0; i < n; i++) cin >> s[i];
	if(n&1){
		for(int i = 0; i < 1; i++){
			for(int j = 0; j < m - 1; j++){
				if(s[i][j] == '0' && s[i][j + 1] == '0') continue;
				int r[6] = {};
				int ct = 0;
				if(s[i][j] == '1'){
					r[2 * ct] = i;
					r[2 * ct + 1] = j;
					ct++;
					flip(i, j);
				}
				if(s[i][j + 1] == '1'){
					r[2 * ct] = i;
					r[2 * ct + 1] = j + 1;
					ct++;
					flip(i, j + 1);
				}
				r[2 * ct] = i + 1;
				r[2 * ct + 1] = j;
				ct++;
				flip(i + 1, j);
				if(ct == 2) {
					r[2 * ct] = i + 1;
					r[2 * ct + 1] = j + 1;
					ct++;
					flip(i + 1, j + 1);
				}
				ans u;
				for(int k = 0; k < 6; k++) u.r[k] = r[k] + 1;
				v.pb(u);
			}
		}
	}
	if(m&1){
		for(int j = 0; j < 1; j++){
			for(int i = n&1; i < n - 1; i++){
				if(s[i][j] == '0' && s[i + 1][j] == '0') continue;
				int r[6] = {};
				int ct = 0;
				if(s[i][j] == '1'){
					r[2 * ct] = i;
					r[2 * ct + 1] = j;
					ct++;
					flip(i, j);
				}
				if(s[i + 1][j] == '1'){
					r[2 * ct] = i + 1;
					r[2 * ct + 1] = j;
					ct++;
					flip(i + 1, j);
				}
				r[2 * ct] = i;
				r[2 * ct + 1] = j + 1;
				ct++;
				flip(i, j + 1);
				if(ct == 2) {
					r[2 * ct] = i + 1;
					r[2 * ct + 1] = j + 1;
					ct++;
					flip(i + 1, j + 1);
				}
				ans u;
				for(int k = 0; k < 6; k++) u.r[k] = r[k] + 1;
				v.pb(u);
			}
		}
	}
	if(n < m){
		for(int i = n&1; i < n - 1; i += 2){
			for(int j = 0; j < m - 1; j++){
				if(s[i][j] == '0' && s[i + 1][j] == '0') continue;
				int r[6] = {};
				int ct = 0;
				if(s[i][j] == '1'){
					r[2 * ct] = i;
					r[2 * ct + 1] = j;
					ct++;
					flip(i, j);
				}
				if(s[i + 1][j] == '1'){
					r[2 * ct] = i + 1;
					r[2 * ct + 1] = j;
					ct++;
					flip(i + 1, j);
				}
				r[2 * ct] = i;
				r[2 * ct + 1] = j + 1;
				ct++;
				flip(i, j + 1);
				if(ct == 2) {
					r[2 * ct] = i + 1;
					r[2 * ct + 1] = j + 1;
					ct++;
					flip(i + 1, j + 1);
				}
				ans u;
				for(int k = 0; k < 6; k++) u.r[k] = r[k] + 1;
				v.pb(u);
			}
			calc(i, m - 2);
		}
	} else {
		for(int j = m&1; j < m - 1; j += 2){
			for(int i = 0; i < n - 1; i++){
				if(s[i][j] == '0' && s[i][j + 1] == '0') continue;
				int r[6] = {};
				int ct = 0;
				if(s[i][j] == '1'){
					r[2 * ct] = i;
					r[2 * ct + 1] = j;
					ct++;
					flip(i, j);
				}
				if(s[i][j + 1] == '1'){
					r[2 * ct] = i;
					r[2 * ct + 1] = j + 1;
					ct++;
					flip(i, j + 1);
				}
				r[2 * ct] = i + 1;
				r[2 * ct + 1] = j;
				ct++;
				flip(i + 1, j);
				if(ct == 2) {
					r[2 * ct] = i + 1;
					r[2 * ct + 1] = j + 1;
					ct++;
					flip(i + 1, j + 1);
				}
				ans u;
				for(int k = 0; k < 6; k++) u.r[k] = r[k] + 1;
				v.pb(u);
			}
			calc(n - 2, j);
		}
	}
	for(int i = 0; i < n; i++){
		//deb1(s[i])
		for(int j = 0; j < m; j++){
			assert(s[i][j] == '0');
		}
	}
	deb1(v.size())
	for(auto it : v){
		it.print();
	}
}

int main(){
	GODSPEED;
	int test = 1;
	cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}