#include <iostream>
#include <cmath>

using namespace std;

int const nmax = 300;
int const modulo = (int) (1e9) + 7;

int comb[1 + nmax][1 + nmax];
int fact[1 + nmax];
int n, k;
int dim[1 + nmax];
int dp[1 + nmax][1 + nmax];
//dp[i][j] = Nr de moduri de a aseza toate dalele de primele i culori, astfel incat sa am j defecte

void precompute() {
  for(int i = 0 ; i <= n ;i++){
    comb[i][0] = 1;
  }
  for(int i = 1 ; i <= n ;i++){
    for(int j = 1 ; j <= i ;j++){
      comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
      if(modulo <= comb[i][j] ){
        comb[i][j] -= modulo;
      }
    }
  }
  fact[1] = 1;
  for(int i = 2 ; i <= n ;i++) {
    fact[i] = (1LL * fact[i - 1] * i) % modulo;
  }
}

bool perfectsquare(int a, int b) {
  long long prod = 1LL * a * b;
  long long rad = sqrt(prod);
  return (prod == rad * rad);
}

void read() {
  int v[1 + nmax], belong[1 + nmax]; //carei multimi ii apartine

  cin >> n;
  for(int i = 1 ; i <= n; i++){
    cin >> v[i];
    belong[i] = 0;
  }
  for(int i=1; i<=n; i++) {
    if(belong[i] == 0) {
      k++;
      dim[k]++;
      belong[i] = k;
      for(int j = i + 1; j <= n; j++) {
        if(perfectsquare(v[i] , v[j] ) ){
          belong[j] = k;
          dim[k]++;
        }
      }
    }
  }
}

int solve() {
  int suma = dim[1];
  dp[1][suma - 1] = 1;
  for(int i = 2; i <= k; i++) {
    for(int j = 0; j < suma; j++) {
      //in cate bucati vreau sa partitionez multimea i
      for(int p = 1 ; p <= dim[i]; p++){
        //cate defecte vechi vreau sa repar
        for(int h = 0; h <= p && h <= j; h++) {
          int val = 1LL * comb[dim[i] - 1][p - 1] * comb[j][h] % modulo;
          val = (1LL * val * comb[suma + 1 - j][p - h]) % modulo;
          dp[i][j - h + dim[i] - p] += (1LL * dp[i - 1][j] * val ) % modulo;
          //cout<<i<<", "<<j - h + dim[i] - p<<" "<<endl;
          if(modulo <= dp[i][j - h + dim[i] - p]){
            dp[i][j - h + dim[i] - p] -= modulo;
          }
        }
      }
    }
    suma += dim[i];
  }
  int answer = dp[k][0];
  for(int i = 1; i <= k; i++){
    answer = (1LL * answer * fact[dim[i]]) % modulo;
  }
  return answer;
}

int main() {
  read();
  precompute();

  cout << solve();
  return 0;
}