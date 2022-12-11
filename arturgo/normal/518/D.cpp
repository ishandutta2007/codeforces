#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int nbPersonnes, t;
long double prob;

long double probs[4000][4000];
bool passage[4000][4000];

long double estimation(int per, int tem)
{
    if(per == 0)
        return 0;
    if(tem == 0)
        return 0;

    if(!passage[per][tem])
    {
        probs[per][tem] = prob * (estimation(per - 1, tem - 1) + 1) + (1 - prob) * estimation(per, tem - 1);
        passage[per][tem] = true;
    }
    return probs[per][tem];
}

int main()
{
    string s = "";
    cin >> s >> prob >> t;
    if(s.size() < 5)
    {
        nbPersonnes = 0;
        for(int iCar = 0;iCar < (int)s.size();iCar++)
        {
            nbPersonnes *= 10;
            nbPersonnes += s[iCar] - '0';
        }
    }
    else
    {
        nbPersonnes = t + 1;
    }
    nbPersonnes = min(nbPersonnes, t + 1);
    long double es = estimation(nbPersonnes, t);
    cout << fixed << setprecision(8);
    cout << es;
}