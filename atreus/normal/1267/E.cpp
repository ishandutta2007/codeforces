#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 3000 + 5;

int a[105][105];
bool mark[105];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	int answer = m;
	vector<pair<int, int> > ans;
	for (int i = 0; i < n - 1; i++){
		int j = n - 1;
		vector<pair<int, int> > diffs;
		for (int k = 0; k < m; k++)
			diffs.push_back({a[k][j] - a[k][i], k});
		sort(diffs.begin(), diffs.end());
		int sum = 0;
		for (int k = 0; k < m; k++){
			sum += diffs[k].first;
			if (sum <= 0 and (m - k - 1) < answer){
				answer = (m - k - 1);
				ans = diffs;
			}
		}
	}
	int sum = 0;
	for (auto k : ans){
		sum += k.first;
		if (sum <= 0)
			mark[k.second] = 1;
	}
	cout << answer << endl;
	for (int i = 0; i < m; i++)
		if (mark[i] == 0)
			cout << i + 1 << " ";
	cout << endl;
}