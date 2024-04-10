#include <iostream>
#include <vector>
#include <algorithm>

int const nmax = 100000000;
int const inf = 1000000000;
int const sigma = 1000;
int const modulo = 1000000007;
//int dp[1 + nmax];
std::pair<int,int> init[sigma] = {{0, 0}, {2, 0},{3, 1},{4, 2},{6, 1},{8, 2},{12, 0},{14, 1},{18, 2},{26, 0},{38, 1},{39, 2},{56, 0},{57, 2},{80, 1},{84, 2},{119, 0},{120, 2},{173, 1},{178, 2},{254, 0},{259, 2},{362, 1},{381, 2},{536, 0},{543, 2},{779, 1},{804, 2},{1145, 0},{1168, 2},{1631, 1},{1717, 2},{2414, 0},{2446, 2},{3506, 1},{3621, 2},{5153, 0},{5259, 2},{7340, 1},{7729, 2},{10865, 0},{11010, 2},{15779, 1},{16297, 2},{23189, 0},{23668, 2},{33032, 1},{34783, 2},{48893, 0},{49548, 2},{71006, 1},{73339, 2},{104351, 0},{106509, 2},{148646, 1},{156526, 2},{220019, 0},{222969, 2},{319529, 1},{330028, 2},{469580, 0},{479293, 2},{668909, 1},{704370, 2},{990086, 0},{1003363, 2},{1437881, 1},{1485129, 2},{2113112, 0},{2156821, 2},{3010091, 1},{3169668, 2},{4455389, 0},{4515136, 2},{6470465, 1},{6683083, 2},{9509006, 0},{9705697, 2},{13545410, 1},{14263509, 2},{20049251, 0},{20318115, 2},{29117093, 1},{30073876, 2},{42790529, 0},{43675639, 2},{60954347, 1},{64185793, 2},{90221630, 0},{91431520, 2},{131026919, 1},{135332445, 2},{192557381, 0},{196540378, 2},{274294562, 1},{288836071, 2},{405997337, 0},{411441843, 2},{589621136, 1},{608996005, 2},{866508215, 0},{884431704, 2},{1000000000, 1}};

/*
*/
int mex(int a, int b) {
  if(a != 0 && b != 0)
    return 0;
  else if(a != 1 && b != 1)
    return 1;
  else
    return 2;
}

/*
void computedp() {
  for(int i = 3;i <= nmax; i++)
    dp[i] = mex(dp[i / 3], dp[i - i / 3]);
}
*/

int extract(int number) {
  if(number < 3)
    return 0;
  else
    return mex(extract(number / 3), extract(number - number / 3));
}


int const mvmax = 1000;
int dp[1 + mvmax][4];

int gauss(int n) {
  return 1LL * n * (n + 1) / 2 % modulo;
}

void reducep(int &a, int &b, int &c, int p) {
  if(a % p == 0)
    a /= p;
  else if(b % p == 0)
    b /= p;
  else if(c % p == 0)
    c /= p;
}

int fast(int x, int y, int p) {
  int result = 1LL * p * (y - x + 1) % modulo;
  int result2 = (modulo + gauss(y) - gauss(x - 1)) % modulo;

  return (modulo +result - result2) % modulo;
}

int brut(int x, int y, int p) {
  int result = 0;
  for(int i = x; i <= y; i++)
    result += (p - i);
  return result;
}

int main() {
  /*
  computedp();
  std::vector<std::pair<int,int>> sol;
  sol.push_back({1, 0});
  for(int i = 2; i <= nmax * 10; i++) {
    int cost = extract(i);
    if(cost == sol.back().second)
      sol.back().first++;
    else
      sol.push_back({i, cost});
    if(i % (nmax * 1) == 0)
      std::cerr << i << '\n';
  }
  for(int i = 0; i < sol.size(); i++)
    std::cout << "{" << sol[i].first << ", " << sol[i].second << "},";
  */
  int ptr = 0;
  int n, lim;
  std::cin >> n >> lim;
  int ones = 0, twos = 0, zeros = 0;

  for(int i = 0; i <= sigma; i++)
    if(0 < i && init[i].first == 0){
      ptr = i;
      init[i].first = inf + 1;
      break;
    } 
  
  for(int i = 1;i < ptr; i++) {
    if(init[i - 1].first + 1 < lim) {
      if(init[i].second == 0)
        zeros += fast(init[i - 1].first + 1, std::min(lim - 1, init[i].first), lim);
      else if(init[i].second == 1)
        ones +=  fast(init[i - 1].first + 1, std::min(lim - 1, init[i].first), lim);
      else
        twos +=  fast(init[i - 1].first + 1, std::min(lim - 1, init[i].first), lim);
      if(modulo <= zeros)
        zeros -= modulo;
      if(modulo <= ones)
        ones -= modulo;
      if(modulo <= twos)
        twos -= modulo;
    }
  }
  
  dp[0][0] = 1;
  
  for(int i = 1;i <= n; i++) {
    for(int h = 0; h < 4; h++)
      dp[i][h] = (1LL * dp[i - 1][h ^ 0] * zeros + 
                  1LL * dp[i - 1][h ^ 1] * ones + 
                  1LL * dp[i - 1][h ^ 2] * twos) % modulo;
  }
  std::cout << (0LL + dp[n][1] + dp[n][2] + dp[n][3]) % modulo << '\n';
}