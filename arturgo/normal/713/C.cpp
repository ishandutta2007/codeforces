#include <iostream>
#include <queue>
#include <set>
using namespace std;

int main() {
  int nbEntiers;
  cin >> nbEntiers;

  multiset<long long> changes;
  long long firstSlope = 0, ans = 0;
  for(int iEntier = 0;iEntier < nbEntiers;iEntier++) {
    long long entier;
    cin >> entier;
    entier -= iEntier;
    ans += entier;

    changes.insert(entier);
    changes.insert(entier);
    firstSlope--;
    
    while(firstSlope + changes.size() > 0) {
      changes.erase(changes.lower_bound(*changes.rbegin()));
    }
  }

  long long curPos = 0, curPente = firstSlope;
  while(!changes.empty()) {
    long long nouvPos = *changes.begin();
    ans += curPente * (nouvPos - curPos);
    curPos = nouvPos;
    curPente++;
    changes.erase(changes.begin());
  }

  cout << ans << endl;
  return 0;
}