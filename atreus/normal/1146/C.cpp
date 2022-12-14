/***
  * Virtual Contest: Forethought Future Cup - Elimination Round
***/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;

int ask(vector<int> fi, vector<int> se){
	if (fi.empty() or se.empty())
		return 0;
	cout << fi.size() << " " << se.size() << " ";
	for (auto v : fi)
		cout << v << " ";
	for (auto u : se)
		cout << u << " ";
	cout << endl;
	int x;
	cin >> x;
	return x;
}

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int answer = 0;
		int n;
		cin >> n;
		for (int i = 0; i < 7; i++){
			vector<int> fi, se;
			for (int j = 0; j < n; j++){
				if (j & (1 << i))
					fi.push_back(j + 1);
				else
					se.push_back(j + 1);
			}
			answer = max(answer, ask(fi, se));
		}
		cout << "-1 " << answer << endl;
	}
}