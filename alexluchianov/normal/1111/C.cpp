#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int const nmax = 100000;
ll const inf = 1000000000000000000LL;

vector<int> avengers;

int lowerthan(vector<int> &v, int target){
  int x = 0;
  for(int h = 20; 0 <= h; h--){
    if(x + (1 << h) <= v.size() && v[x + (1 << h) - 1] <= target)
      x += (1 << h);
  }
  return x;
}

int A, B;

ll solve(int from, int to){
  int mid = (from + to) / 2;
  int inrange = lowerthan(avengers, to) - lowerthan(avengers, from - 1);
  if(inrange == 0)
    return A;

  ll result = 1LL * inrange * B * (to - from + 1);
  if(from < to)
    result = min(result, solve(from, mid) + solve(mid + 1, to));
  return result;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int k, n;
  cin >> k >> n >> A >> B;
  for(int i = 1;i <= n; i++){
    int a;
    cin >> a;
    avengers.push_back(a);
  }
  sort(avengers.begin(), avengers.end());
  cout << solve(1, (1 << k));

  return 0;
}