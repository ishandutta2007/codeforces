#include <iostream>

using namespace std;

bool vowel(char c)
{
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return 1;
    else return 0;
}

int main()
{
    string s,t;
    cin >> s >> t;
    if(s.size()==t.size())
    {
        bool good=1;
        for(int i=0;i<(int)s.size();i++)
        {
            if(vowel(s[i])!=vowel(t[i]))
            {
                good=0;
                break;
            }
        }
        if(good) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else cout << "No" << endl;
    return 0;
}