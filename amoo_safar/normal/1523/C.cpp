// vaziat meshki-ghermeze !
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

int a[N];

vector<int> V;
void Print(){
	int n = V.size();
	for(int i = 0; i < n; i++)
		cout << V[i] << ".\n"[i == n - 1];
}

int Main(){
	V.clear();
	int n;
	cin >> n;
	V.pb(1);
	int v; cin >> v;
	Print();
	for(int i = 1; i < n; i++){
		cin >> v;
		if(v == 1){
			V.pb(1);
			Print();
			continue;
		}
		while(V.back() != v - 1){
			V.pop_back();
		}
		V.pop_back();
		V.pb(v);
		Print();
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while(T --) Main();
	return 0;
}