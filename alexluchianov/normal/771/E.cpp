#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <map>

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 300000;
int v[1 + nmax], v2[1 + nmax];

std::map<int,int> fmax1, fmax2;

void _add(std::map<int,int> &mp, std::pair<int,int> fp) {
  std::map<int,int>::iterator it = mp.lower_bound(fp.first), it2;
  it2 = it;
  if(fp.second < it->second)
    mp.erase(it++);
  if(it != mp.begin())
    it2--;
  if(it == mp.begin() || fp.second < it2->second) {
    mp.insert(fp);
  }
}

std::map<ll, int> frec, frec2, frec3;


int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  int smax = 0;
  fmax1.insert({0, 0});

  for(int i = 1;i <= n; i++) 
    std::cin >> v[i];
  for(int i = 1;i <= n; i++)
    std::cin >> v2[i];
  frec[0] = 1;
  frec2[0] = 1;
  frec3[0] = 1;
  
  ll sum = 0, sum2 = 0, sum3 = 0;

  for(int i = 1; i <= n; i++) {
    sum += v[i];
    sum2 += v2[i];
    sum3 += v[i] + v2[i];

    if(0 < frec[sum]) {
      int target = frec[sum];

      std::map<int,int>::iterator it = fmax2.begin();
      int last = -1;
      while(it != fmax2.end() && it->first < target) {
        last = it->second;
        fmax2.erase(it++);
      }
      if(0 <= last)
        _add(fmax1, {i, last});
      
      it = fmax1.begin();
      last = -1;
      while(it != fmax1.end() && it->first < target) {
        last = it->second;
        fmax1.erase(it++);
      }
      if(0 <= last) {
        std::swap(fmax1, fmax2);
        fmax1.clear();
        _add(fmax1, {i, last});
        smax++;
      }
    }

    if(0 < frec2[sum2]) {
      int target = frec2[sum2];

      std::map<int,int>::iterator it = fmax2.end();
      if(it != fmax2.begin()) {
        it--;
        int last = -1;
        while(it->second < target) {
          last = it->first;
          if(it == fmax2.begin()) {
            fmax2.erase(it);
            break;
          } else 
            fmax2.erase(it--);
        }
        if(0 <= last)
          _add(fmax1, {last, i});
      }
      int last = -1;
      it = fmax1.end();
      
      if(it != fmax1.begin()) {
        it--;
        int last = -1;
        while(it->second < target) {
          last = it->first;
          if(it == fmax1.begin()) {
            fmax1.erase(it);
            break;
          } else 
            fmax1.erase(it--);
        }
        if(0 <= last) {
          std::swap(fmax1, fmax2);
          fmax1.clear();
          _add(fmax1, {last, i});
          smax++;
        }
      }

    }

    if(0 < frec3[sum3]) {
      int target = frec3[sum3];
      std::map<int,int>::iterator it = fmax2.lower_bound(target);
      if(it != fmax2.begin()) {
        it--;
        if(it->second < target) {
          _add(fmax1, {i, i});
        }
      }
      it = fmax1.lower_bound(target);
      if(it != fmax1.begin()) {
        it--;
        if(it->second < target) {
          std::swap(fmax1, fmax2);
          fmax1.clear();
          _add(fmax1, {i, i});
          smax++;
        }
      }
    }

    frec[sum] = i + 1;
    frec2[sum2] = i + 1;
    frec3[sum3] = i + 1;

    /*
    std::cout << "phase\n";
    for(std::map<int,int>::iterator it = fmax1.begin(); it != fmax1.end(); it++)
      std::cout << it->first << " " << it->second << ": ";
    std::cout << '\n';
    for(std::map<int,int>::iterator it = fmax2.begin(); it != fmax2.end(); it++)
      std::cout << it->first << " " << it->second << ": ";
    std::cout << '\n';
    std::cout << '\n';
    */

  }
  std::cout << smax;

  return 0;
}