#include <iostream>
#include <cmath>

using namespace std;

int s(int x) {
    return (x * (x + 1)) / 2;
}

int main()
{
    int a, b;
    cin >> a >> b;
    int x = (a + b) / 2;
    cout << s(abs(x - a)) + s(abs(x - b));
    return 0;
}