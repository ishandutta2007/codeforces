#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, pos;
    
    scanf("%d %d", &n, &pos);
    pos--;
    
    static char s[256];
    scanf("%s", s);
    
    int leftFirst = pos - 0 + n - 1;
    int rightFirst = n - 1 - pos + n - 1;
    
    vector<string> actions;
    if (leftFirst < rightFirst)
    {
        for (int i = pos; i >= 0; i--)
        {
            actions.push_back(string("PRINT ") + s[i]);
            if (i != 0)
                actions.push_back("LEFT");
        }
        
        for (int i = 1; i < n; i++)
        {
            actions.push_back("RIGHT");
            if (i > pos)
                actions.push_back(string("PRINT ") + s[i]);
        }
    }
    else
    {
        for (int i = pos; i < n; i++)
        {
            actions.push_back(string("PRINT ") + s[i]);
            if (i != n - 1)
                actions.push_back("RIGHT");
        }
        
        for (int i = n - 2; i >= 0; i--)
        {
            actions.push_back("LEFT");
            if (i < pos)
                actions.push_back(string("PRINT ") + s[i]);
        }
    }
    
    //printf("%d\n", (int)actions.size());
    for (auto s: actions)
        printf("%s\n", s.c_str());
    
    return 0;
}