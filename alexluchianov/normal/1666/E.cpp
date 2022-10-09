#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

int const nmax = 100000;
int orig[5 + nmax], v[5 + nmax];

bool makeSplit(int n, int limitX, int limitY) {
  int currX = v[0], currY = v[0];//what can I get from previous person

  for(int i = 1;i <= n; i++) {
    //what values can I receive from the next block
    if(currX <= currY) { 
      int newX = std::max(0, limitX - currY);
      int newY = limitY - currX;

      if(newX <= newY) {
        //what can i pass forward
        currX = std::max(0, v[i] - newY);
        currY = v[i] - newX;
      } else
        return false;
    } else
      return false;
  }

  return currX <= 0 && 0 <= currY;

  return true;
}

int print(int n, int pos, int limitX, int limitY, int currX, int currY, std::vector<std::pair<int,int>> &sol) {
  if(pos <= n) {
    //what values can I receive from the next block

    int newX = std::max(0, limitX - currY);
    int newY = limitY - currX;

    if(newX <= newY) {
      //what can i pass forward
      int newcurrX = std::max(0, v[pos] - newY);
      int newcurrY = v[pos] - newX;

      int val = v[pos] - print(n, pos + 1, limitX, limitY, newcurrX, newcurrY, sol);
      int returnval = std::max(currX, limitX - val);
      sol.push_back({orig[pos] - returnval, orig[pos] + val});
      return returnval;
    } else {
      return -1;
      assert(1 == 0);
    }
  } else {
    assert(currX <= 0 && 0 <= currY);
    return 0;
  }
}


int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int total, n;
  std::cin >> total >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> orig[i];
  orig[n + 1] = total;
  for(int i = 0;i <= n; i++)
    v[i] = orig[i + 1] - orig[i];
    
  int solX = 0, solY = total;
  for(int jump = (1 << 30); 0 < jump; jump /= 2) {
    if(solX + jump <= solY && makeSplit(n, solX + jump, solY))
      solX += jump;
  }
  for(int jump = (1 << 30); 0 < jump; jump /= 2)
    if(solX + jump <= solY && makeSplit(n, solX, solY - jump))
      solY -= jump;
  std::vector<std::pair<int,int>> sol;

  print(n, 1, solX, solY, v[0], v[0], sol);
  std::reverse(sol.begin(), sol.end());

  for(int i = 0; i < sol.size(); i++)
    std::cout << sol[i].first << " " << sol[i].second << '\n';
  return 0;
}