#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s;
    int k;
    cin >> s;
    cin >> k;
    if ((s == "front" && k == 1) || (s != "front" && k == 2))
        cout << 'L';
    else
        cout << 'R';

    return 0;
}