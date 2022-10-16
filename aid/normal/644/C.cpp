#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int MAXN = 100 * 1000 + 5;
unordered_map<string, int> ids;
string names[MAXN];
vector<string> paths[MAXN];
unordered_map<string, vector<int> > ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int m = 0;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        s = s.substr(7);
        size_t j = 0;
        while(j < s.length() && s[j] != '/')
            j++;
        string name = s.substr(0, j), path = s.substr(j);
        if(ids.find(name) == ids.end()) {
            names[m] = name;
            ids[name] = m++;
        }
        paths[ids[name]].push_back(path);
    }
    for(int i = 0; i < m; i++) {
        sort(paths[i].begin(), paths[i].end());
        paths[i].erase(unique(paths[i].begin(), paths[i].end()), paths[i].end());
        string s;
        for(size_t j = 0; j < paths[i].size(); j++) {
            s += paths[i][j];
            s += '#';
        }
        ans[s].push_back(i);
    }
    int cnt = 0;
    for(unordered_map<string, vector<int> >::iterator it = ans.begin();
        it != ans.end(); it++)
        if(it->second.size() > 1)
            cnt++;
    cout << cnt << '\n';
    for(unordered_map<string, vector<int> >::iterator it = ans.begin();
        it != ans.end(); it++)
        if(it->second.size() > 1) {
            for(size_t i = 0; i < it->second.size(); i++)
                cout << "http://" << names[it->second[i]] << ' ';
            cout << '\n';
        }
    return 0;
}