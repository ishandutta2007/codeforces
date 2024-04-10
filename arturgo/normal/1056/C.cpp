#include <iostream>
#include <queue>
using namespace std;

struct Event {
  int n, a, b;
  Event(int _n = 0, int _a = 0, int _b = 0) {
    n = _n;
    a = _a;
    b = _b;
  }
};

int pouvoirs[100 * 1000];
int autres[100 * 1000];
bool dansPaire[100 * 1000];
bool sontPris[100 * 1000];
priority_queue<Event> events;

bool operator < (const Event &a, const Event &b) {
  if(a.n == b.n)
    return pouvoirs[a.a] < pouvoirs[b.a];
  return a.n < b.n;
}

int main() {
  ios_base::sync_with_stdio(false);
  int nbNombres, nbPaires;
  cin >> nbNombres >> nbPaires;

  for(int iNombre = 0;iNombre < 2 * nbNombres;iNombre++) {
    cin >> pouvoirs[iNombre];
  }

  for(int iPaire = 0;iPaire < nbPaires;iPaire++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    autres[a] = b;
    autres[b] = a;
    dansPaire[a] = true;
    dansPaire[b] = true;

    if(pouvoirs[a] < pouvoirs[b])
      events.push(Event(2, b, a));
    else
      events.push(Event(2, a, b));
  }

  for(int iNombre = 0;iNombre < 2 * nbNombres;iNombre++) {
    if(!dansPaire[iNombre]) {
      events.push(Event(1, iNombre, 0));
    }
  }

  int t;
  cin >> t;
  t--;

  vector<int> forcees;
  for(int iFois = 0;iFois < 2 * nbNombres;iFois++) {
    if(t == 0) {
      if(!forcees.empty()) {
	cout << forcees.back() + 1 << endl;
	sontPris[forcees.back()] = true;
	cout.flush();
	forcees.clear();
      }
      else {
	while(sontPris[events.top().a]) {
	  events.pop();
	}
	cout << events.top().a + 1 << endl;
	sontPris[events.top().a] = true;
	cout.flush();
      }
    }
    else {
      int rep;
      cin >> rep;
      rep--;

      if(dansPaire[rep] && !sontPris[autres[rep]]) {
	forcees.push_back(autres[rep]);
      }
      
      sontPris[rep] = true;
    }
    t = !t;
  }
  return 0;
}