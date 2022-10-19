#include <bits/stdc++.h>

using namespace std;

const long long int MAXN = 3005;

const long long int MAXINT = 4611686018427387903;

vector<long long int> v[MAXN];

vector<long long int> voters[MAXN];

multiset<long long int> all_v;

multiset<long long int> all_voters;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long int n, m, p, c, result, current, answer = MAXINT;
	cin >> n >> m;
	for (long long int i = 0; i < n; i++) {
		cin >> p >> c;
		v[p - 1].push_back(c);
		if (p != 1)
			all_v.insert(c);
	}
	for (long long int i = 0; i < m; i++)
		sort(v[i].begin(), v[i].end(), greater<long long int>());
	for (long long int i = 1; i <= n; i++) {
		for (long long int j = 0; j < m; j++)
			voters[j] = v[j];
		all_voters = all_v;
		result = 0;
		current = voters[0].size();
		for (long long int j = 1; j < m; j++)
			while (voters[j].size() >= i) {
				current++;
				result += voters[j].back();
				all_voters.erase(all_voters.find(voters[j].back()));
				voters[j].pop_back();
			}
		while (current < i) {
			result += *all_voters.begin();
			all_voters.erase(all_voters.begin());
			current++;
		}
		answer = min(answer, result);
	}
	cout << answer;
	return 0;
}