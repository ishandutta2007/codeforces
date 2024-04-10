#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int nbCars;
string s;
bool rest[100001];

void lireEntree()
{
    cin >> s;
    nbCars = s.size();
}

void reponse()
{
    int nbResteF = 0, nbResteO = 0;
    for(int iCar = nbCars - 1;iCar >= 0;iCar--)
        rest[iCar] = rest[iCar + 1] || (s[iCar + 1] == '#');

    for(int iCar = nbCars - 1;iCar >= 0 && s[iCar] != '#';iCar--)
    {
        if(s[iCar] == '(' && nbResteF != 0)
            nbResteF--;
        else if(s[iCar] == '(')
        {
            cout << -1 << endl;
            return;
        }
        else
            nbResteF++;
    }

    vector<int> rep;
    for(int iCar = 0;iCar < nbCars && rest[iCar];iCar++)
    {
        if(s[iCar] == ')' && nbResteO != 0)
            nbResteO--;
        else if(s[iCar] == '#' && nbResteO != 0)
        {
            nbResteO--;
            rep.push_back(1);
        }
        else if(s[iCar] == ')' || s[iCar] == '#')
        {
            cout << -1 << endl;
            return;
        }
        else if(s[iCar] == '(')
            nbResteO++;
    }

    if(nbResteO <= nbResteF)
    {
        cout << -1 << endl;
        return;
    }

    rep.push_back(nbResteO - nbResteF);

    for(int i = 0;i < (int)rep.size();i++)
        cout << rep[i] << endl;
}

int main()
{
    lireEntree();
    reponse();
    return 0;
}