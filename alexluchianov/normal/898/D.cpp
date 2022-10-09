#include <iostream>
#include <fstream>
#include <deque>
#include <algorithm>

using namespace std;
int const nmax = 200000;
int v[5 + nmax];
int main()
{
  int n ,m , k;
  cin>>n>>m>>k;
  deque<int>q;
  for(int i = 1 ; i <= n ;i++){
    cin>>v[i];
  }
  sort(v + 1 , v + n + 1);
  int sum = 0;
  for(int i = 1 ; i <= n ;i++){
    q.push_back(v[i]);
    while(q.front() <= v[i] - m){
      q.pop_front();
    }
    while(k <= q.size()){
      q.pop_back();
      sum++;
    }
  }
  cout<<sum;
  return 0;
}