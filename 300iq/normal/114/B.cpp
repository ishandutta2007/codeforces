#include <bits/stdc++.h>

using namespace std;

map <string, int> press;
map <int, string> r_press;
int g[20][20];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
	string s;
	cin >> s;
	press[s] = i;
	r_press[i] = s;
    }
    for (int i = 0; i < m; i++) {
	string u, v;
	cin >> u >> v;
	g[press[u]][press[v]] = 1;
	g[press[v]][press[u]] = 1;
    }
    int limit = (1 << n);
    vector <string> ans;
    bool good = false;
    for (int mask = 0; mask < limit; mask++) {
	good = true;
	for (int i = 0; i < n; i++) 
	    for (int j = i + 1; j < n; j++) 
		if ((mask & (1 << i)) && (mask & (1 << j)) && g[i][j])
		    good = false;
	if (!good) continue;
	vector <string> res;
	for (int i = 0; i < n; i++)
	    if ((mask & (1 << i)))
		res.push_back(r_press[i]);
	if (res.size() > ans.size())
	    ans = res;
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
	cout << ans[i] << endl;
}