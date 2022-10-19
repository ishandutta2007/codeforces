#include <bits/stdc++.h>
using namespace std;

// https://cp-algorithms.com/string/prefix-function.html
vector<int> prefix_function(string& s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

const int K = 26;

string s;
vector<int> pf;

struct node {
  node* children[K]{};
  int val;
  node* parent = nullptr;
  node* push(char c) {
    int d = c-'a';
    int i = (int)s.size();
    s += c;
    if (children[d] != nullptr) {
      pf.push_back(children[d]->val);
      return children[d];
    }
    int j = pf.back();
    while (j > 0 && s[i] != s[j]) {
      j = pf[j-1];
    }
    if (s[i] == s[j]) j++;
    pf.push_back(j);
    children[d] = new node();
    children[d]->val = j;
    children[d]->parent = this;
    return children[d];
  }
  node* pop() {
    s.pop_back();
    pf.pop_back();
    return parent;
  }
  ~node() {
    for (int i = 0; i < K; i++) {
      delete children[i];
    }
  }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> s;
  int n = (int)s.size();
  pf = prefix_function(s);

  node* root = new node();

  int q;
  cin >> q;
  while (q--) {
    string t;
    cin >> t;
    int m = (int)t.size();
    for (char c: t) {
      root = root->push(c);
    }
    for (int i = n; i < n+m; i++) {
      cout << pf[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < m; i++) {
      root = root->pop();
    }
  }
}