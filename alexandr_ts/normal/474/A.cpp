#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;

main()
{
    char c;
    cin >> c;
    string s;
    cin >> s;
    string s1, s2, s3;
    s1 = "qwertyuiop", s2 = "asdfghjkl;", s3 = "zxcvbnm,./";
    if (c == 'R')
    {
        for (int i = 0; i < (int)s.size(); i++)
        {
            for (int j = 0; j < s1.size(); j++)
                if (s[i] == s1[j])
                {
                    s[i] = s1[j - 1];
                    break;
                }
            for (int j = 0; j < s2.size(); j++)
                if (s[i] == s2[j])
                {
                    s[i] = s2[j - 1];
                    break;
                }
            for (int j = 0; j < s3.size(); j++)
                if (s[i] == s3[j])
                {
                    s[i] = s3[j - 1];
                    break;
                }
        }
    }
    else
    {
        for (int i = 0; i < (int)s.size(); i++)
        {
            for (int j = 0; j < s1.size(); j++)
                if (s[i] == s1[j])
                {
                    s[i] = s1[j + 1];
                    break;
                }
            for (int j = 0; j < s2.size(); j++)
                if (s[i] == s2[j])
                {
                    s[i] = s2[j + 1];
                    break;
                }
            for (int j = 0; j < s3.size(); j++)
                if (s[i] == s3[j])
                {
                    s[i] = s3[j + 1];
                    break;
                }
        }
    }
    cout << s;
    return 0;
}