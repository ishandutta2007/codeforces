#include <iostream>

#define lint long long int
using namespace std;

lint fib[55];

int main()
{
    fib[0] = 1;
    fib[1] = 1;
    fib[2] = 2;

    for (int i = 3; i <= 51; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    int n = 0;
    cin >> n;

    lint k = 0;
    cin >> k;

    for (int i = 1; i <= n; i++) {
        //cout << "suntem la " << i << " cu " << k << endl;
        //cout << "alea normale dau ca sunt " << n - i << " numere cu " << fib[n - i] << " posibs " << endl;

        //Avem fib[i - 1]
        if (k > fib[n - i]) {
            cout << i + 1 << ' ' << i << ' ';
                k -= fib[n - i];

            i ++;

        }
        else
            cout << i << ' ';

        //Avem apoi fib[i - 2]

    }

    cout << endl;
    return 0;
}