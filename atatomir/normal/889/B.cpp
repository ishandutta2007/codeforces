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

#define maxCh 33

int n, i, j, id1, id2;
string s;
int go[maxCh];
bool us[maxCh];
string ans;
bool is_in[maxCh];
bool is_start[maxCh];


void no_sol() {
    cout << "NO";
    exit(0);
}

void dfs(int i) {
    ans.pb('a' + i);
    us[i] = true;

    if (go[i] == -1) return;
    if (us[go[i]]) no_sol();
    dfs(go[i]);
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n;
    for (i = 0; i < maxCh; i++)
        go[i] = -1;

    for (i = 1; i <= n; i++) {
        cin >> s;
        is_start[s[0] - 'a'] = true;

        for (j = 0; j + 1 < s.size(); j++) {
            id1 = s[j] - 'a';
            id2 = s[j + 1] - 'a';

            if (go[id1] != -1 && go[id1] != id2)
                no_sol();

            go[id1] = id2;
            is_in[id2] = true;
        }
    }

    for (i = 0; i < 26; i++) {
        if (us[i]) continue;
        if (!is_start[i]) continue;
        if (is_in[i]) continue;

        dfs(i);
    }

    for (i = 0; i < 26; i++) {
        if (is_start[i] && !us[i])
            no_sol();
    }

    cout << ans;


    return 0;
}