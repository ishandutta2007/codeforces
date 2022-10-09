#include <iostream>
#include <set>

using namespace std;

using ll = long long;

int const sigma = 26;


void addset(multiset<int> &orig, multiset<int> &guest){
  if(orig.size() < guest.size())
    swap(orig, guest);

  for(multiset<int>::iterator it = guest.begin(); it != guest.end(); it++)
    orig.insert(*it);
}

namespace Trie{
  struct Node{
    int scount;
    Node* sons[sigma];
    Node(int val){
      scount = val;
      for(int i = 0; i < sigma; i++)
        sons[i] = NULL;
    }
  };
  void _insert(Node* &root, string& s, int k){
    if(root == NULL)
      root = new Node(0);
    if(s.size() == k)
      root->scount++;
    else
      _insert(root->sons[s[k] - 'a'], s, k + 1);
  }

  multiset<int> solve(Node* &root,ll &result, int level){
    multiset<int> myset;

    for(int i = 0; i < sigma; i++){
      multiset<int> newp;
      if(root->sons[i] != NULL)
        newp = solve(root->sons[i], result, level + 1);
      addset(myset, newp);
    }

    if(0 < level){
      if(root->scount == 0) {
        multiset<int>::iterator it = myset.end();
        it--;
        result -= *it;
        myset.erase(it);
        myset.insert(level);
        result += level;
      } else {
        myset.insert(level);
        result += level;
      }
    }
    return myset;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  Trie::Node* root = NULL;
  for(int i = 1;i <= n; i++){
    string s;
    cin >> s;
    Trie::_insert(root, s, 0);
  }
  ll result = 0;
  Trie::solve(root, result, 0);
  cout << result << '\n';
  return 0;
}