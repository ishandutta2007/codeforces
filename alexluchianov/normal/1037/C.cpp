#include <iostream>
#include <fstream>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int main()
{
  int n;
  cin >> n;
  string s;
  string s2;
  cin >> s;
  cin >> s2;
  int result = 0;
  for(int i = 1; i < n; i++){
    if(s[i - 1] != s2[i - 1] && s[i] != s2[i] && s[i - 1] == s2[i] && s[i] == s2[i - 1]) {
      swap(s[i - 1], s[i]);
      result++;
    }
  }
  for(int i = 0;i < n; i++)
    if(s[i] != s2[i])
      result++;
  cout << result;
  return 0;
}