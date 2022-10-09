#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;

struct Trie{
  int exist;
  Trie* son[2];
Trie(){
  exist = 0;
  son[0] = son[1] = nullptr;
}
};
Trie *root;

void update(Trie* node, ll key, int p){
  node->exist = 1;
  if(0 <= p){
    int bit = (0 < (key & (1LL << p)));
    if(node->son[bit] == nullptr)
      node->son[bit] = new Trie();
    update(node->son[bit], key, p - 1);
  }
}

ll query(Trie* node, ll key, int p){
  if(0 <= p){
    int bit = (0 < (key & (1LL << p)));
    if(node->son[!bit] != nullptr) {
      return (1LL << p) + query(node->son[!bit], key, p -1);
    } else
      return query(node->son[bit], key, p - 1);
  } else
    return 0;
}
ll v[1 + nmax];

int main()
{
  root = new Trie();
  update(root, 0, 40);
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++) {
    cin >> v[i];
    v[i] ^= v[i - 1];
  }
  ll result = 0;
  for(int i = 0;i <= n; i++) {
    update(root, v[i], 40);
    result = max(result, query(root, v[n] ^ v[i], 40));
  }
  cout << result;
  return 0;
}