#include <iostream>
#include <set>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;
using ld = long double;

int const nmax = 1000000;
int const sigma = 26;

struct Node{
  int id;
  Node* sons[sigma];
  Node(int id_ = 0){
    id = id_;
    for(int i = 0; i < sigma; i++)
      sons[i] = NULL;
  }
};
Node* v[5 + nmax];
int dp[5 + nmax], order[5 + nmax], seen[5 + nmax];
multiset<int> myset, myset2;

int ptr = 0;

void dfs(Node* root, int level){
  if(root->id == 0){
    myset.insert(-level);
    myset2.insert(-order[root->id]);
    for(int h = 0; h < sigma; h++)
      if(root->sons[h] != NULL)
        dfs(root->sons[h], level + 1);

  } else {
    dp[root->id] = level + *myset.begin();
    if(0 < seen[root->id]) {
      order[root->id] = ++ptr;
      dp[root->id] = min(dp[root->id] , ptr  + *myset2.begin());
    } else
      order[root->id] = ptr;

    myset.insert(dp[root->id] - level);
    myset2.insert(dp[root->id] - order[root->id] + (0 < seen[root->id]) );

    for(int h = 0; h < sigma; h++)
      if(root->sons[h] != NULL)
        dfs(root->sons[h], level + 1);

    myset.erase(myset.find(dp[root->id] - level));
    myset2.erase(myset2.find(dp[root->id] - order[root->id] + (0 < seen[root->id])));
  }
}
int el[5 + nmax];

int main()
{
  int n, k;
  cin >> n;
  v[0] = new Node(0);

  for(int i = 1;i <= n; i++){
    int father;
    char ch;
    cin >> father >> ch;
    v[father]->sons[ch - 'a'] = new Node(i);
    v[i] = v[father]->sons[ch - 'a'];
  }
  cin >> k;
  for(int i = 1;i <= k; i++){
    cin >> el[i];
    seen[el[i]] = i;
  }
  dfs(v[0], 1);
  for(int i = 1;i <= k; i++)
    cout << dp[el[i]] << " ";
  return 0;
}