#include <iostream>
#include <algorithm>

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int const lim = 1000000000;

struct Ring{
  int inner;
  int outer;
  ll h;
  bool operator < (Ring const &a) const{
    if(outer != a.outer)
      return a.outer < outer;
    else
      return a.inner < inner;
  }
};

Ring v[5 + nmax];

int n;

struct Tree{
  ll val;
  Tree* left;
  Tree* right;
  Tree() {}
  Tree(ll val){
    this->val = val;
    left = nullptr;
    right = nullptr;
  }
  void computenode(){
    val = 0;
    if(left != nullptr)
      val = MAX(val , left->val);

    if(right != nullptr)
      val = MAX(val , right->val);
  }
};

void update(Tree* &node ,int from , int to , int x , ll val){
  if(node == nullptr)
    node = new Tree(0);

  if(from < to){

    int mid = ((from + to) >> 1);
    if(x <= mid)
      update(node->left , from , mid , x , val);
    else
      update(node->right , mid + 1 , to , x , val);
    node->computenode();

  } else
    node->val = MAX(node->val ,val);
}

ll query(Tree* &node , int from , int to , int x , int y){
  if(y < x)
    return 0;

  if(node == nullptr)
    node = new Tree(0);

  if((from == x && to == y) || node->val == 0){
    return node -> val;
  } else {
    ll result = 0;
    int mid = (from + to) / 2;
    if(x <= mid){
      ll partresult = query(node->left , from , mid , x , MIN(mid , y));
      result = MAX(result , partresult);
    }
    if(mid + 1 <= y){
      ll partresult = query(node->right , mid + 1 , to , MAX(x , mid + 1) , y);
      result = MAX(result , partresult);
    }
    return result;
  }
}

int main()
{
  std::cin >> n;
  for(int i = 1 ; i <= n ; i++)
    std::cin >> v[i].inner >> v[i].outer >> v[i].h;
  std::sort(v + 1 , v + n + 1);
  Tree* root = new Tree(0);
  for(int i = 1 ; i <= n ; i++){
    ll val = query(root , 1 , lim , 1 , v[i].outer - 1);
    update(root , 1 , lim , v[i].inner , val + v[i].h);
  }
  std::cout << query(root , 1 , lim , 1 , lim);

  return 0;
}