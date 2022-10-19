#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	
	vector <string> row(N + 1);
	vector <vector <int>> gps(1);
	for (int i = 0; i <= N; i++)
		gps[0].push_back(i);
	
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		for (int j = 0; j < gps.size(); j++)
			if (gps[j].size() > 1) {
				swap(gps[j], gps[0]);
				break;
			}
		vector <vector <int>> nxt;
		for (auto it : gps) {
			int ones = it.size();
			if (it[0] == gps[0][0])
				ones--;
			ones = min(ones, x);
			x -= ones;
			vector <int> tmp[2];
			for (int j = 0; j < it.size(); j++) {
				int digit = j < ones;
				tmp[digit].push_back(it[j]);
				row[it[j]] += (char)(digit + '0');
			}
			for (int j = 0; j < 2; j++)
				if (!tmp[j].empty())
					nxt.push_back(tmp[j]);
		}
		gps = nxt;
	}
	
	printf("%d\n", N + 1);
	for (int i = 0; i <= N; i++)
		puts(row[i].c_str());
		
	return 0;
}