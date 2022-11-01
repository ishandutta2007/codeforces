#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int a[1000000];

int main()
{
    string s;
    cin >> s;
    bool er = false;
    for(int i = 0; i < s.size(); i++)
        if(s[i] == 'H' || s[i] == '9' || s[i] == 'Q')
            er = true;
    if(er)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}