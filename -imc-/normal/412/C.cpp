#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    string answer;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        
        if (i == 0)
            answer = string(s.size(), '$');
        for (int j = 0; j < (int)s.size(); j++)
        {
            if (s[j] == '?') continue;
            if (answer[j] == '$' || answer[j] == s[j])
                answer[j] = s[j];
            else
                answer[j] = '?';
        }
    }
    
    for (auto& c: answer)
        if (c == '$')
            c = 'a';
    
    cout << answer << endl;
    
    return 0;
}