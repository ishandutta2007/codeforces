#include <iostream>
#include <algorithm>

using namespace std;

void normal(int &x) {
    x %= 360;
    x += 360;
    x %= 360;
}

int dist(int x) {
    return min(360 - x, x);
}

int main()
{
    long long int _x;
    cin >> _x;
    _x %= 360;

    int x = _x;
    normal(x);
    int a = x - 90;
    normal(a);
    int b = x - 180;
    normal(b);
    int c = x - 270;
    normal(c);

    if (dist(x) <= dist(a) && dist(x) <= dist(b) && dist(x) <= dist(c)) {
        cout << "0\n";
        return 0;
    }

    if (dist(a) <= dist(x) && dist(a) <= dist(b) && dist(a) <= dist(c)) {
        cout << "1\n";
        return 0;
    }

    if (dist(b) <= dist(x) && dist(b) <= dist(a) && dist(b) <= dist(c)) {
        cout << "2\n";
        return 0;
    }

    if (dist(c) <= dist(x) && dist(c) <= dist(a) && dist(c) <= dist(b)) {
        cout << "3\n";
        return 0;
    }

    return 0;
}