#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#define int long long
using namespace std;

struct Event {
  int pos, val;
  bool type;

  Event(int _pos = 0, int _val = 0, bool _type = false) {
    pos = _pos;
    val = _val;
    type = _type;
  }
};

bool operator < (const Event & a, const Event & b) {
  return a.pos < b.pos;
}

int sommes[1000 * 1000 + 42];

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int nbLigs, nbCols;
  cin >> nbLigs >> nbCols;

  for(int iLig = 0;iLig < nbLigs;iLig++) {
    int nbElems;
    cin >> nbElems;

    vector<Event> events;
    
    vector<int> elems;
    int maxi = 0;
    for(int iElem = 0;iElem < nbElems;iElem++) {
      int elem;
      cin >> elem;
      elems.push_back(elem);
      maxi = max(maxi, elem);
      events.push_back(Event(iElem, elem, true));
      events.push_back(Event(nbCols - nbElems + iElem + 1, elem, false));
    }

    int iEvent = 0;
    sort(events.begin(), events.end());

    multiset<int> ouverts;

    int iPos = 0;
    for(;iPos < nbElems;iPos++) {
      while(iEvent != (int)events.size() && events[iEvent].pos == iPos) {
	if(events[iEvent].type) {
	  ouverts.insert(events[iEvent].val);
	}
	else {
	  ouverts.erase(ouverts.find(events[iEvent].val));
	}
	iEvent++;
      }

      int curMax = *ouverts.rbegin();
      if(iPos + nbElems < nbCols) {
	curMax = max(curMax, 0ll);
      }
      
      sommes[iPos] += curMax;
      sommes[iPos + 1] -= curMax;
    }
    
    sommes[iPos] += maxi;
    iPos = max(iPos, nbCols - nbElems);
    sommes[iPos] -= maxi;
    
    for(;iPos < nbCols;iPos++) {
      while(iEvent != (int)events.size() && events[iEvent].pos == iPos) {
	if(events[iEvent].type) {
	  ouverts.insert(events[iEvent].val);
	}
	else {
	  ouverts.erase(ouverts.find(events[iEvent].val));
	}
	iEvent++;
      }

      int curMax = *ouverts.rbegin();
      if(iPos >= nbElems) {
	curMax = max(curMax, 0ll);
      }
      
      sommes[iPos] += curMax;
      sommes[iPos + 1] -= curMax;
    }
  }

  for(int iCol = 0;iCol < nbCols;iCol++) {
    cout << sommes[iCol] << " ";
    sommes[iCol + 1] += sommes[iCol];
  }
  return 0;
}