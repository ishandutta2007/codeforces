#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void output(const vector <ll> &v, int left) {
  printf("%d %d\n", left + 1, left + v.size());
  for (auto it : v)
    printf("%lld ", it);
  puts("");
}

int main() {
  int N;
  scanf("%d", &N);
  vector <ll> a(N);
  for (auto &it : a)
    scanf("%lld", &it);
  
  if (N == 1) {
    printf("1 1\n%lld\n", -a[0]);
    printf("1 1\n0\n");
    printf("1 1\n0\n");
    return 0; 
  }
  
  vector <ll> one;
  for (int i = 0; i < N; i++)
    one.push_back(-N * a[i]);
  
  vector <ll> two;
  for (int i = 1; i < N; i++)
    two.push_back((N - 1) * a[i]);
  
  vector <ll> three;
  for (int i = 0; i < N - 1; i++)
    three.push_back(i ? 0 : (N - 1) * a[i]);
  
  output(one, 0);
  output(two, 1);
  output(three, 0);
  
  return 0;
}