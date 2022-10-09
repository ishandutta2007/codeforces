#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

ll const nmax =   1000000;
ll const inf = 1000000000;

struct Square{
  ll x , y;
  ll cost;
  bool operator < (Square const &a) const{
    return x < a.x;
  }
};

Square v[5 + nmax];


ll dp[5 + nmax];

struct Line{
  ll x;
  ll y;
};

ll eval(Line a , ll point){
  return 1LL * point * a.x + a.y;
}
struct Node{
  Line line;
  Node *left , *right;

  Node (Line line){
    this->line = line;
    left = right = nullptr;
  }
};

void addline(Node* &node , int from , int to , Line line){
  if(node == nullptr) {
    node = new Node(line);
    return;
  }

  if(from == to){
    if(eval(node->line , from) < eval(line , from))
      node->line = line;
  } else {
    int mid = (from + to) / 2 + 1;

    bool evalfrom = eval(node->line , from) < eval(line , from);
    bool evalmid = eval(node->line , mid) < eval(line , mid);
    if(evalfrom == 0 && evalmid == 0)
      addline(node->right , mid , to , line);
    else if(evalfrom == 1 && evalmid == 0)
      addline(node->left , from , mid - 1 , line);
    else {
      swap(line , node->line);
      if(evalfrom == 0)
        addline(node->left , from , mid - 1 , line);
      else
        addline(node->right , mid , to , line);
    }
  }
}

ll query(Node* &node , int from , int to , int x){
  if(node == nullptr)
    return 0;

  if(from == to)
    return eval(node->line , x);
  else{
    int mid = (from + to) / 2 + 1;
    ll result = 0;

    if(x < mid)
      result = query(node->left , from , mid - 1 , x);
    else
      result = query(node->right , mid  , to , x);
    return MAX(result , eval(node->line , x) );
  }
}


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  Node* root;
  root = new Node({0 , 0});

  int n ;
  cin >> n;
  for(int i = 1 ; i <= n ; i++){
    cin >> v[i].x >> v[i].y >> v[i].cost;
  }
  sort(v + 1 , v + n + 1);
  ll result = 0;
  for(int i = 1; i <= n ; i++){
    dp[i] = v[i].x * v[i].y - v[i].cost + query(root , 1 , inf , v[i].y);
    //cout << i << " " << dp[i] << " " << v[i].x << " " << v[i].y << "" '\n';
    //cout << dp[i] << " ";

    assert(0 <= dp[i]);

    addline(root , 1 , inf , {-v[i].x , dp[i]});
    result = MAX(result , dp[i]);
  }
  cout << result;

  return 0;
}