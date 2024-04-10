#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<string> pot;
    
    for (int i = 0; i < 2; i++)
    {
        string x;
        cin >> x;
        pot.insert(x);
    }
    
    int n;
    cin >> n;
    
    for (int i = 0; i <= n; i++)
    {
        for (string s: pot)
            printf("%s ", s.c_str());
        printf("\n");
        
        
        if (i == n) break;
        
        string a, b;
        cin >> a >> b;
        pot.erase(a);
        pot.insert(b);
        
    }
    
    return 0;
}