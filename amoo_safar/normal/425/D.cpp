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
const int Sqrt = 220;

vector<int> V[N];

int x[N], y[N];
int n;

int mk[N], T = 0;
int mk2[N], T2 = 0;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
		V[x[i]].pb(y[i]);
	}
	for(int i = 0; i < n; i++) sort(all(V[i]));

	int ans = 0;
	for(int i = 0; i < N; i++){
		if(V[i].size() < Sqrt) continue;
		
		T ++;
		for(auto p : V[i]) mk[p] = T;
		V[i].clear();
		for(int j = 0; j < N; j++){
			if(V[j].empty()) continue;
			T2 ++;
			for(auto p : V[j]) mk2[p] = T2;
			for(auto p : V[j]){
				ans += (mk[p] == T) && (mk[p + abs(i - j)] == T) && (mk2[p + abs(i - j)] == T2);
			}
		}
	}

	int ln;
	for(int i = 0; i < N; i++){
		if(V[i].size() < 2) continue;
		int m = V[i].size();
		for(int j = 0; j < m; j++){
			for(int k = j + 1; k < m; k++){
				ln = V[i][k] - V[i][j];
				auto it = lower_bound(all(V[i + ln]), V[i][j]);
				if(it != V[i + ln].end() && *it == V[i][j]){
					it = lower_bound(all(V[i + ln]), V[i][j] + ln);
					ans += (it != V[i + ln].end() && *it == V[i][k]);
				}
			}
		}
	}












	cout << ans << '\n';
	return 0;
}