#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long a1, b1, a2, b2;

long long nbFact2(long long nb)
{
    long long ret = 0;
    while(nb % 2 == 0)
    {
        ret++;
        nb /= 2;
    }
    return ret;
}

long long nbFact3(long long nb)
{
    long long ret = 0;
    while(nb % 3 == 0)
    {
        ret++;
        nb /= 3;
    }
    return ret;
}

long long dim(long long nb)
{
    while(nb % 2 == 0)
        nb /= 2;
    while(nb % 3 == 0)
        nb /= 3;
    return nb;
}

int main()
{
    cin >> a1 >> b1 >> a2 >> b2;

    long long prod1 = a1 * b1;
    long long prod2 = a2 * b2;
    if(dim(prod1) == dim(prod2))
    {
        long long taille = 0;
        while(nbFact3(prod1) > nbFact3(prod2))
        {
            prod1 = (prod1 / 3) * 2;
            if(a1 % 3 == 0)
                a1 = (a1 / 3) * 2;
            else
                b1 = (b1 / 3) * 2;
            taille++;
        }
        while(nbFact3(prod1) < nbFact3(prod2))
        {
            prod2 = (prod2 / 3) * 2;
            if(a2 % 3 == 0)
                a2 = (a2 / 3) * 2;
            else
                b2 = (b2 / 3) * 2;
            taille++;
        }
        while(nbFact2(prod1) > nbFact2(prod2))
        {
            prod1 /= 2;
            if(a1 % 2 == 0)
                a1 /= 2;
            else
                b1 /= 2;
            taille++;
        }
        while(nbFact2(prod1) < nbFact2(prod2))
        {
            prod2 /= 2;
            if(a2 % 2 == 0)
                a2 /= 2;
            else
                b2 /= 2;
            taille++;
        }
        cout << taille << endl;
        cout << a1 << " " << b1 << endl;
        cout << a2 << " " << b2 << endl;
    }
    else
        cout << -1 << endl;
    return 0;
}