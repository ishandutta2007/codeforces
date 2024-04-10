#include <iostream>

using namespace std;

/*int n1,n2;
int k1,k2;

int din[2][55][55];

int rec (bool move, int n1, int n2) {
    if(din[n1][n2])
        return din[n1][n2];

    if(!n1) {
        din[n1][n2]=2;
        return din[n1][n2];
    }
    else if(!n2) {
        din[n1][n2]=1;
        return din[n1][n2];
    }
}*/

int main()
{
    int n1,n2;
    cin>>n1>>n2;

    if(n1>n2)
        cout<<"First\n";
    else
        cout<<"Second\n";
    return 0;
}