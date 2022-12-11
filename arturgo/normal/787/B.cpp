#include <iostream>
#include <set>
using namespace std;

bool estCorrect() {
    int nbPersonnes;
    cin >> nbPersonnes;
    
    set<int> personnes;
    bool correct = false;
    
    for(int i = 0;i < nbPersonnes;i++) {
        int p;
        cin >> p;
        
        if(personnes.find(-p) != personnes.end()) {
            correct = true;
        }
        
        personnes.insert(p);
    }
    
    return correct;
}

int main() {
    int nbUnivers, nbGroupes;
    cin >> nbUnivers >> nbGroupes;
    
    string finDuMonde = "NO";
    for(int iGroupe = 0;iGroupe < nbGroupes;iGroupe++) {
        if(!estCorrect()) {
            finDuMonde = "YES";
        }
    }
    
    cout << finDuMonde << endl;
}