#include <iostream>
#include <string>
#include <vector>

using namespace std;

class node {
  vector<node*> children;
  int depth;
 
public:
  node (int _depth) {
    children = vector<node*> (26, nullptr);
    depth = _depth;
    // cout << this << endl;
  }

  void add (string *s) {
    if (depth < (int) s->size()) {
      if (children[s->at(depth) - 'a'] == nullptr) {
        children[s->at(depth) - 'a'] = new node (depth + 1);
      }

      children[s->at(depth) - 'a']->add(s);
    }
  }

  bool dfs (bool wannawin) {
    int childc = 0;
    
    for (int i = 0; i < 26; i++) {
      if (children[i] != nullptr) {
        childc++;
      }
    }

    if (childc == 0) {
      return !wannawin;
    }

    for (int i = 0; i < 26; i++) {
      if (children[i] != nullptr) {
        if (!(children[i]->dfs(wannawin))) {
          return true;
        }
      }
    }

    return false;
  }
};

int main () {
  int stringc, gamec;
  cin >> stringc >> gamec;

  node root (0);
  for (int i = 0; i < stringc; i++) {
    string s;
    cin >> s;

    root.add(&s);
  }

  bool winnable = root.dfs(1), losable = root.dfs(0);
  // cout << winnable << " " << losable << endl;

  if (losable) {
    if (winnable) {
      cout << "First" << endl;
    } else {
      cout << "Second" << endl;
    }
  } else {
    if (winnable) {
      if (gamec % 2 == 0) {
        cout << "Second" << endl;
      } else {
        cout << "First" << endl;
      }
    } else {
      cout << "Second" << endl;
    }
  }
}