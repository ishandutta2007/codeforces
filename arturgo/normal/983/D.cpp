#include <map>
#include <set>
#include <vector>
#include <iostream>
using namespace std;

const int MAX_NB_RECTS = 200 * 1000;
const int ADD = 0, ERASE = 1, VOID = 2;

struct Point {
  int x, y;
  Point(int _x = 0, int _y = 0) {
    x = _x;
    y = _y;
  }
};

struct Noeud {
  set<int> couleurs;
  int maxi, mini;
};

int nbX = 0, nbY = 0;
map<int, int> xs, ys;
vector<pair<Point, Point>> rects;
vector<pair<int, int>> events[MAX_NB_RECTS * 2];
Noeud arbre[(1 << 19)];
bool estVisible[(1 << 19)];

void compute(int noeud, int deb, int fin, int action, int rect) {
  arbre[noeud].mini = -1;
  if(noeud < (1 << 18))
    arbre[noeud].mini = min(arbre[2 * noeud].mini, arbre[2 * noeud + 1].mini);
  arbre[noeud].mini = max(arbre[noeud].mini, *arbre[noeud].couleurs.rbegin());
  
  arbre[noeud].maxi = -1;
  if(noeud < (1 << 18))
    arbre[noeud].maxi = max(arbre[2 * noeud].maxi, arbre[2 * noeud + 1].maxi);
  arbre[noeud].maxi = max(arbre[noeud].maxi, *arbre[noeud].couleurs.rbegin());
  
  if(arbre[noeud].maxi < arbre[noeud].mini || estVisible[arbre[noeud].maxi])
    arbre[noeud].maxi = -1;
}

void update(int noeud, int deb, int fin, int action, int rect, int _deb = 0, int _fin = (1 << 18)) {
  if(_fin <= deb || _deb >= fin)
    return;
  compute(noeud, _deb, _fin, action, rect);
  if(deb <= _deb && _fin <= fin) {
    if(action == ADD) {
      arbre[noeud].couleurs.insert(rect);
    }
    if(action == ERASE) {
      arbre[noeud].couleurs.erase(rect);
    }
    compute(noeud, _deb, _fin, action, rect);
    return;
  }
  
  int _mil = (_deb + _fin) / 2;
  update(2 * noeud, deb, fin, action, rect, _deb, _mil);
  update(2 * noeud + 1, deb, fin, action, rect, _mil, _fin);
  compute(noeud, _deb, _fin, action, rect);
}

int main() {
  ios_base::sync_with_stdio(false);
  int nbRects;
  cin >> nbRects;

  for(int iRect = 0;iRect < nbRects;iRect++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    xs[x1] = xs[x2] = ys[y1] = ys[y2] = 0;
    rects.push_back({Point(x1, y1), Point(x2, y2)});
  }

  for(pair<const int, int>& x : xs) {
    x.second = nbX++;
  }

  for(pair<const int, int>& y : ys) {
    y.second = nbY++;
  }

  for(int iNoeud = 0;iNoeud < (1 << 19);iNoeud++) {
    arbre[iNoeud].maxi = -1;
    arbre[iNoeud].couleurs.insert(-1);
  }
  
  int iRect = 0;
  for(pair<Point, Point>& rect : rects) {
    rect.first.x = xs[rect.first.x];
    rect.second.x = xs[rect.second.x];
    rect.first.y = ys[rect.first.y];
    rect.second.y = ys[rect.second.y];
    events[rect.first.x].push_back({iRect, ADD});
    events[rect.second.x].push_back({iRect, ERASE});
    iRect++;
  }

  for(int x = 0;x < 2 * MAX_NB_RECTS;x++) {
    for(pair<int, int> event : events[x]) {
      update(1, rects[event.first].first.y, rects[event.first].second.y, event.second, event.first);
    }
    
    while(arbre[1].maxi != -1) {
      estVisible[arbre[1].maxi] = true;
      //cout << arbre[1].maxi << endl;
      update(1, rects[arbre[1].maxi].first.y, rects[arbre[1].maxi].second.y, VOID, arbre[1].maxi);
    }
  }

  int nbVisibles = 1;
  for(int iRect = 0;iRect < nbRects;iRect++) {
    if(estVisible[iRect])
      nbVisibles++;
  }

  cout << nbVisibles << endl;
  return 0;
}