#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 100000 + 5;
const int mod = 1e9 + 7;

pair<int,int> Q[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, h, m, k;
	cin >> n >> h >> m >> k;
	m /= 2;
	vector<pair<int,int>> ops;
	for (int i = 0; i < n; i++){
		int hi, mi;
		cin >> hi >> mi;
		mi %= m;
		Q[i] = {hi, mi};
		if (k == 1)
			continue;
		if (mi+k-1 < m){
			ops.push_back({mi+1,1});
			ops.push_back({mi+k,-1});
		}
		else{
			ops.push_back({mi+1,1});
			ops.push_back({0,1});
			ops.push_back({(mi+k)%m,-1});
		}
	}
	if (k == 1){
		cout << 0 << " " << 0 << endl;
		cout << endl;
		return 0;
	}
	sort(ops.begin(), ops.end());
	int now = 0;
	int answer = n, t = 0;
	for (int i = 0; i < ops.size(); i++){
		now += ops[i].second;
		if ((i == ops.size() - 1 or ops[i].first != ops[i+1].first) and answer > now)
			answer = min(answer, now), t = ops[i].first;
	}
	cout << answer << " " << t << endl;
	for (int i = 0; i < n; i++){
		int hi = Q[i].first, mi = Q[i].second;
		if (mi+1 <= t and t < mi+k){
			cout << i+1 << " ";
			continue;
		}
		if (mi+1 <= t+m and t+m < mi+k){
			cout << i+1 << " ";
		}
	}
	cout << '\n';
}