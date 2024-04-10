#include <iostream>

using namespace std;

int const nmax = 30;
int const sigma = 26;
int frec[1 + nmax];

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++){
    char a;
    cin >> a;
    if('a' <= a && a <= 'z')
      frec[a - 'a']++;
    else
      frec[a - 'A']++;
  }
  for(int i = 0; i < sigma; i++)
    if(0 == frec[i]) {
      cout << "NO";
      return 0;
    }
  cout << "YES";
  return 0;
}