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
ll p[1000], l[1000], pc =0;
void factor(ll n){
	ll on = n;
	for(ll i = 2;i*i<=n;i++){
		if(on%i == 0){
			pc++;
			p[pc-1] = i;
		}
		while(on%i == 0){
			on/=i;
			l[pc-1]++;
		}
	}
	if(on != 1){
		p[pc] = on, l[pc++] = 1;
	}
}
int main(){
	FAST;
	ll n;
	cin >> n;
	factor(n);
	if(n == 1){
		cout << 1 << endl;
		exit(0);
	}
	if(pc == 1){
		cout << p[0] << endl;
	}else{
		cout << 1 << endl;
	}
}