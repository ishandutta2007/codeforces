#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

int a[maxn], b[maxn], nex[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	stack<int> S;
	int T = -1;
	for (int i = n; i >= 1; i--){
		if (a[i] == 1)
			S.push(i);
		if (a[i] == 2){
			if (S.empty())
				return cout << "-1\n", 0;
			nex[i] = S.top();
			S.pop();
			if (T == -1)
				T = i;
		}
		if (a[i] == 3){
			if (S.empty() and T == -1)
				return cout << "-1\n", 0;
			if (T != -1){
				nex[i] = T;
				T = i;
			}
			else{
				nex[i] = S.top();
				S.pop();
				T = i;
			}
		}
	}
	int free = n;
	vector<pair<int,int>> ops;
	for (int i = n; i >= 1; i--){
		if (a[i] == 0)
			continue;
		if (a[i] == 1){
			ops.push_back({free,i});
			b[i] = free;
			free --;
			continue;
		}
		if (a[i] == 2){
			ops.push_back({b[nex[i]],i});
			b[i] = b[nex[i]];
			continue;
		}
		if (a[i] == 3){
			ops.push_back({free,i});
			ops.push_back({free, nex[i]});
			b[i] = free;
			free --;
			continue;
		}
	}
	cout << ops.size() << '\n';
	for (auto it : ops)
		cout << it.first << " " << it.second << '\n';
}