#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e3 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

str s[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int check(str a, str b){
	int ans = 0;
	for(int i = 0; i < 7; i++){
		if(a[i] == '1' && b[i] == '0') ans ++;
		if(a[i] == '0' && b[i] == '1') ans += N;	
	}
	return min(ans, N);
}

bitset<N> bt[N];
str in[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, k;
	cin >> n >> k;
	for(int i = 0; i <n; i++) cin >> in[i];
	bt[n][0] = 1;
	for(int i = n - 1; i >= 0; i--){
		for(int j = 0; j <= 9; j++){
			bt[i] |= (bt[i + 1] << check(s[j], in[i]));
		}
	}
	if(bt[0][k] == 0) return cout << "-1\n", 0;

	for(int i = 0; i < n; i++){
		for(int j = 9; j >= 0; j--){
			ll r = check(s[j], in[i]);
			if(r > k) continue;
			if(bt[i + 1][k-r]){
				k -= r;
				cout << j;
				break;
			}
		}
	}
	return 0;
}