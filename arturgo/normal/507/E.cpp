#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
using namespace std;

struct Route
{
    int fin, etat, debut;
    Route(int _fin = 0, int _etat = 0, int _debut = 0)
    {
        fin = _fin;
        etat = _etat;
        debut = _debut;
    }
};

bool operator < (const Route &a, const Route &b)
{
    if(a.debut == b.debut)
        return a.fin < b.fin;
    return a.debut < b.debut;
}

struct Event
{
    int noeud, dist, nbBons, der;
    Event(int _noeud = 0, int _dist = 0, int _nbBons = 0, int _der = 0)
    {
        noeud = _noeud;
        dist = _dist;
        nbBons = _nbBons;
        der = _der;
    }
};

bool operator < (const Event &a, const Event &b)
{
    if(a.dist == b.dist)
        return a.nbBons < b.nbBons;
    return a.dist > b.dist;
}

int nbVilles, nbRoutes;
vector<Route> voisins[100001];

Event mels[100001];
bool passage[100001];

void lireEntree()
{
    cin.sync_with_stdio(false);
    cin >> nbVilles >> nbRoutes;

    int debut, fin, etat;
    for(int iRoute = 0;iRoute < nbRoutes;iRoute++)
    {
        cin >> debut >> fin >> etat;
        voisins[debut].push_back(Route(fin, etat));
        voisins[fin].push_back(Route(debut, etat));
    }
}

void calculMeilleur()
{
    priority_queue<Event> events;
    events.push(Event(1, 0, 0, 0));

    while(!events.empty())
    {
        Event cur = events.top();
        events.pop();

        if(passage[cur.noeud])
            continue;
        passage[cur.noeud] = true;
        mels[cur.noeud] = cur;

        for(int iVoisin = 0;iVoisin < (int)voisins[cur.noeud].size();iVoisin++)
            events.push(Event(voisins[cur.noeud][iVoisin].fin, cur.dist + 1, cur.nbBons + voisins[cur.noeud][iVoisin].etat, cur.noeud));
    }
}

int main()
{
    lireEntree();
    calculMeilleur();
    set<Route> routesChange;
    for(int iVille = 0;iVille <= nbVilles;iVille++)
        for(int iVoisin = 0;iVoisin < (int)voisins[iVille].size();iVoisin++)
            if(iVille > voisins[iVille][iVoisin].fin && voisins[iVille][iVoisin].etat == 1)
                routesChange.insert(Route(voisins[iVille][iVoisin].fin, 0, iVille));

    int curNoeud = nbVilles;
    while(curNoeud != 1)
    {
        int proNoeud = mels[curNoeud].der;
        if(mels[curNoeud].nbBons - mels[proNoeud].nbBons == 1)
        {
            if(routesChange.find(Route(proNoeud, 0, curNoeud)) != routesChange.end())
                routesChange.erase(Route(proNoeud, 0, curNoeud));
            if(routesChange.find(Route(curNoeud, 0, proNoeud)) != routesChange.end())
                routesChange.erase(Route(curNoeud, 0, proNoeud));
        }
        else
        {
            routesChange.insert(Route(proNoeud, 1, curNoeud));
        }
        curNoeud = proNoeud;
    }

    cout << routesChange.size() << "\n";
    set<Route>::iterator it = routesChange.begin();
    while(it != routesChange.end())
    {
        cout << it->debut << " " << it->fin << " " << it->etat << "\n";
        it++;
    }
    return 0;
}