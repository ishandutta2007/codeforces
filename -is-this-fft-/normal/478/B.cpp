#include <iostream>

using namespace std;

typedef long long llong;

llong choose2 (llong n) {
  return n * (n - 1) / 2;
}

int main () {
  llong vertexc, compc;
  cin >> vertexc >> compc;

  llong kmin = 0;
  llong bigc = vertexc % compc, smallsz = vertexc / compc;
  kmin = bigc * choose2(smallsz + 1) + (compc - bigc) * choose2(smallsz);

  llong kmax = choose2(vertexc - (compc - 1));

  cout << kmin << " " << kmax << endl;
}