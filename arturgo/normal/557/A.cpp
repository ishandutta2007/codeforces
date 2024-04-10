#include <iostream>
using namespace std;

int debuts[3], maxi[3];

int main()
{
    int nbParticipants;
    cin >> nbParticipants;
    
    for(int iNiv = 0;iNiv < 3;iNiv++)
    {
        cin >> debuts[iNiv] >> maxi[iNiv];
        nbParticipants -= debuts[iNiv];
    }
    
    for(int iParticipant = 0;iParticipant < nbParticipants;iParticipant++)
    {
        if(debuts[0] != maxi[0])
            debuts[0]++;
        else if(debuts[1] != maxi[1])
            debuts[1]++;
        else
            debuts[2]++;
    }
    
    cout << debuts[0] << " " << debuts[1] << " " << debuts[2] << endl;
    return 0;
}