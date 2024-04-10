#include <iostream>
#include <vector>
#include <set>

using namespace std;

set <int> st[200];
int price[300];

bool check(int l, int r, int p){
	if (st[l].find(r) == st[l].end() || st[l].find(p) == st[l].end())
		return false;
	if (st[r].find(l) == st[r].end() || st[r].find(p) == st[r].end())
		return false;
	if (st[p].find(l) == st[p].end() || st[p].find(r) == st[p].end())
		return false;
	return true;
}

int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> price[i];
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		st[a].insert(b);
		st[b].insert(a);
	}
	int ans = 100000000;
	for (int i = 1; i <= n - 2; i++){
		for (int j = i + 1; j <= n - 1; j++){
			for (int k = j + 1; k <= n; k++){
				if (check(i, j, k))
					ans = min(ans, price[i] + price[j] + price[k]);
			}
		}
	}
	if (ans == 100000000)
        ans = -1;
	cout << ans << endl;
	return 0;
}