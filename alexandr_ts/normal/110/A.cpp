#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int a[1000000];

int main()
{
    string s;
    cin >> s;
    int qua = 0;
    int qua1 = 0;
    bool er = false;
    bool er1 = false;
    for(int i = 0; i < s.size(); i++)
        if(s[i] == '4' || s[i] == '7')
            qua++;
    if(qua == 0)
        er1 = true;
    while(qua > 0)
    {
        if(!(qua % 10 == 4 || qua % 10 == 7))
            er = true;
        qua /= 10;
    }
    if(er || er1)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}