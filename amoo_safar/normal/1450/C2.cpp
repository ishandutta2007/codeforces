// har ki ro didi goft mikhad beshe meslemon !
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

int x[N], y[N];

str s[N];

int Main(){
	int n;
	cin >> n;
	vector<int> cntX(3, 0), cntY(3, 0), cntS(3, 0);
	for(int i = 0; i < n; i++){
		cin >> s[i];
		for(int j = 0; j < n; j++){
			if(s[i][j] == 'X')
				cntX[(i + j) % 3] ++;
			if(s[i][j] == 'O')
				cntY[(i + j) % 3] ++;
			if(s[i][j] != '.')
				cntS[(i + j) % 3] ++;
		}
	}
	int idx = (max_element(all(cntS)) - cntS.begin());
	// debug(idx);
	vector<int> V;
	for(int i = 0; i < 3; i++) if(i != idx) V.pb(i);	
	// debug(V[0]);
	// debug(V[1]);
	int tx, ty;
	if(cntX[V[0]] + cntY[V[1]] < cntX[V[1]] + cntY[V[0]]){
		tx = V[1];
		ty = V[0];
	} else {
		ty = V[1];
		tx = V[0];
	}

	for(int i = 0; i < n; i++){
		//cin >> s[i];
		for(int j = 0; j < n; j++){
			if((i + j) % 3 == idx) continue;
			if(s[i][j] == '.') continue;
			
			if((s[i][j] == 'X') && ((i + j) % 3 == ty))
				s[i][j] = 'O';
			if((s[i][j] == 'O') && ((i + j) % 3 == tx))
				s[i][j] = 'X';
		}
		cout << s[i] << '\n';
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