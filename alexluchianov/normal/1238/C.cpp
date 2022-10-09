#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
  int h, n;
  cin >> h >> n;
  vector<int> v;
  for(int i = 1;i <= n; i++){
    int a;
    cin >> a;
    v.push_back(a);
  }

  v.push_back(0);
  sort(v.begin(), v.end());

  int result = 0;
  //daca ajung la o platforma(mai am una imaginara) castig clar
  while(2 < v.size()){
    int a = v.back();
    v.pop_back();
    if(v.back() + 1 == a){
      v.pop_back();
      if(0 < v.size() && v.back() + 2 == a)
        continue;
      else {
        result++;
        v.push_back(a - 2);
      }
    } else
      v.push_back(v.back() + 1);
  }
  cout << result << '\n';
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();

  return 0;
}