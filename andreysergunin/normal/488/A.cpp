#include<bits/stdc++.h>

using namespace std;


bool lucky(long long a)
{
    bool f = false;
    while (a > 0)
    {
        if (a % 10 == 8)
            f = true;
        a /= 10;
    }
    return f;
}

int main()
{
    long long a, b;
    cin >> a;
    b = a + 1;
    while (!lucky(abs(b)))
        b++;
    cout << b - a;
    return 0;
}