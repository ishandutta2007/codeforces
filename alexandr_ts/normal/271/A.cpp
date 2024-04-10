#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int a[1000000];

int main()
{
    string s;
    int n;
    cin >> n;
    bool er = false;
    while(!er)
    {
        n++;
        s = n / 1000 - '0';
        s += n / 100 % 10 - '0';
        s += n / 10 % 10 - '0';
        s += n % 10 - '0';
        if(s[0] != s[1] && s[0] != s[2] && s[0] != s[3] && s[1] != s[2] && s[1] != s[3] && s[2] != s[3])
            er = true;
    }
    cout << n;
    return 0;
}