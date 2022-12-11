#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int pgcd(int a, int b) {
  if(a == 0)
    return b;
  return pgcd(b % a, a);
}

vector<int> divisors(int n) {
  vector<int> divs;
  for(int i = 1;i*i <= n;i++) {
    if(n % i == 0) {
      divs.push_back(i);
      if(i * i != n)
	divs.push_back(n/i);
    }
  }
  sort(divs.begin(), divs.end());
  return divs;
}

int main() {
  ios_base::sync_with_stdio(false);
  
  int nbTests;
  cin >> nbTests;

  for(int iTest = 0;iTest < nbTests;iTest++) {
    int A, B, C;
    cin >> A >> B >> C;

    vector<int> dA = divisors(A);
    vector<int> dB = divisors(B);
    vector<int> dC = divisors(C);
    vector<int> cBC = divisors(pgcd(B, C));
    vector<int> cAB = divisors(pgcd(A, B));
    vector<int> cCA = divisors(pgcd(C, A));
    vector<int> cT = divisors(pgcd(A, pgcd(B, C)));

    int divTout = cT.size();
    int divAB = cAB.size() - divTout;
    int divBC = cBC.size() - divTout;
    int divCA = cCA.size() - divTout;
    int divA = dA.size() - divAB - divCA - divTout;
    int divB = dB.size() - divAB - divBC - divTout;
    int divC = dC.size() - divBC - divCA - divTout;

    cout <<
      divA * divB * divC
      + divTout * (divA * divB + divB * divC + divC * divA)
      + (divA + divB + divC) * (divAB + divBC + divCA) * divTout
      + (divA + divB + divC) * (divBC * divCA + divCA * divAB + divAB * divBC)
      + divA * ((divB + divC) * divBC + divBC * (divBC + 1) / 2 + divTout * (divTout + 1) / 2)
      + divB * ((divA + divC) * divCA + divCA * (divCA + 1) / 2 + divTout * (divTout + 1) / 2)
      + divC * ((divB + divA) * divAB + divAB * (divAB + 1) / 2 + divTout * (divTout + 1) / 2)
      + divTout * (divTout + 1) * (divTout + 2) / 6
      + divTout * (divTout + 1) / 2 * (divAB + divBC + divCA)
      + divTout * (divBC * divCA + divCA * divAB + divAB * divBC)
      + divAB * (divAB + 1) / 2 * (divBC + divCA + divTout)
      + divBC * (divBC + 1) / 2 * (divAB + divCA + divTout)
      + divCA * (divCA + 1) / 2 * (divBC + divAB + divTout)
      + divAB * divBC * divCA << endl;
  }

  return 0;
}