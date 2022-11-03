#include <bits/stdc++.h>
#define int ll
#define fir first
#define sec second
#define pb push_back
using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 100;
int answer;

vector<int> vec[MAX_N];

void dfs(int u, int len = 1) {
    answer = max(answer, len);
    for (auto i:vec[u])
        dfs(i, len + 1);
}

main() {
    int n;
    cin >> n;
    map<string, int> num;
    num["polycarp"] = 1;
    int last = 1;

    for (int i = 1; i <= n; i++) {
        string name2, name1;
        cin >> name2 >> name1 >> name1;
        for (auto &i:name2)
        if (i >= 'A' && i <= 'Z') {
            i -= 'A';
            i += 'a';
        }
        for (auto &i:name1)
        if (i >= 'A' && i <= 'Z') {
            i -= 'A';
            i += 'a';
        }
        num[name2] = ++last;
        vec[num[name1]].pb(last);
    }

    dfs(1);

    cout << answer;
}