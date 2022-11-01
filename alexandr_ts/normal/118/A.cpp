#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string s;
    cin >> s;
    string s1;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] - 'A' + 'a';
        if(s[i] == 'a' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y' || s[i] == 'e' || s[i] == 'i')
            continue;
        else
        {
            s1 += '.';
            s1 += s[i];
        }
    }
    cout << s1;
    return 0;
}