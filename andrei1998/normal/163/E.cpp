#include <iostream>
#include <cassert>
#include <cstdio>
#include <string>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

const int LENMAX = 1E6 + 15;
const int NMAX = 1E5 + 15;

struct State {
    int trans[26];
    int father;
    char fatherLit;
    int fail;
    int h;
    bool word;
    bool active;

    State(int _father = 0, char _fatherLit = '.', int _fail = 0, int _h = 0): father(_father), fatherLit(_fatherLit), fail(_fail), h(_h) {
        memset(trans, 0, sizeof trans);
        word = false;
        active = false;
    }
} states[LENMAX];

int N, K;

int sz;
int nodeOfString[NMAX];

int add(const string &str) {
    int node = 1;
    for (auto it: str) {
        if (!states[node].trans[it - 'a']) {
            states[node].trans[it - 'a'] = ++ sz;
            states[sz] = State(node, it, 0, 1 + states[node].h);
        }
        node = states[node].trans[it - 'a'];
    }

    states[node].word = true;
    return node;
}

vector <int> tree[LENMAX];

void build() {
    queue <int> q;
    q.push(1);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (states[node].h <= 1)
            states[node].fail = 1;
        else {
            int k = states[states[node].father].fail;
            while (k > 1 && !states[k].trans[states[node].fatherLit - 'a'])
                k = states[k].fail;

            if (states[k].trans[states[node].fatherLit - 'a'])
                k = states[k].trans[states[node].fatherLit - 'a'];
            states[node].fail = k;
        }

        if (node != 1)
            tree[states[node].fail].push_back(node);
        for (int i = 0; i < 26; ++ i)
            if (states[node].trans[i])
                q.push(states[node].trans[i]);
    }
}

int first[LENMAX];
int last[LENMAX];
int cnt;

void dfs(int node) {
    first[node] = ++ cnt;
    for (auto it: tree[node])
        dfs(it);
    last[node] = ++ cnt;
}

inline int lsb(int node) {
    return node & (-node);
}

typedef long long int lint;
lint aib[2 * LENMAX];

void add(int where, int val) {
    assert(cnt == 2 * sz);
    for (; where <= cnt; where += lsb(where))
        aib[where] += val;
}

lint query(int where) {
    lint ans = 0;
    for (; where; where -= lsb(where))
        ans += aib[where];
    return ans;
}

void include(int who) {
    int node = nodeOfString[who];
    if (!states[node].active) {
        add(first[node], 1);
        add(last[node], -1);
        states[node].active = true;
    }
}

void exclude(int who) {
    int node = nodeOfString[who];
    if (states[node].active) {
        add(first[node], -1);
        add(last[node], 1);
        states[node].active = false;
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    //freopen("data.in", "r", stdin);
    //cout << sizeof(states) / 1024 / 1024 << endl;

    cin >> N >> K;

    sz = 1;
    for (int i = 1; i <= K; ++ i) {
        string str;
        cin >> str;
        nodeOfString[i] = add(str);
    }

    build();
    dfs(1);

    for (int i = 1; i <= K; ++ i)
        include(i);

    /*for (int i = 1; i <= sz; ++ i) {
        cout << i << ' ' << states[i].h << ' '<< states[i].father << ' ' << states[i].fatherLit << ' ' << states[i].fail << endl;
    }*/

    while (N --) {
        char type;
        cin >> type;

        if (type == '?') {
            string str;
            cin >> str;

            lint ans = 0;
            int node = 1;
            for (auto it: str) {
                while (node > 1 && !states[node].trans[it - 'a'])
                    node = states[node].fail;
                if (states[node].trans[it - 'a'])
                    node = states[node].trans[it - 'a'];
                ans += query(first[node]);
            }

            cout << ans << '\n';
        }
        else if (type == '+') {
            int nr;
            cin >> nr;
            include(nr);
        }
        else {
            int nr;
            cin >> nr;
            exclude(nr);
        }
    }

    return 0;
}