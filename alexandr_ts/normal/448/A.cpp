#include <iostream>

using namespace std;

int main()
{
    int a1, a2, a3, b1, b2, b3, n;
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> n;
    int a = a1 + a2 + a3;
    int b = b1 + b2 + b3;
    int aa = (a - 1) / 5 + 1;    int bb = (b - 1) / 10 + 1;
    if (a == 0)
        aa = 0;
    if (b == 0)
        bb = 0;

    if (aa + bb > n)
        cout << "NO"; else cout << "YES";
    //cout << endl << aa + bb;
    return 0;
}