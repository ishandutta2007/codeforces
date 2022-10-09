#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  sort(s.begin() ,s.end());
  cout << s;

  return 0;
}