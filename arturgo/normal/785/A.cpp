#include <iostream>
using namespace std;

int tab[256];

int main() {
    tab[(int)'T'] = 4;
    tab[(int)'C'] = 6;
    tab[(int)'O'] = 8;
    tab[(int)'D'] = 12;
    tab[(int)'I'] = 20;
    
    int nbObjects;
    cin >> nbObjects;
    
    int nbFaces = 0;
    
    for(int i = 0;i < nbObjects;i++) {
        string name;
        cin >> name;
        nbFaces += tab[(int)name[0]];
    }
    
    cout << nbFaces << endl;
}