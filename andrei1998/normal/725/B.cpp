#include <iostream>

using namespace std;

int main()
{
    long long int N;
    char ch;
    cin >> N >> ch;

    N --;

    long long int ans = (N / 4) * 16;
    N %= 4;

    if (N == 1 || N == 3)
        ans += 7;

    if (ch == 'f')
        ans += 1;
    else if (ch == 'e')
        ans += 2;
    else if (ch == 'd')
        ans += 3;
    else if (ch == 'a')
        ans += 4;
    else if (ch == 'b')
        ans += 5;
    else if (ch == 'c')
        ans += 6;

    cout << ans << '\n';
    return 0;
}