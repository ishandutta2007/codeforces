#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h>
#include <time.h>
#include <functional>
#include <numeric>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

#define debug(format, ...) printf(format, __VA_ARGS__);

const int N_ = 100500;
const int C_ = 1050;

int N, K, X;

int main() {
  scanf("%d%d%d", &N, &K, &X);
  vector<int> freq(C_);
  for(int i = 1; i <= N; i++) {
    int x;
    scanf("%d", &x);
    freq[x] += 1;
  }

  for(int rep = 0; rep < K; rep++) {
    vector<int> nfreq(C_);
    int carry = 0;
    for(int i = 0; i < C_; i++) {
      nfreq[i] += (freq[i] + carry) / 2;
      nfreq[i ^ X] += (freq[i] + !carry) / 2;
      carry ^= freq[i] % 2;
    }
    freq = nfreq;
  }

  vector<int> pos;
  for(int i = 0; i < C_; i++) {
    if(freq[i] > 0) pos.push_back(i);
  }

  printf("%d %d\n",
    *max_element(pos.begin(),pos.end()),
    *min_element(pos.begin(), pos.end())
  );

  return 0;
}