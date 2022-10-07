#include <iostream>

using namespace std;

int main()
{
    int x1, x2, x3, y1, y2, y3;
    cin >> x1 >> x2 >> x3;
    cin >> y1 >> y2 >> y3;
    if (x1+y1==1 && x2+y2==1 && x3 + y3 == 1)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}