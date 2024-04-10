#include <iostream>

using namespace std;

#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const sigma = 26;
int allowed[5 + sigma][5 + sigma];
string v;
int dp[5 + sigma];
int dp2[5 + sigma];

int main()
{
  cin >> v;
  v = "#" + v;

  int k;
  cin >> k;
  for(int i = 1 ; i <= k ; i++){
    char a , b;
    cin >> a >> b;
    allowed[a - 'a'][b - 'a'] = 1;
    allowed[b - 'a'][a - 'a'] = 1;
  }
  for(int i = 1 ; i < v.size() ; i++){
    for(int j = 0 ; j < 26 ; j++){
      if(allowed[j][v[i] - 'a'] == 0){
        dp2[v[i] - 'a'] = MAX(dp2[v[i] - 'a'] , dp[j] + 1);
      }
    }
    for(int j = 0; j < 26; j++){
      dp[j] = MAX(dp[j] , dp2[j]);
      dp2[j] = 0;
    }
  }
  int result = 0;
  for(int j = 0 ; j < 26 ; j++){
    result = MAX(result , dp[j]);
  }
  cout << v.size() - result - 1;

  return 0;
}