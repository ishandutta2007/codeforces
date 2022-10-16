#include <iostream>
#include <cmath>

#define lint long long int
using namespace std;

lint get(lint n, lint k) {
    return n / k + 1;
}

int main()
{
    lint k, a, b;
    cin >> k >> a >> b;

    if (!a || !b)
        cout << get(abs(a) + abs(b), k) << '\n';
    else if (b < 0)
        cout << get(abs(a), k) - get(abs(b) - 1, k) << '\n';
    else if (a > 0)
        cout << get(abs(b), k) - get(abs(a) - 1, k) << '\n';
    else
        cout << get(abs(a), k) + get(abs(b), k) - 1 << '\n';

    return 0;
}