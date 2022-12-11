#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <list>
#include <set>
using namespace std;

struct Ouvert
{
    int depuis, id;
    Ouvert(int _depuis = 0, int _id = 0)
    {
        depuis = _depuis;
        id = _id;
    }
};

int main()
{
    int nbRequetes, maxPersonnes, tempsReste;
    cin >> nbRequetes >> maxPersonnes >> tempsReste;

    vector<int> heures;

    for(int iRequete = 0;iRequete < nbRequetes;iRequete++)
    {
        int heure, minute, seconde;
        cin >> heure; cin.ignore();
        cin >> minute; cin.ignore();
        cin >> seconde;

        heures.push_back(heure * 3600 + minute * 60 + seconde);
    }

    list<Ouvert> ouvertes;
    int nbIds = 0;

    vector<int> ids;
    bool possible = false;

    for(int iRequete = 0;iRequete < nbRequetes;iRequete++)
    {
        while(!ouvertes.empty() && heures[iRequete] >= ouvertes.front().depuis + tempsReste)
            ouvertes.pop_front();

        if((int)ouvertes.size() != maxPersonnes)
        {
            nbIds++;
            ouvertes.push_back(Ouvert(heures[iRequete], nbIds));
            ids.push_back(nbIds);
            if((int)ouvertes.size() == maxPersonnes)
                possible = true;
        }
        else if((int)ouvertes.size() == maxPersonnes)
        {
            int derId = ouvertes.back().id;
            ouvertes.pop_back();
            ouvertes.push_back(Ouvert(heures[iRequete], derId));
            ids.push_back(derId);
        }
    }

    if(possible)
    {
        cout << nbIds << endl;
        for(int iRequete = 0;iRequete < nbRequetes;iRequete++)
            cout << ids[iRequete] << endl;
    }
    else
        cout << "No solution" << endl;

    return 0;
}