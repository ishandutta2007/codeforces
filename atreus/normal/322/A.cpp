#include <iostream>

using namespace std;

int main ()
{
    int b, g;
    cin >> b >> g;
    if (b >= g){
        cout << b + g - 1 << endl;
    for (int i = 1; i <= b; i++)
        cout << i << " " << 1 << endl;
    for (int j = 2; j <= g; j++)
        cout << 1 << " " << j << endl;
    }
    else if (g > b){
        cout << g + b - 1 << endl;
    for (int i = 1; i <= g; i++)
        cout << 1 << " " << i << endl;
    for (int j = 2; j <= b; j++)
        cout << j << " " << 1 << endl;
    }
}