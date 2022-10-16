#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int SIGMA = 26;

struct Node {
    int go[SIGMA], t;
};

const int MAXN = 10 * 1000 + 5, MAXLEN = 1000 * 1000 + 5;
Node trie[MAXLEN];
int p[MAXN], freeNode;
string w[MAXLEN], s;

int newNode() {
    for(int i = 0; i < SIGMA; i++)
        trie[freeNode].go[i] = -1;
    trie[freeNode].t = -1;
    return freeNode++;
}

void add(const string &s, int id) {
    int v = 0;
    for(size_t i = 0; i < s.length(); i++) {
        char c = s[i];
        if('A' <= c && c <= 'Z')
            c ^= 32;
        if(trie[v].go[c - 'a'] == -1)
            trie[v].go[c - 'a'] = newNode();
        v = trie[v].go[c - 'a'];
    }
    trie[v].t = id;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> s >> m;
    for(int i = 0; i < m; i++)
        cin >> w[i];
    reverse(s.begin(), s.end());
    newNode();
    for(int i = 0; i < m; i++)
        add(w[i], i);
    for(int i = 0; i <= n; i++)
        p[i] = -1;
    p[0] = 0;
    for(int i = 0; i < n; i++) {
        if(p[i] == -1)
            continue;
        int v = 0;
        for(int j = i; j < n; j++) {
            if(trie[v].go[s[j] - 'a'] == -1)
                break;
            v = trie[v].go[s[j] - 'a'];
            if(trie[v].t != -1)
                p[j + 1] = trie[v].t;
        }
    }
    for(int i = n; i > 0; i -= (int)w[p[i]].length())
        cout << w[p[i]] << ' ';
    cout << '\n';
    return 0;
}