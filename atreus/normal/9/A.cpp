#include <iostream>

using namespace std;

int main () {
    int n, m;
    cin >> n >> m;
    int b;
    if (n >= m)
        b = n;
    else
        b = m;
    int s = 6 - b + 1;
    if (s == 1)
        cout << "1/6" << endl;
    else if (s == 2 )
        cout << "1/3" << endl;
    else if (s == 3)
        cout << "1/2" << endl;
    else if (s == 4)
        cout << "2/3" << endl;
    else if (s == 5)
        cout << "5/6" << endl;
    else if (s == 6)
        cout << "1/1" << endl;
}