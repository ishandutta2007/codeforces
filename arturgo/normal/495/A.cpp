#include <iostream>
using namespace std;

int transforme[10] = {2, 7, 2, 3 ,3 ,4 ,2 ,5 ,1, 2};
char a, b;

void lireEntree()
{
    cin >> a >> b;
}

int main()
{
    lireEntree();
    cout << transforme[a - '0'] * transforme[b - '0'] << endl;
    return 0;
}