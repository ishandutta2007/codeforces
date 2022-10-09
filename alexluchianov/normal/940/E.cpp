#include <iostream>
#include <vector>
#include <deque>


using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int v[5 + nmax];

ll dp[5 + nmax];

int main()
{
  int n , k;
  cin >> n >> k;
  ll sum = 0;
  for(int i = 1 ; i <= n ; i++) {
    cin >> v[i];
    sum += v[i];
  }

  deque<int> dq;
  for(int i = 1 ; i <= n ; i++){
    while(0 < dq.size() && v[i] < v[dq.back()] )
      dq.pop_back();
    dq.push_back(i);
    while(dq.front() <= i - k)
      dq.pop_front();

    if(k <= i)
      dp[i] = v[dq.front()];
  }
  for(int i = 1 ; i <= n ; i++){
    if(k <= i)
      dp[i] = MAX(dp[i] + dp[i - k] , dp[i - 1]);
    else
      dp[i] = dp[i - 1];
  }
  cout << sum - dp[n];

  return 0;
}