#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

string s, emp;

ll getmin(int days, ll start){
  return days * start;
}

ll getmax(ll days, ll start){
  ll result = 0;
  for(int i = 1;i <= days; i++, start *= 2)
    result += start;
  return result;
}

vector<int> sol;

void extract(ll start, int nec, ll total){
  if(nec == 0)
    return ;
  for(int jump = (1 << 30); 0 < jump; jump /= 2)
    if(getmax(nec, start + jump) < total)
      start += jump;

  while(getmax(nec, start) < total)
    start++;
  sol.push_back(start);
  extract(start, nec - 1, total - start);
}

void solve(){
  int n;
  cin >> n;
  sol.clear();
  int nec = 1;
  while(getmax(nec, 1) < n)
    nec++;
  extract(1, nec, n);
  cout << sol.size() - 1 << '\n';

  for(int i = 1; i < sol.size(); i++)
    cout << sol[i] - sol[i - 1] << " ";
  cout << '\n';
}

int main()
{
  /*
  ios::sync_with_stdio(0);
  cin.tie(0);
  */


  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}
/*
1
1000000000
*/