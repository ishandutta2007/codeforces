#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 300000;
int const inf = 1000000000;

struct Line{
  int a ;
  ll b;
  inline ll eval(int point){
    return 1LL * a * point + b;
  }
};

struct Node{
  Line line;
  Node *left , *right;

  Node(Line line) {
    this->line = line;
    this->left = this->right = nullptr;
  }
};

void addline(Node* &root , int from , int to , Line line){
  if(root == nullptr) {
    root = new Node(line);
    return ;
  }
  int mid = (from + to) / 2 + 1;

  bool isbetterfrom = root->line.eval(from) < line.eval(from);
  bool isbettermid = root->line.eval(mid) < line.eval(mid);
  bool isbetterend = root->line.eval(to) < line.eval(to);

  if(isbetterend == 0 && isbetterfrom == 0)
    return ;

  if(isbetterfrom == 1 && isbettermid == 0)
    addline(root->left , from , mid - 1 , line);
  else if(isbetterfrom == 0 && isbettermid == 0)
    addline(root->right , mid , to , line);
  else{
    swap(root->line , line);
    if(isbetterfrom == 0 && isbettermid == 1)
      addline(root->left , from ,mid - 1 , line);
    else
      addline(root->right , mid , to , line);
  }
}

ll queryline(Node* &root , int from , int to , int x){
  if(root == nullptr)
    return 1LL * -inf * inf - inf;
  else{

    if(from == to){
      return root->line.eval(x);
    } else{
      int mid = (from + to) / 2 + 1;
      ll result = 0;
      if(x < mid)
        result = queryline(root->left , from , mid - 1 , x);
      else
        result = queryline(root->right , mid , to , x);
      ll result2 = root->line.eval(x);
      return MAX(result , result2);

    }
  }
}

struct SupremeAint{
  Node *root;
  SupremeAint *left , *right;

  SupremeAint(){
    this->root = nullptr;
    this->left = this->right = nullptr;
  }
};

void update(SupremeAint* &root , int from , int to , int x , int y , Line line){
  if(root == nullptr)
    root = new SupremeAint();


  //cout <<"|";

  if(x == from && to == y) {
    addline(root->root , -inf , inf , line);
  } else{
    int mid = (from + to) / 2 + 1;
    if(x < mid)
      update(root->left , from , mid - 1 , x , MIN(y , mid - 1) , line);
    if(mid <= y)
      update(root->right , mid , to , MAX(x , mid) , y , line);
  }
}

ll query(SupremeAint* &root , int from , int to , int x , int timestamp){

  if(root == nullptr)
    return 1LL * -inf * inf - inf;
  else{
    int mid = (from + to) / 2 + 1;
    ll result = 0;
    if(timestamp < mid)
      result = query(root->left , from , mid - 1 ,x , timestamp);
    else
      result = query(root->right , mid , to , x , timestamp);


    ll result2 = queryline(root->root , -inf , inf , x);
    return MAX(result , result2);

  }
}

struct Query{
  int op;
  int a ;
  int b;
};

vector<Query> qp;
Line v[5 + nmax] ;
int vp = 0;
int start[5 + nmax];
int send[5 + nmax];

int sum[5 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  qp.push_back({0 , 0 , 0});

  for(int i = 1 ; i <= n ; i++){
    Query q;
    cin >> q.op;
    if(q.op == 1){
      cin >> q.a >> q.b;
      start[i] = i;
    } else if(q.op == 2){
      cin >> q.a;
      send[q.a] = i;
    } else if(q.op == 3)
      cin >> q.a;
    qp.push_back(q);
  }
  SupremeAint *root = nullptr;

  for(int i = 1 ; i <= n; i++) {
    if(qp[i].op == 1) {
      if(send[i] == 0)
        send[i] = n;

      update(root , 1 , n , start[i]  , send[i] , {qp[i].a , qp[i].b} );
    }
  }

  int sup = 0;

  for(int i = 1 ; i <= n ; i++){
    if(qp[i].op == 3) {
      if(sup == 0)
        cout << "EMPTY SET\n";
      else
        cout << query(root , 1 , n , qp[i].a , i) << '\n';
    } else if(qp[i].op == 1)
      sup++;
    else if(qp[i].op == 2)
      sup--;

  }

  return 0;
}