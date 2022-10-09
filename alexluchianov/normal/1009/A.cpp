#include <iostream>

using namespace std;

#define ll long long
#define MIN(a , b) ((((a) < (b)) ? (a) : (b))
#define MAX(a , b) ((((a) < (b)) ? (b) : (a))
int const nmax = 10000;
int v[5 + nmax];
int v2[5 + nmax];

int main()
{
  int n , m;
  cin >> n >> m;
  for(int i = 1 ; i <= n ;i++)
    cin >> v[i];
  for(int i = 1 ; i <= m ;i++)
    cin >> v2[i];
  int result = 0 , last = 1;
  for(int i = 1 ; i <= n ;i++){
    if(last <= m && v[i] <= v2[last]){
      last++;
      result++;
    }
  }
  cout << result;
  return 0;
}