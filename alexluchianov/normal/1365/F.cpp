#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using ll = long long;

int const nmax = 500;
int v[1 + nmax], v2[1 + nmax];
std::map<std::pair<int,int>, int> mp;

std::pair<int,int> repair(std::pair<int,int> nod){
  if(nod.second < nod.first)
    std::swap(nod.first, nod.second);
  return nod;
}

bool solve(){
  int n;
  std::cin >> n;
  mp.clear();
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  for(int i = 1;i <= n; i++)
    std::cin >> v2[i];
  if(n % 2 == 1 && v[n / 2 + 1] != v2[n / 2 + 1])
    return false;

  for(int i = 1; i <= n / 2; i++){
    mp[repair({v[i], v[n - i + 1]})]++;
    mp[repair({v2[i], v2[n - i + 1]})]--;
  }
  for(std::map<std::pair<int,int>, int>::iterator it = mp.begin(); it != mp.end(); it++)
    if(it->second != 0)
      return false;
  return true;
}

int main(){
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++){
    if(solve() == true)
      std::cout << "Yes\n";
    else
      std::cout << "No\n";
  }
}