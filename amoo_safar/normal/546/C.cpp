// Amsal Shoma Ro Gaedan Ye Amal Pasandidas !
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

queue<ll> q1, q2;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	int k1, k2, v;
	cin >> k1;
	for(int i = 0; i < k1; i++){
		cin >> v; q1.push(v);
	}
	cin >> k2;
	for(int i = 0; i < k2; i++){
		cin >> v; q2.push(v);
	}
	int TOF = 1e6;
	int cnt = 0;
	while(TOF --){
		if(q1.empty()) return cout << cnt << " 2\n", 0;
		if(q2.empty()) return cout << cnt << " 1\n", 0;
		cnt ++;
		int p1 = q1.front(); q1.pop();
		int p2 = q2.front(); q2.pop();	
		if(p1 < p2){
			q2.push(p1);
			q2.push(p2);
		} else {
			q1.push(p2);
			q1.push(p1);
		}
	}
	cout << "-1\n";
	return 0;
}