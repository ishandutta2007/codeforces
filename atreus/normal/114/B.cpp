#include <bits/stdc++.h>

using namespace std;

vector <string> ans;
map <string, vector <string> > mp;
string s[30];
int n, m;

void checktrue(string a){
    vector <string> v;
    for (int i = 0; i < a.size(); i++)
        if (a[i] == '1')
            v.push_back(s[i]);
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v.size(); j++){
            for (int k = 0; k < mp[v[i]].size(); k++){
                if (mp[v[i]][k] == v[j]){
                    return;
                }
            }
        }
    }
    if (v.size() >= ans.size())
        ans = v;
    return;
}

void f(string a){
    if (a.size() == n){
        checktrue(a);
        return;
    }
    f(a + '0');
    f(a + '1');
}

int main() {
	ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < m; i++){
        string a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    string c;
    f(c);
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
}