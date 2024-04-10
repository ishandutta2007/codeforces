#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define int long long
using namespace std;

struct Req {
  int taille, id;
  Req(int _taille = 0, int _id = 0) {
    taille = _taille;
    id = _id;
  }
};

bool operator < (const Req& a, const Req& b) {
  return a.taille < b.taille;
}

int hauteurs[100 * 1000];
int ecarts[100 * 1000];
int reponses[100 * 1000];

int32_t main() {
  ios_base::sync_with_stdio(false);
  
  int nbCordes;
  cin >> nbCordes;
  
  for(int iCorde = 0;iCorde < nbCordes;iCorde++) {
    cin >> hauteurs[iCorde];
  }
  
  sort(hauteurs, hauteurs + nbCordes);
  
  for(int iHauteur = 0;iHauteur < nbCordes - 1;iHauteur++) {
    ecarts[iHauteur] = hauteurs[iHauteur + 1] - hauteurs[iHauteur];
  }
  
  sort(ecarts, ecarts + nbCordes - 1);
  
  int nbReqs;
  cin >> nbReqs;
  
  vector<Req> reqs;
  for(int iReq = 0;iReq < nbReqs;iReq++) {
    int deb, fin;
    cin >> deb >> fin;
    fin++;
    
    reqs.push_back(Req(fin - deb, iReq));
  }
  
  sort(reqs.begin(), reqs.end());
  
  int nbLibres = nbCordes, sommeReste = 0;
  int curEcart = 0;
  
  for(int iReq = 0;iReq < nbReqs;iReq++) {
    while(curEcart != nbCordes - 1 && ecarts[curEcart] <= reqs[iReq].taille) {
      sommeReste += ecarts[curEcart];
      nbLibres--;
      curEcart++;
    }
    reponses[reqs[iReq].id] = nbLibres * reqs[iReq].taille + sommeReste;
  }
  
  for(int iReq = 0;iReq < nbReqs;iReq++) {
    cout << reponses[iReq] << " ";
  }
  cout << endl;
  return 0;
}