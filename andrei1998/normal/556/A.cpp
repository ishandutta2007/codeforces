#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    string str;
    cin >> str;

    int zero = 0, unu = 0;
    for (int i = 0; i < str.size(); i++)
        if (str[i] == '0')
            zero ++;
        else
            unu ++;

    cout << abs(zero - unu) << endl;

    return 0;
}