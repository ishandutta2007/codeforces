#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    int kol = 0;
    while (n > 0)
    {
        if (n % 10 == 4 || n % 10 == 7)
            kol++;
        n /= 10;
    }
    if (kol == 4 || kol == 7)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}