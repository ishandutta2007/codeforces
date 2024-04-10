#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 1024;
int v[1 + nmax];
deque<int> dq;
int n, k;

int ask(int val){
  cout << "? " << val << '\n';
  dq.push_back(val);
  if(k < dq.size())
    dq.pop_front();

  cout.flush();
  char result;
  cin >> result;
  if(result == 'Y')
    return 1;
  else
    return 0;
}

void reset(){
  cout << "R\n";
  cout.flush();
}

int dqfront(){
  if(dq.size() == 0)
    return n + 1;
  else
    return dq.front();
}

void reduce(vector<int> v1, vector<int> v2){
  if(v1.size() == 0 || v2.size() == 0)
    return ;
  for(int i = 0; i < v1.size(); i++)
    ask(v1[i]);
  for(int i = 0; i < v2.size(); i++) {
    int pos = v2[i];
    v[pos] &= !ask(pos);
  }
  ask(v2.back());
  for(int i = 0; i < v1.size() - 1; i++){
    int pos = v1[i];
    v[pos] &= !ask(pos);
  }
}

int main()
{
  /*
  for(int n = 1;n <= nmax; n *= 2)
    for(int k = 1; k <= n; k *= 2)
      cout << n << " " << k << " " << (n + n / k + (n / k * (n / k - 1) / 2) * (3 * k) ) << " " << (3 * n * n / k / 2) << " " << ((n + n / k + (n / k * (n / k - 1) / 2) * (3 * k) ) <= (3 * n * n / k / 2)) <<'\n';
  //*/

  cin >> n >> k;
  if(k == 1) {
    for(int i = 1;i <= n; i++)
      v[i] = 1;

    for(int i = 1;i <= n; i++)
      for(int j = 1;j < i; j++) {
        ask(j);
        v[i] &= !ask(i);
      }
  } else {
    for(int i = 1;i <= n; i++)
      v[i] = 1;

    for(int i = 1;i <= k; i++)
      v[i] = !(ask(i));

    for(int i = 1;i < n / k; i++){
      int start = i * k;
      reset();
      ask(1);
      for(int bon = 1; bon <= k; bon++)
        v[start + bon] &= !ask(start + bon);

      for(int j = 0; j < i; j++){
        reset();
        int from = j * k;
        vector<int> v1, v2;
        for(int bon = 1; bon <= k; bon++)
          if(v[from + bon] == 1)
            v1.push_back(from + bon);
          else
            v1.push_back(1);

        for(int bon = 1; bon <= k; bon++)
          if(v[start + bon] == 1)
            v2.push_back(start + bon);
          else
            v2.push_back(1);
        reduce(v1, v2);
        v[1] = 1; /// 1 has immunity to whatever happened
      }
    }
  }
  int result = 0;
  for(int i = 1;i <= n; i++)
    result += v[i];
  cout << "! " << result << '\n';


  return 0;
}