#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int a[1000000];

int main()
{
    int n;
    string s;
    cin >> s;
    if(s[0] >= 'a' && s[0] <= 'z')
        s[0] += 'A' - 'a';
    cout << s;

    return 0;
}