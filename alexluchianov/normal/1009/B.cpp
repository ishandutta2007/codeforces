#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define ll long long
#define MIN(a , b) ((((a) < (b)) ? (a) : (b))
#define MAX(a , b) ((((a) < (b)) ? (b) : (a))
int const nmax = 100000;
char v[5 + nmax];
int frec[10];

int main()
{
  cin >> (v + 1);
  int n = strlen(v + 1);
  int last2 = 0;
  for(int i = 1 ; i <= n ;i++){
    if(v[i] == '0')
      frec[0]++;
    else if(v[i] == '1')
      frec[1]++;
    else
      frec[2]++;
  }
  for(int i = 1 ; i <= n ;i++){
    if(v[i] == '2' && 0 < frec[1]){
      for(int j = 0 ; j < frec[1] ; j++) {
        cout << 1;
      }
      frec[1] = 0;
    }
    if(v[i] != '1')
      cout << v[i];
  }
  for(int j = 0 ; j < frec[1] ;j++)
    cout << 1;
  return 0;
}