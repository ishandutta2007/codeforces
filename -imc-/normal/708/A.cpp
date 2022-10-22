#include <bits/stdc++.h>

using namespace std;

void shift(char& c)
{
    if (c == 'a')
        c = 'z';
    else
        c--;
}

int main()
{
    string s;
    cin >> s;
    
    int n = s.length();
    int pos = 0;
    
    while (pos < n && s[pos] == 'a') pos++;
    
    if (pos == n)
    {
        shift(s[pos - 1]);
    }
    else
    {
        int pos2 = pos;
        
        while (pos2 < n && s[pos2] != 'a') pos2++;
        
        for (int i = pos; i < pos2; i++)
            shift(s[i]);
    }
    
    printf("%s\n", s.c_str());
    
    return 0;
}