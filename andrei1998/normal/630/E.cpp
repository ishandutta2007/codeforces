#include <iostream>
#include <cassert>

#define lint long long int
using namespace std;

int main()
{
    lint x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    lint pe_rand = (y2 - y1 + 1) / 2;
    if ((y1 % 2 + 10) % 2 != (y2 % 2 + 10) % 2) {
        cout << (x2 - x1 + 1ll) * pe_rand << endl;
        return 0;
    }

    //Daca trece prin 2 centre
    if ((x1 + y1 + 10) % 2 == 0)
        cout << (x2 - x1 + 1ll) * pe_rand + (x2 - x1) / 2 + 1ll << endl;
    else {
        cout << (x2 - x1 + 1ll) * pe_rand + (x2 - x1) / 2 + 1ll<< endl;
    }
    return 0;
}