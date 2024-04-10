// faz lati nemigire bache shir !
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
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int Main(){
	int n;
	cin >> n;
	str s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	int p1 = 0, p2 = 0, p3 = 0;
	n = n + n;
	str res = "";
	int c0, c1;
	while(max({p1, p2, p3}) < n){
		// cerr << p1 << ' ' << p2 << p3 << '\n';
		c0 = 0; c1 = 0;
		if(s1[p1] == '0') c0++;
		else c1 ++;
		if(s2[p2] == '0') c0++;
		else c1 ++;
		if(s3[p3] == '0') c0++;
		else c1 ++;
		char gd = '1';
		if(c0 > c1) gd = '0';

		res += gd;
		if(s1[p1] == gd) p1 ++;
		if(s2[p2] == gd) p2 ++;
		if(s3[p3] == gd) p3 ++;
	}
	vector<int> V = {p1, p2, p3};
	sort(all(V));
	if(V[1] == n) return cout << res << '\n', 0;
	if(p1 == V[1]){
		while(p1 < n){ res += s1[p1]; p1 ++;} 
	} else if (p2 == V[1]){
		while(p2 < n){ res += s2[p2]; p2 ++;}
	} else {
		while(p3 < n){ res += s3[p3]; p3 ++;}
	}
	cout << res << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while(T --) Main();
	return 0;
}