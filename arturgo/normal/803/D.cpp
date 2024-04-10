#include <iostream>
#include <vector>
using namespace std;

int maxLigne;
vector<int> blocs;

int main() {
    cin >> maxLigne;
    cin.ignore();
    
    string chaine;
    getline(cin, chaine);
    
    int debut = 0;
    
    int lastBreak = -1;
    for(int iCar = 0;iCar < (int)chaine.size();iCar++) {
        if(chaine[iCar] == ' ' || chaine[iCar] == '-') {
            blocs.push_back(iCar - lastBreak);
            lastBreak = iCar;
        }
    }
    
    blocs.push_back((int)chaine.size() - lastBreak - 1);
    
    for(int bloc : blocs) {
    	debut = max(debut, bloc);
    }
    
    debut--;
    int fin = 1000 * 1000;
    while(debut + 1 < fin) {
        int mil = (debut + fin) / 2;
        
        int nbLignes = 0;
        int curSomme = mil;
        
        for(int bloc : blocs) {
            if(curSomme + bloc > mil) {
                nbLignes++;
                curSomme = 0;
            }
            curSomme += bloc;
        }
        
        if(nbLignes <= maxLigne) {
            fin = mil;
        }
        else {
            debut = mil;
        }
    }
    
    cout << fin << endl;
    return 0;
}