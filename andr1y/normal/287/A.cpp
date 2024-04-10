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
#define N 200000
#define INF 101111111111111
using namespace std;
ll a[4][4];
ll check(ll i, ll j){
	return (a[i][j]) + (a[i+1][j]) + (a[i][j+1]) + (a[i+1][j+1]);
}
int main(){
	FAST;
	for(ll i =0;i<4;i++){
		for(ll j  =0;j<4;j++){
			char c;
			cin >> c;
			a[i][j] = (c == '#' ? 1 : 0);
		}
	}
	for(ll i =0;i<3;i++){
		for(ll j  =0;j<3;j++){
			if(check(i, j) != 2){
				cout << "YES" << endl;
				exit(0);
			}
		}
	}
	cout << "NO" << endl;
}