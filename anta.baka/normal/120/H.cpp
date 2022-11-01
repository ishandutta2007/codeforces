#include <bits/stdc++.h>

using namespace std;

int K;
vector < vector<int> > g;
vector<int> mt;
vector<char> used;

bool try_kuhn (int v) {
	if (used[v])  return false;
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (mt[to] == -1 || try_kuhn (mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    vector<string> t(n);
    vector<string> a;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        t[i] = s;
        int m = s.length();
        string cur;
        for(int i1 = 0; i1 < m; i1++) {
            cur += s[i1];
            a.push_back(cur);
            for(int i2 = i1+1; i2 < m; i2++) {
                cur += s[i2];
                a.push_back(cur);
                for(int i3 = i2+1; i3 < m; i3++) {
                    cur += s[i3];
                    a.push_back(cur);
                    for(int i4 = i3+1; i4 < m; i4++)
                        a.push_back(cur+s[i4]);
                    cur.pop_back();
                }
                cur.pop_back();
            }
            cur.pop_back();
        }
    }
    sort(a.begin(),a.end());
    unique(a.begin(),a.end());
    map<string,int> pos;
    K = a.size();
    for(int i = 0; i < K; i++)
        pos[a[i]] = i;
    g.resize(n);
    for(int i = 0; i < n; i++) {
        string s = t[i];
        int m = s.length();
        string cur;
        for(int i1 = 0; i1 < m; i1++) {
            cur += s[i1];
            g[i].push_back(pos[cur]);
            for(int i2 = i1+1; i2 < m; i2++) {
                cur += s[i2];
                g[i].push_back(pos[cur]);
                for(int i3 = i2+1; i3 < m; i3++) {
                    cur += s[i3];
                    g[i].push_back(pos[cur]);
                    for(int i4 = i3+1; i4 < m; i4++)
                        g[i].push_back(pos[cur+s[i4]]);
                    cur.pop_back();
                }
                cur.pop_back();
            }
            cur.pop_back();
        }
    }
	mt.assign (K, -1);
	for (int v=0; v<n; ++v) {
		used.assign (n, false);
		try_kuhn(v);
	}
    int cnt = 0;
	for (int i=0; i<K; ++i)
		if(mt[i] != -1)
            cnt++;
    if(cnt < n)
        return cout << -1, 0;
    vector<string> ans(n);
    for(int i = 0; i < K; ++i)
        if(mt[i] != -1)
            ans[mt[i]] = a[i];
    for(string w : ans)
        cout << w << "\n";
}