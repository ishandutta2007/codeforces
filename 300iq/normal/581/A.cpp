#include <algorithm>
#include <iostream>
#include <fstream>
#define ll long long
using namespace std;
int main()
{
   int a, b;
   cin >> a >> b;
   int tmp = max(a, b);
   a = min(a, b);
   b = tmp;
   cout << a << " " << (b - a) / 2;
}