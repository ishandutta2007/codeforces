#include<bits/stdc++.h>
using namespace std;

const int MAX = 100500;

int trie[MAX][26];
int szT = 0;

int newT() {
    return ++szT;
}

int n, k, root;
bool win[MAX], lose[MAX];

void addTrie(const string& s) {
    int v = root;
    for (int i = 0; i < s.length(); i++) {
        int c = s[i] - 'a';
        if (trie[v][c] == 0){
            trie[v][c] = newT();
        }
        v = trie[v][c];
    }
}

void dfs(int v) {
    win[v] = false;
    lose[v] = false;
    bool isLeaf = true; //
    for (int i = 0; i <26; i++) {
        if (trie[v][i] != 0) {
            isLeaf = false;
            int to = trie[v][i];
            dfs(to);
            win[v] |= !win[to];
            lose[v] |= !lose[to];
        }
    }
    if (isLeaf) {
        lose[v] = true;
    }
}

int main() {
    cin >> n >> k;
    root = newT();
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        addTrie(s);
    }
    dfs(root);
    if(win[root] == false){
        cout << "Second";
    }
    else if(win[root] == true && lose[root] == true){
        cout << "First";
    }
    else if(k %2 == 1){
        cout << "First";
    }
    else{
        cout << "Second";
    }
    return 0;
}