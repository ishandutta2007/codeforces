#include <iostream>
#include <string>
using namespace std;

int applis[200 * 1000];
int ordre[200 * 1000];

int main()
{
    int nbApplis, nbRuns, nbSurPage;
    cin >> nbApplis >> nbRuns >> nbSurPage;

    for(int iAppli = 0;iAppli < nbApplis;iAppli++)
    {
        cin >> applis[iAppli];
        ordre[applis[iAppli]] = iAppli;
    }

    long long nbGestes = 0;
    int idAppli;
    for(int iRun = 0;iRun < nbRuns;iRun++)
    {
        cin >> idAppli;
        nbGestes += (long long)(1 + (ordre[idAppli] / nbSurPage));

        if(ordre[idAppli] != 0)
        {
            int temp = applis[ordre[idAppli] - 1];
            ordre[applis[ordre[idAppli] - 1]]++;
            ordre[idAppli]--;
            applis[ordre[idAppli]] = idAppli;
            applis[ordre[idAppli] + 1] = temp;
        }
    }
    cout << nbGestes << endl;
}