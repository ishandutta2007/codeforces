#include <iostream>

using namespace std;

int main()
{
  char ch;
  for(int i = 0; i < 7; i++)
    cin >> ch;
  ch -= '0';
  cout << ch % 2;
  return 0;
}