#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, q;
    scanf("%d %d %d", &n, &k, &q);
    
    vector<int> t(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]);
    
    set<pair<int, int>> s;
    for (int i = 0; i < q; i++)
    {
        int type, id;
        scanf("%d %d", &type, &id);
        id--;
        
        if (type == 1)
            s.insert(make_pair(-t[id], id));
        else
        {
            auto it = s.begin();
            bool found = false;
            for (int i = 0; i < k; i++)
            {
                if (it == s.end()) break;
                if (it->second == id)
                {
                    found = true;
                    break;
                }
                
                it++;
            }
            
            printf("%s\n", found ? "YES" : "NO");
        }
    }
    
    return 0;
}