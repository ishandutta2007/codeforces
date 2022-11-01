#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
string s;

int rec(int cur)
{
    if(cur < 0)
        return 0;
    int cur1 = cur;
    while(s[cur1] == '0')
        cur1--;
    int bol = 0;
    if(cur1 > cur - cur1 + 1)
        bol = 1;
    else
    if(cur1 < cur - cur1 + 1)
        bol = 2;
    else
    for(int i = 0; i < cur1; i++)
    {
        if(s[i] < s[i + cur1])
        {
            bol = 2;
            break;
        }
        if(s[i] > s[i + cur1])
        {
            bol = 1;
            break;
        }
    }
    if(bol == 2)
        return 1;
    else
        return 1 + rec(cur1 - 1);
}

int main()
{
    cin >> s;
    cout << rec(s.size() - 1);
    return 0;
}