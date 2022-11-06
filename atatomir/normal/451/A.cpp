#include <iostream>

using namespace std;

long n,m,i=1;

int main()
{
    cin >> n >> m;

    while (n*m != 0) {
        n--; m--;
        i ^= 1;
    }

    if(!i) cout << "Akshat" ; else cout << "Malvika";

    return 0;
}