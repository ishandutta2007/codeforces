#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 111

int n, i, j;
string s[maxN];
vector<int> list[maxN];
bool us[maxN];
vector<int> ord;
char to[maxN];

void dfs(int node) {
    us[node] = true;
    for (auto to : list[node])
        if (!us[to])
            dfs(to);
    ord.pb(node);
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n;
    for (i = 1; i <= n; i++) cin >> s[i];
    for (i = 1; i < n; i++) {
        for (j = 0; j < s[i].size() && j < s[i + 1].size(); j++)
            if (s[i][j] != s[i + 1][j])
                break;

        if (j < s[i].size() && j < s[i + 1].size()) {
            list[s[i][j] - 'a'].pb(s[i + 1][j] - 'a');
        }
    }

    for (i = 0; i < 26; i++)
        if (!us[i])
            dfs(i);

    reverse(ord.begin(), ord.end());
    for (i = 0; i < 26; i++)
        to[ord[i]] = 'a' + i;

    for (i = 1; i <= n; i++)
        for (auto& c : s[i])
            c = to[c - 'a'];

    for (i = 1; i < n; i++) {
        if (s[i] <= s[i + 1]) continue;
        printf("Impossible\n");
        return 0;
    }


    for (auto e : ord) printf("%c", 'a' + e);
    //for (i = 0; i < 26; i++) printf("%c", to[i]);




    return 0;
}