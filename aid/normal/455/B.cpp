#include <iostream>
#include <string>

using namespace std;

const int SIGMA = 30;

struct Node {
    int go[SIGMA], gr, gr0;
    char mex[SIGMA];
};

const int MAXN = 100 * 1000 + 5;
Node trie[MAXN];
int freen = 0;

int newNode() {
    for(int i = 0; i < SIGMA; i++)
        trie[freen].go[i] = -1;
    return freen++;
}

void add(string &s) {
    int v = 0;
    for(size_t i = 0; i < s.length(); i++) {
        if(trie[v].go[s[i] - 'a'] == -1)
            trie[v].go[s[i] - 'a'] = newNode();
        v = trie[v].go[s[i] - 'a'];
    }
}

void dfs(int v) {
    bool leaf = true;
    for(int i = 0; i < SIGMA; i++)
        if(trie[v].go[i] != -1) {
            leaf = false;
            dfs(trie[v].go[i]);
            if(trie[trie[v].go[i]].gr < SIGMA)
                trie[v].mex[trie[trie[v].go[i]].gr] = true;
        }
    while(trie[v].mex[trie[v].gr])
        trie[v].gr++;
    if(leaf)
        trie[v].gr0 = 1;
    else {
        for(int i = 0; i < SIGMA; i++)
            trie[v].mex[i] = false;
        for(int i = 0; i < SIGMA; i++)
            if(trie[v].go[i] != -1)
                if(trie[trie[v].go[i]].gr0 < SIGMA)
                    trie[v].mex[trie[trie[v].go[i]].gr0] = true;
        while(trie[v].mex[trie[v].gr0])
            trie[v].gr0++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    newNode();
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        add(s);
    }
    dfs(0);
    if(trie[0].gr) {
        if(trie[0].gr0)
            cout << "First\n";
        else if(k & 1)
            cout << "First\n";
        else
            cout << "Second\n";
    }
    else
        cout << "Second\n";
    return 0;
}