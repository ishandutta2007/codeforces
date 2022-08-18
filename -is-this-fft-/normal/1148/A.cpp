
 #include <iostream>

using namespace std;

int main () {
  long long a, b, c;
  cin >> a >> b >> c;

  c *= 2;
  c += 2*min(a, b);
  if (a != b) c++;

  cout << c << endl;
}