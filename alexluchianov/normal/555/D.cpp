#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 200000;
int v[1 + nmax];
set<int> myset;
map<int,int> code;

void makemove(int &start, int &l){
  set<int>::iterator it = myset.lower_bound(start + l + 1);
  set<int>::iterator it2 = myset.lower_bound(start - l);
  it--;
  if(start < *it){
    l -= (*it - start);
    start = *it;
  } else if(*it2 < start){
    l -= (start - *it2);
    start = *it2;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  cin >> n >> q;
  for(int i = 1;i <= n; i++){
    cin >> v[i];
    myset.insert(v[i]);
    code[v[i]] = i;
  }
  for(int i = 1; i <= q; i++){
    int start, l;
    cin >> start >> l;
    start = v[start];
    while(true){
      int start1 = start, l1 = l;
      makemove(start, l);
      makemove(start, l);
      if(start == start1 && l != l1)
        l %= (l1 - l);
      else if(l == l1)
        break;
    }
    cout << code[start] << '\n';
  }
  return 0;
}