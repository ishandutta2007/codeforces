#include <iostream>
using namespace std;

//ifstream in("pebbles.in");

int main() {
  int n, k;
  cin>>n>>k;
  int a;
  int buzunare = 0;
  for(int i = 0 ; i < n ;i++) {
    cin>>a;
    buzunare = buzunare + a / k + bool(a % k);
  }
  cout<<buzunare / 2 + buzunare % 2;
  return 0;
}