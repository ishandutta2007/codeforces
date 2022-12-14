#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
 
const int maxn = 2e5 + 10;

int n;
int fen[maxn], p[maxn];
vector<int> st[maxn], ft[maxn];

struct query{
	int lef;
	int dwn;
	int rig;
	int up;
	ll answer;
} q[maxn];

ll C(int k){
	return 1ll * k * (k - 1) / 2;
}

int get(int idx){
	int ret = 0;
	for (; idx; idx -= idx & -idx)
		ret += fen[idx];
	return ret;
}

void add(int idx){
	for (; idx <= n; idx += idx & -idx)
		fen[idx] ++;
}

int main(){
	ios_base::sync_with_stdio(false);
	int m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	for (int i = 1; i <= m; i++){
		cin >> q[i].lef >> q[i].dwn >> q[i].rig >> q[i].up;
		st[q[i].lef].push_back(i);
		ft[q[i].rig].push_back(i);
		q[i].answer = C(n) - C(q[i].lef - 1) - C(q[i].dwn - 1) - C(n - q[i].rig) - C(n - q[i].up);
	}
	for (int i = 1; i <= n; i++){
		for (auto it : st[i]){
			int num = get(q[it].dwn - 1);
			q[it].answer += C(num);
			num = (i - 1) - get(q[it].up);
			q[it].answer += C(num);
		}
		add(p[i]);
	}
	memset(fen, 0, sizeof fen);
	for (int i = n; i >= 1; i--){
		for (auto it : ft[i]){
			int num = get(q[it].dwn - 1);
			q[it].answer += C(num);
			num = (n - i) - get(q[it].up);
			q[it].answer += C(num);
		}
		add(p[i]);
	}
	for (int i = 1; i <= m; i++)
		cout << q[i].answer << '\n';
}