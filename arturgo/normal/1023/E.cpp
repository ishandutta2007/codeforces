#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool can_go(int lig1, int col1, int lig2, int col2) {
  cout << "? " << lig1 << " " << col1 << " " << lig2 << " " << col2 << endl;
  cout.flush();
  string answer;
  cin >> answer;
  return answer == "YES";
}

vector<int> path;

int main() {
  ios_base::sync_with_stdio(false);
  int taille;
  cin >> taille;


  int curLig = 1, curCol = 1;
  string depsA;

  for(int iFois = 0;iFois < taille - 1;iFois++) {
    if(curLig <= taille && can_go(curLig + 1, curCol, taille, taille)) {
      curLig++;
      depsA.push_back('D');
    }
    else {
      curCol++;
      depsA.push_back('R');
    }
  }

  string depsB;
  int autLig = taille, autCol = taille;
  for(int iFois = 0;iFois < taille - 1;iFois++) {
    if(can_go(1, 1, autLig, autCol - 1)) {
      autCol--;
      depsB.push_back('R');
    }
    else {
      autLig--;
      depsB.push_back('D');
    }
  }

  reverse(depsB.begin(), depsB.end());
  cout << "! " << depsA << depsB << endl;
  cout.flush();
  return 0;
}