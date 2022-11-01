#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

const long double EPS = 1e-9;

int a[1000000];

int main()
{
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    bool er = false;
    if(s1.size() != s2.size())
        er = true;
    bool found1 = false;
    for(int i = 0; i < s1.size(); i++)
        if(s1[i] == '1')
            found1 = true;
    if(!found1)
        er = true;
    bool found0 = false;
    for(int i = 0; i < s2.size(); i++)
        if(s2[i] == '1')
            found0 = true;
    if(!found0)
        er = true;
    if(s1 == s2)
        er = false;
    if(er)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}