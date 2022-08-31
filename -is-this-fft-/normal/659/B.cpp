#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

const int MAX_REG = 10005;

using namespace std;

vector<pair<int, string> > teams [MAX_REG];

int main () {
  int studentc, regc;
  cin >> studentc >> regc;

  for (int i = 0; i < studentc; i++) {
    string name;
    int region, score;
    cin >> name >> region >> score;
    
    teams[region].push_back(make_pair(score, name));
  }

  for (int i = 1; i <= regc; i++) {
    sort(teams[i].begin(), teams[i].end(), greater<pair<int, string> >());
    if (teams[i].size() > 2 && teams[i][1].first == teams[i][2].first) {
      /* fucking gay stuff that is the most retarded thing
       * in the history of retarded cases
       * like srsly why the hell does this fail only on the 53th case?
       * this should fail in the first case because reg 2 has only 2
       * people
       * also this exists for the purpose of hacking
       * which is a sin in and of itself
       *
       * Also this whole contest was just weird
       * i mean seriously
       * problem D has a one liner answer???
       * like wtf right?
       * also most problems were too easy for div 2
       * what the fuck
       * even if this is a 7 problem contest
       * it's not a real contest if 4 problems are trivial
       * fucking hell man 
       *
       * Another resubmission.... fuuuuuuuuuuuuuck */
      cout << "?" << endl;
    } else {
      cout << teams[i][0].second << " " << teams[i][1].second << endl;
    }
  }
}