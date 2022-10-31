#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 500
#define INF 101111111111111
using namespace std;
ll a[N][N];
int main(){
	FAST;
	ll r, c;
	cin >> r >> c;
	if(r == 1 && c == 1){
		//pass
	}else if(r == 1 && c != 1){
		for(ll i = 0;i<c;i++) a[0][i] = i+2;
	}else if(r != 1 && c == 1){
		for(ll i = 0;i<r;i++) a[i][0] = i+2;
	}else{
		for(ll i = 0;i<c;i++) a[0][i] = i+2;
		for(ll i = 1;i<r;i++){
			for(ll j = 0;j<c;j++) a[i][j] = (a[0][j])*(c+1+i);
		}
	}

	for(ll i = 0;i<r;i++){
		for(ll j = 0;j<c;j++) cout << a[i][j] << " ";
			cout << endl;
	}
}