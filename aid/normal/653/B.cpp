#include <iostream>
#include <unordered_set>

using namespace std;

const int MAXN = 10, MAXQ = 40;
pair<pair<char, char>, char> q[MAXQ];
unordered_set<string> st[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
        cin >> q[i].first.second >> q[i].first.first >> q[i].second;
    st[1].insert("a");
    for(int i = 1; i < n; i++)
        for(unordered_set<string>::iterator it = st[i].begin();
            it != st[i].end(); it++) {
            string s = *it;
            char c = s[(int)s.length() - 1];
            s.resize((int)s.length() - 1);
            for(int j = 0; j < m; j++)
                if(q[j].second == c)
                    st[i + 1].insert(s + q[j].first.first + q[j].first.second);
        }
    cout << st[n].size() << '\n';
    return 0;
}