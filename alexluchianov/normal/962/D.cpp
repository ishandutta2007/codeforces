#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX(a , b) (((a) < (b)) ? (b) : (a))
#define ll long long

struct T{
  ll val;
  int pos;
  bool operator < (T const a) const {
    if(a.val != val)
      return val > a.val;
    else
      return pos > a.pos;
  }
};

vector<T> v;

int compare(T a , T b){
  return a.pos < b.pos;
}

int main()
{
  int n;
  cin >> n;
  priority_queue<T> pq;
  for(int i = 1 ; i <= n ; i++){
    int a;
    cin >> a;
    pq.push({a , i});
  }
  while(1 < pq.size()){
    T a = pq.top();
    pq.pop();
    T b = pq.top();
    pq.pop();
    if(a.val == b.val)
      pq.push({a.val + b.val ,MAX(a.pos , b.pos)});
    else {
      v.push_back(a);
      pq.push(b);
    }
  }
  v.push_back(pq.top());
  pq.pop();

  sort(v.begin() , v.end() , compare);
  cout << v.size()  << '\n';

  for(int i = 0 ; i < v.size() ; i++)
    cout << v[i].val << " ";

  return 0;
}