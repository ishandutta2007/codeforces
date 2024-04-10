#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 2000000;
int sol[1 + nmax];

int checkandpass(int ptr){
  if(0 != sol[ptr] / 2) {
    sol[ptr + 1] += sol[ptr] / 2;
    sol[ptr] %= 2;
    return 1;
  }
  return 0;
}

bool normalize(int &lim){
  bool change = 0;
  for(int i = 0; i < lim; i++){
    change |= checkandpass(i);
    change |= checkandpass(i + 1);

    if(sol[i] == 1 && sol[i + 1] == 1) {
      sol[i] = -1;
      sol[i + 1] = 0;
      sol[i + 2]++;
      change = 1;
    } else if(sol[i] == -1 && sol[i + 1] == -1){
      sol[i] = 1;
      sol[i + 1] = 0;
      sol[i + 2]--;
      change = 1;
    }
    if(sol[i] == 1 && sol[i + 1] == -1){
      sol[i] = -1;
      sol[i + 1] = 0;
      change = 1;
    }
    if(sol[i] == -1 && sol[i + 1] == 1){
      sol[i] = 1;
      sol[i + 1] = 0;
      change = 1;
    }

    while(0 < sol[lim] || 0 < sol[lim + 1])
      lim++;
  }
  return change;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  reverse(s.begin(), s.end());
  for(int i = 0; i < n; i++)
    if(s[i] == '1')
      sol[i] = 1;
  int lim = n - 1;
  while(normalize(lim));
  int result = 0;

  for(int i = 0; i <= lim; i++)
    if(sol[i] != 0)
      result++;


  cout << result << '\n';
  for(int i = 0; i <= lim; i++)
    if(0 < sol[i])
      cout << "+2^"<< i << '\n';
    else if(sol[i] < 0)
      cout << "-2^"<< i << '\n';

  return 0;
}