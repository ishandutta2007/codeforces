#include <conio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++){
        cin >> a;
        int n = a.length();
        if (n > 10)
            cout << a[0] << n-2 << a[n-1] << endl;
        else
            cout << a << endl;
    }

}