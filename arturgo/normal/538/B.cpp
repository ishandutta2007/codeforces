#include <iostream>
using namespace std;

int decomp[10];

int main()
{
    int a;
    cin >> a;

    int maxChiffre = 0;
    int prod = 1;

    while(a != 0)
    {
        maxChiffre = max(maxChiffre, a % 10);
        for(int i = 0;i < a % 10;i++)
            decomp[i] += prod;
        prod *= 10;
        a /= 10;
    }

    cout << maxChiffre << endl;

    for(int i = 0; i < maxChiffre;i++)
        cout << decomp[i] << " ";
}