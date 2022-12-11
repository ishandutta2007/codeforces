#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> divisors(long long a) {
  vector<long long> divs;
  long long d = 2;
  while(d * d <= a) {
    while(a % d == 0) {
      a /= d;
      divs.push_back(d);
    }
    d++;
  }
  divs.push_back(a);
  return divs;
}

int main() {
  ios_base::sync_with_stdio(false);
  int nbPaires;
  cin >> nbPaires;

  vector<pair<int, int>> paires;
  for(int iPaire = 0;iPaire < nbPaires;iPaire++) {
    int a, b;
    cin >> a >> b;
    paires.push_back({a, b});
  }

  vector<int> possibles;
  for(int elem : divisors(paires[0].first)) {
    possibles.push_back(elem);
  }
  for(int elem : divisors(paires[0].second)) {
    possibles.push_back(elem);
  }

  for(int div : possibles) {
    bool possible = true;
    for(pair<int, int> paire : paires) {
      if(!possible)
	break;
      if(paire.first % div != 0 && paire.second % div != 0) {
	possible = false;
      }
    }

    if(possible && div > 1) {
      cout << div << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}