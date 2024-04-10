#include <iostream>
#include <string>

using namespace std;

bool query(int n) {
    cout << n << endl;

    string ans;
    cin >> ans;

    return ans == "yes";
}

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

int main()
{
    int found = 0;
    int mult = 1;
    for (int i = 0; i < sizeof(primes) / sizeof(int); ++ i)
        if (query(primes[i])) {
            ++ found;
            mult *= primes[i];
        }
    if (found == 0)
        cout << "prime\n";
    else if (found >= 2)
        cout << "composite\n";
    else if (mult <= 10 && query(mult * mult))
        cout << "composite\n";
    else
        cout << "prime\n";
    return 0;
}