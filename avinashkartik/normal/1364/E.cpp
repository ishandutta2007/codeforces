#include<bits/stdc++.h>

using namespace std;

#define  f              first                 
#define  s              second
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;

typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  1e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, x, ans[N], vis[N];
map <pair<int,int>, int> m;

int find(int i, int j, int k){
	if(i <= n) return i;
	for(int ii = 1; ii <= n; ii++){
		if(vis[ii]) continue;
		if(ii != j and ii != k){
			vis[ii] = 1;
			return ii;
		}
	}
}

int q(int i, int j){
	if(i > j) swap(i, j);
	if(m[make_pair(i, j)] == 0){
		int x;
		deb3('?', i, j)
		cin >> x;
		m[make_pair(i, j)] = x;
	}
	return m[make_pair(i, j)];
}

int query(int i, int j, int k){
	int x = q(i, j);
	int y = q(j, k);
	if(x < y) return 3;
	if(x > y) return 1;
	return 2;	
}

bool check(int x, int y, int z){
	return (x|z) == y;
}
 
int query1(int i, int j, int k){
	int x = q(i, j);
	int y = q(j, k);
	int z = q(k, i);
	if(x == y and x == z) return 0;
	if(x == z) return 4;
	if(x == y) return 5;
	if(y == z) return 6;
	if(check(x, y, z)) return 1;
	if(check(y, z, x)) return 2;
	if(check(z, x, y)) return 3;
	return 0;
}

void solve(){
	mset(ans, -1);
	cin >> n;
	int i = 1, j = 2, k = 3, nxt = 4, f = 3;
	while(f == 3){
		int ch = query(i, j, k);
		if(ch == 1){
			i = nxt++;
		} else if(ch == 2){
			j = nxt++;
		} else {
			k = nxt++;
		}
		f = (i <= n) + (j <= n) + (k <= n);
	}
	while(f == 2){
		i = find(i, j, k);
		j = find(j, i, k);
		k = find(k, i, j);
		int ch = query1(i, j, k);
		if(!ch){
			i = nxt++;
			j = nxt++;
			k = nxt++;
		} else if(ch == 1){
			j = nxt++;
			k = nxt++;
		} else if(ch == 2){
			i = nxt++;
			k = nxt++;
		} else if(ch == 3){
			i = nxt++;
			j = nxt++;
		} else if(ch == 4){
			i = nxt++;
		} else if(ch == 5){
			j = nxt++;
		} else {
			k = nxt++;
		}
		f = (i <= n) + (j <= n) + (k <= n);
	}
	int v;
	if(i <= n) v = i;
	else if(j <= n) v = j;
	else v = k;
	ans[v] = 0;
	for(int i = 1; i <= n; i++){
		if(ans[i] == -1){
			ans[i] = q(v, i);
		}
	}
	cout << '!' << " ";
	for(int i = 1; i <= n; i++) cout << ans[i] << " ";
}

int main(){
	int test = 1;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}