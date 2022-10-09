#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (A))

int const nmax = 100000;
int v[1 + nmax], frec[1 + nmax];
int n;

int eval(int x){
  int sum = 0, last = 1, result = 1;
  for(int i = 1;i <= n; i++){
    frec[v[i]]++;
    if(frec[v[i]] == 1)
      sum++;
    if(sum == x + 1){
      while(last < i){
        frec[v[last]]--;
        last++;
      }
      sum = 1;
      result++;
    }
  }
  while(last <= n){
    frec[v[last]]--;
    last++;
  }
  return result;
}
int sol[1 + nmax];

int binarysearch(int from, int to, int target){
  if(from < to){
    int mid = (from + to + 1) / 2;
    if(sol[mid] == 0)
      sol[mid] = eval(mid);
    if(target <= sol[mid])
      return binarysearch(mid, to, target);
    else
      return binarysearch(from, mid - 1, target);
  } else
    return from;
}

int main()
{
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  int ptr = 1;
  while(ptr <= n){
    int target;
    if(sol[ptr] == 0)
      sol[ptr] = eval(ptr);
    target = sol[ptr];

    int lim = binarysearch(1, n, target);
    ++ptr;
    while(ptr <= lim){
      sol[ptr] = target;
      ptr++;
    }
  }
  for(int i = 1;i <= n; i++)
    cout << sol[i] << " ";
  return 0;
}