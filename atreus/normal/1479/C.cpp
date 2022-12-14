#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 32 + 10;
const int mod = 998244353;
const int inf = 1e6 + 10;

vector<pair<int,int>> g[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int L, R;
	cin >> L >> R;
	cout << "YES\n";
	int n = 28, m = 0;
	int st = 2;
	if (L == 1)
		st = 1;
	else{
		g[1].push_back({2,L-1});
		m++;
	}
	R = R-L+1;
	for (int i = st+1; i <= n-1; i++){
		int now = 1;
		g[st].push_back({i,1});
		m++;
		for (int j = st+1; now+1 <= 1000*1000 and j < i; j++){
			g[j].push_back({i,now});
			m++;
			now += (1<<(j-st-1));
		}
	}
	g[st].push_back({n,1});
	m ++;
	int now = 1;
	for (int i = 0; i < 25 and now <= 1000*1000; i++){
		if ((R-1) & (1 << i)){
			int idx = (i+st+1);	
			g[idx].push_back({n,now});
			m++;
			now += (1<<i);
		}
	}
	cout << n << " " << m << endl;
	for (int i = 1; i <= n; i++)
		for (auto [u,w] : g[i])
			cout << i << " " << u << " " << w << endl;
}