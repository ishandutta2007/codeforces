#include <iostream>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    if (n % 2 == 0)
        cout << "Marsel\n";
    else {
        bool found = false;

        for (int i = 1; i * i <= m; ++ i)
            if (m % i == 0) {
                //Impart in i parti
                if (i > 1 && m / i >= k)
                    found = true;

                //Impart in m / i parti
                if (m / i > 1 && i >= k)
                    found = true;
            }

        if (!found)
            cout << "Marsel\n";
        else
            cout << "Timur\n";
    }

    return 0;
}