#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int a[1000000];

int main()
{
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
        if(i % 2 == 0)
            a[i / 2] = (int)s[i] - '0';
    sort(a, a + s.size() / 2 + 1);
    cout << a[0];
    for(int i = 1; i < s.size() / 2 + 1; i++)
        cout << "+" << a[i];
    return 0;
}