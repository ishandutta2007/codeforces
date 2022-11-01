#include <iostream>
#include <string>

using namespace std;

string s;

int al[27];
int a[1000000];

int main()
{
    int n, k;
    cin >> k;
    cin >> s;
    bool er = false;

    for(int i = 0; i < s.size(); i++)
        if(s[i] == '?')
            a[i] = 100;
        else
        {
            a[i] = s[i] - 'a' + 1;
            al[a[i]]++;
        }

    for(int i = s.size()/2; i >= 0; i--)
    {
        if(a[i] == 100 && a[s.size() - i - 1] == 100)
        {
            for(int j = 26; j >= 1; j--)
                if(al[j] == 0 && j <= k)
                {
                    a[i] = j;
                    a[s.size() - i - 1] = j;
                    al[j] = 2;
                    break;
                }
            if(a[i] == 100)
            {
                a[i] = 1;
                a[s.size() - i - 1] = 1;
            }
        }
        if(a[i] != 100 && a[s.size() - i - 1] != 100 && a[i] != a[s.size() - i - 1])
            er = true;
        if(a[i] == 100 && a[s.size() - i - 1] != 100)
            a[i] = a[s.size() - i - 1];
        if(a[i] != 100 && a[s.size() - i - 1] == 100)
            a[s.size() - i - 1] = a[i];
    }
    for(int i = 1; i <= k; i++)
        if(al[i] == 0)
            er = true;
    for(int i = k + 1; i <= 26; i++)
        if(al[i] != 0)
            er = true;
    if(er)
        cout << "IMPOSSIBLE";
    else
    {
        string s1;
        for(int i = 0; i < s.size(); i++)
            s1 += (char)a[i] + 'a' - 1;
        cout << s1;
    }
    cout << endl;
    return 0;
}