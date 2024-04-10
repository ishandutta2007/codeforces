#include <iostream>
#include <map>
#include <cstring>
#include <cassert>
#include <string>

#define lint long long int
using namespace std;

const int NMAX = 100000 + 5;

struct State {
    int len, link;
    int cnt, dp;
    bool vis;
    int trans[26];
} states[2 * NMAX];

int sz, last;
void init() {
    sz = last = 0;
    memset(states, 0, sizeof states);
    states[0].link = -1;
}

void addLetter(int letter) {
    int current = ++ sz;
    states[current].len = states[last].len + 1;

    int p;
    for (p = last; p != -1 && !states[p].trans[letter]; p = states[p].link)
        states[p].trans[letter] = current;

    if (p != -1) {
        int q = states[p].trans[letter];

        if (states[p].len + 1 == states[q].len)
            states[current].link = q;
        else {
            int clone = ++ sz;

            states[clone] = states[q];
            states[clone].len = states[p].len + 1;

            for (; p != -1 && states[p].trans[letter] == q; p = states[p].link)
                states[p].trans[letter] = clone;
            states[q].link = states[current].link = clone;
        }
    }

    last = current;
}

void dfs(int node) {
    if (states[node].vis)
        return ;
    states[node].vis = true;

    for (int i = 0; i < 26; ++ i)
        if (states[node].trans[i]) {
            dfs(states[node].trans[i]);
            states[node].dp += states[states[node].trans[i]].dp;
        }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int T = 0;
    cin >> T;
    while (T --) {
        string str;
        cin >> str;
        init();
        for (auto it: str)
            addLetter(it - 'a');

        for (int i = 1; i <= sz; ++ i) {
            assert(states[i].link != -1);
            states[i].cnt = states[i].len - states[states[i].link].len;
        }

        int node = last;
        while (node) {
            states[node].dp = 1;
            node = states[node].link;
        }

        dfs(0);

        long long int ans = 0;
        for (int i = 1; i <= sz; ++ i) {
            //cout << i <<  ' ' << states[i].cnt << ' ' << states[i].dp << '\n';
            ans += 1LL * states[i].cnt * states[i].dp * states[i].dp;
        }

        cout << ans << '\n';
    }
    return 0;
}