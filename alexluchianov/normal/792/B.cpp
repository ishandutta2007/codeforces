#include <iostream>
#include <vector>

using namespace std;
vector <int> v;
int main()
{
  int n ,k;
  cin>>n>>k;
  for(int i = 1  ;i <= n ;i++){
    v.push_back(i);
  }
  int x = 0;
  int y = 0;
  for(int i = 0 ; i < k ;i++){
    cin>>y;
    x = (x + y) % n;
    cout<<v[x]<<" ";
    n--;
    v.erase(v.begin() + x);
    x = x % n;
  }
  return 0;
}