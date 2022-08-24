#include <bits/stdc++.h>

using namespace std;

map <string, int> g;

int main() {
    string s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
	cin >> s;
	g[s] = i;
    }
    vector <pair <int, string> > f;
    for (auto s : g)
	f.push_back({s.second, s.first});
    sort(f.begin(), f.end());
    for (int i = f.size() - 1; i >= 0; i--)
	cout << f[i].second << endl;
}