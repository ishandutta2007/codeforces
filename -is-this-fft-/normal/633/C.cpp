#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX_WORD = 100005;
const int MAX_TEXT = 10005;

int decap (char c) {
  if (c == '$') {
    return 26;
  }
  if (c <= 'Z' && c != '$') {
    c += ('a' - 'A');
  }
  c -= 'a';
  return c;
}

struct node {
  int depth, val;
  node **children;

  node (int id) {
    depth = id;
    val = 0;
    children = new node* [27];
    for (int i = 0; i < 27; i++) {
      children[i] = nullptr;
    }
  }

  void add (string s, int v) {
    if (depth == s.size()) {
      val = v;
    } else if (depth < s.size()) {
      if (children[(decap(s[depth]))] == nullptr) {
	children[(decap(s[depth]))] = new node (depth + 1);
      }
      children[(decap(s[depth]))]->add(s, v);
    }
  }
};
      
string words [MAX_WORD];
int wordid [MAX_TEXT];

int main () {
  ios::sync_with_stdio(false);

  node *root = new node (0);

  int textl;
  string text;
  cin >> textl >> text;

  int wordc;
  cin >> wordc;
  for (int i = 0; i < wordc; i++) {
    cin >> words[i + 1];
    root->add(words[i + 1] + '$', i + 1);
  }

  wordid[textl] = -1;
  node *cur = root;
  for (int i = textl - 1; i >= 0; i--) {
    if (wordid[i + 1]) {
      cur = root;
      for (int j = i; j >= 0; j--) {
	cur = cur->children[decap(text[j])];
	if (cur == nullptr) {
	  break;
	}
	if (cur->children[decap('$')] != nullptr) {
	  wordid[j] = cur->children[decap('$')]->val;
	}
      }
    }
  }

  vector<int> ans (0);
  int ptr = 0;
  while (ptr < textl) {
    ans.push_back(wordid[ptr]);
    ptr += words[wordid[ptr]].size();
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << words[ans[i]] << (i + 1 == ans.size() ? '\n' : ' ');
  }
}