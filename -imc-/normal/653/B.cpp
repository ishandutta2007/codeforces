#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    
    vector<pair<char, string>> reps;
    for (int i = 0; i < q; i++)
    {
        string s;
        cin >> s;
        char c;
        scanf(" %c", &c);
        
        reps.emplace_back(c, s);
    }
    
    set<string> can = { "a" };
    for (int length = 1; length < n; length++)
    {
        set<string> newCan;
        for (string s: can)
        {
            for (int i = 0; i < q; i++)
                if (reps[i].first == s[0])
                {
                    string newS = reps[i].second + s.substr(1, s.length() - 1);
                    newCan.insert(newS);
                }
        }
        
        can = newCan;
    }
    
    printf("%d\n", (int)can.size());
    
    return 0;
}