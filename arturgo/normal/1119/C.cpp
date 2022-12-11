#include <iostream>
#include <vector>
#include <set>
using namespace std;

int A[1000][1000];
int B[1000][1000];

int main() {
  ios_base::sync_with_stdio(false);
  int nbLigs, nbCols;
  cin >> nbLigs >> nbCols;
  
  for(int iLig = 0;iLig < nbLigs;iLig++) {
    for(int iCol = 0;iCol < nbCols;iCol++) {
      cin >> A[iLig][iCol];
    }
  }
  
  for(int iLig = 0;iLig < nbLigs;iLig++) {
    for(int iCol = 0;iCol < nbCols;iCol++) {
      cin >> B[iLig][iCol];
    }
  }
  
  for(int iLig = 0;iLig < nbLigs;iLig++) {
    int parityA = 0, parityB = 0;
    
    for(int iCol = 0;iCol < nbCols;iCol++) {
      parityA = (parityA + A[iLig][iCol]) % 2;
      parityB = (parityB + B[iLig][iCol]) % 2;
    }
    
    if(parityA != parityB) {
      cout << "No" << endl;
      return 0;
    }
  }
  
  for(int iCol = 0;iCol < nbCols;iCol++) {
    int parityA = 0, parityB = 0;
    
    for(int iLig = 0;iLig < nbLigs;iLig++) {
      parityA = (parityA + A[iLig][iCol]) % 2;
      parityB = (parityB + B[iLig][iCol]) % 2;
    }
    
    if(parityA != parityB) {
      cout << "No" << endl;
      return 0;
    }
  }
  
  cout << "Yes" << endl;
  return 0;
}