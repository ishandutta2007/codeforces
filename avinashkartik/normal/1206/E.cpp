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
 
const ll   N     =  105;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, a[N][N];

void q(int r1, int c1, int r2, int c2){
	if(a[r2][c2] != -1) return;
	cout << "? ";
	deb4(r1, c1, r2, c2)
	int x;
	cin >> x;
	a[r2][c2] = a[r1][c1] ^ (1 - x);
}

void print(){
	deb1("!")
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << a[i][j];
		}
		cout << endl;
	}
}

void flip(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if((i + j) % 2 == 0) continue;
			a[i][j] = 1 - a[i][j];
		}
	}
}
 
void solve(){
	mset(a, -1);
	cin >> n;
	a[1][1] = 1, a[n][n] = 0, a[2][3] = 0;
	for(int i = 1; i <= n; i += 2){
		for(int j = 1; j <= n; j += 2){
			int r2 = i, c2 = j + 2;
			if(r2 <= n && c2 <= n) q(i, j, r2, c2);
			r2 = i + 1, c2 = j + 1;
			if(r2 <= n && c2 <= n) q(i, j, r2, c2);
			r2 = i + 2, c2 = j;
			if(r2 <= n && c2 <= n) q(i, j, r2, c2);
		}
	}
	cout << "? ";
	deb4(1, 2, 2, 3)
	int x;
	cin >> x;
	a[1][2] = a[2][3] ^ (1 - x);
	cout << "? ";
	deb4(2, 1, 2, 3)
	cin >> x;
	a[2][1] = a[2][3] ^ (1 - x);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if((i + j) % 2 == 0) continue;
			int r2 = i, c2 = j + 2;
			if(r2 <= n && c2 <= n) q(i, j, r2, c2);
			r2 = i + 1, c2 = j + 1;
			if(r2 <= n && c2 <= n) q(i, j, r2, c2);
			r2 = i + 2, c2 = j;
			if(r2 <= n && c2 <= n) q(i, j, r2, c2);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int r2 = i + 1, c2 = j + 2;
			if(r2 <= n && c2 <= n){
				if((a[i][j] == a[i + 1][j + 1]) == (a[i][j + 1] == a[r2][c2])){
					cout << "? ";
					deb4(i, j, r2, c2)
					cin >> x;
					if(x != (a[i][j] == a[r2][c2])) flip();
					print();
					return;
				}
			}
			r2 = i + 2, c2 = j + 1;
			if(r2 <= n && c2 <= n){
				if((a[i][j] == a[i + 1][j + 1]) == (a[i][j + 1] == a[r2][c2])){
					cout << "? ";
					deb4(i, j, r2, c2)
					cin >> x;
					if(x != (a[i][j] == a[r2][c2])) flip();
					print();
					return;
				}
			}
		}
	}

}

int main(){
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}