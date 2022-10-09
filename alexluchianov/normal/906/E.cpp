#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
char v[1 + nmax];
int gpl[1 + nmax], gpsuff[1 + nmax], dp[1 + nmax], suff[1 + nmax];

struct Club{
  int start;
  int delta;
  int length;
};

int main() {
  std::string s, s2;
  std::cin >> s >> s2;
  int n = s.size();
  for(int i = 0; i < s.size(); i++)
    v[1 + 2 * i] = s[i];
  for(int i = 0; i < s2.size(); i++)
    v[2 + 2 * i] = s2[i];
  n = 2 * n;
  for(int i = 0; i <= n; i++)
    dp[i] = gpl[i] = nmax;
  dp[0] = 0;

  std::vector<Club> g1;
  
  int last = -1;

  for(int i = 1;i <= n; i++) {
    std::vector<Club> aux, aux2;
    for(int j = 0; j < g1.size(); j++) {
      Club curr = g1[j];
      if(1 < curr.length) {
        aux.push_back({curr.start, curr.delta, 1});
        aux.push_back({curr.start + curr.delta, curr.delta, curr.length - 1});
      } else
        aux.push_back(curr);
    }
    
    for(int j = 0; j < aux.size(); j++) {
      if(1 < aux[j].start && v[aux[j].start - 1] == v[i]) {
        aux2.push_back({aux[j].start - 1, aux[j].delta, aux[j].length});
      }
    }
    if(1 < i && v[i - 1] == v[i])
      aux2.push_back({i - 1, 1, 1}); 
    g1.clear();
    last = -1;

    for(int j = 0; j < aux2.size(); j++) {
      if(last == -1)
        g1.push_back({aux2[j].start, nmax, aux2[j].length});
      else {
        if(g1.back().delta == aux2[j].start - last)
          g1.back().length += aux2[j].length;
        else
          g1.push_back({aux2[j].start, aux2[j].start - last, aux2[j].length});
      }
      last = aux2[j].start + (aux2[j].length - 1) * aux2[j].delta;
    }

    for(int j = 0; j < g1.size(); j++) {
      if(g1[j].delta == nmax) {
        if(dp[g1[j].start - 1] + 1 < dp[i]) {
          dp[i] = dp[g1[j].start - 1] + 1;
          suff[i] = g1[j].start;
        }
      } else {
        int pos = g1[j].start - g1[j].delta;
        int newpos = g1[j].start + (g1[j].length - 1) * g1[j].delta;
        if(g1[j].length == 1) {
          gpl[pos] = dp[g1[j].start - 1] + 1;
          gpsuff[pos] = g1[j].start;
        } else {
          if(dp[newpos - 1] + 1 < gpl[pos]) {
            gpl[pos] = dp[newpos - 1] + 1;
            gpsuff[pos] = newpos;
          }
        }
        if(gpl[pos] < dp[i]) {
          dp[i] = gpl[pos];
          suff[i] = gpsuff[pos];
        }
      }
    }
    if(1 < i && v[i - 1] == v[i]) {
      if(dp[i - 2] < dp[i]) {
        dp[i] = dp[i - 2];
        suff[i] = i - 1;
      }
    }
  }

  if(dp[n] == nmax)
    std::cout << -1;
  else {
    std::cout << dp[n] << '\n';
    int pos = n;
    while(0 < pos) {
      if(suff[pos] < pos - 1)
        std::cout << (suff[pos] + 1) / 2 << " " << pos / 2 << '\n';
      pos = suff[pos] - 1;
    }
  }
  return 0;
}