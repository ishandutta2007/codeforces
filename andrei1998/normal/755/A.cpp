#include <iostream>

using namespace std;

bool prime(int nr) {
    if (nr <= 1)
        return false;
    for (int i = 2; i * i <= nr; ++ i)
        if (nr % i == 0)
            return false;
    return true;
}

int main()
{
    int N;
    cin >> N;

    for (int m = 1; m <= 1000; ++ m)
        if (!prime(N * m + 1)) {
            cout << m << '\n';
            return 0;
        }
    return 0;
}