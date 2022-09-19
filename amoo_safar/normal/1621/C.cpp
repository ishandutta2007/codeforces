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
typedef pair<int, int> pii;

const int Mod = 1000000007LL;
const int N = 1e4 + 10;
const int Log = 30;
const ll Inf = 2242545357980376863LL;

int mk[N];
int Ask(int i){
	cout << "? " << i << endl;
	int res;
	cin >> res;
	return res;
}
int p[N];
int Main(){
	memset(mk, 0, sizeof mk);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		if(mk[i]) continue;
		vector<int> V = {};
		while(true){
			int x = Ask(i);
			V.pb(x);
			if(mk[x]) break;
			mk[x] = 1;
		}
		for(int j = 0; j + 1 < V.size(); j++){
			p[V[j]] = V[j + 1];
		}
	}
	cout << "!";
	for(int i = 1; i <= n; i++) cout << " " << p[i];
	cout << endl;
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while(tc --) Main();
	return 0;
}