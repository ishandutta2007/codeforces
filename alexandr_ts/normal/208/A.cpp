#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string ans;
    string s;
    cin >> s;
    int i = 0;
    bool prob = false;
    while(i < s.size())
    {
        if(s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B')
        {
            i += 3;
            prob = true;
        }
        else
        {
            if(prob)
            {
                if(ans.size() > 0)
                    ans += ' ';
                prob = false;
            }
            ans += s[i];
            i++;
        }
    }
    cout << ans;
    return 0;
}