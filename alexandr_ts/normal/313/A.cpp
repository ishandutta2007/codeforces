#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string s;
    cin >> s;
    if(s[0] != '-')
    {
        cout << s;
        return 0;
    }
    if(s.size() == 2)
    {
        cout << 0;
        return 0;
    }
    if((s[s.size() - 1] == '0' || s[s.size() - 2] == '0') && (s.size() == 3))
    {
        cout << 0;
        return 0;
    }
    if(s[s.size() - 1] < s[s.size() - 2])
    {
        for(int i = 0; i < s.size() - 2; i++)
            cout << s[i];
        cout << s[s.size() - 1];
    }
    else
    {
        for(int i = 0; i < s.size() - 1; i++)
            cout << s[i];
    }
    return 0;
}