// In the name of GOD
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 5000 + 100;

int n, st;
vector<int> v[maxn];

int dis(int fi, int se){
	if (fi <= se)
		return se - fi;
	return n + se - fi;
}

bool cmp(int fi, int se){
	return dis(st, fi) < dis(st, se);
}

int last[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	for (int i = 1; i <= n; i++){
		if (v[i].empty())
			continue;
		st = i;
		sort(v[i].begin(), v[i].end(), cmp);
		last[i] = n * int(v[i].size() - 1) + dis(i, v[i][0]);
	}
	for (int i = 1; i <= n; i++){
		int answer = 0;
		for (int j = 1; j <= n; j++)
			if (last[j] != 0)
				answer = max(answer, dis(i, j) + last[j]);
		cout << answer << " ";
	}
}