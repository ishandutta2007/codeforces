#include <bits/stdc++.h>
using namespace std;

set<int> arr[100010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        arr[x].insert(y);
        arr[y].insert(x);
    }

    set<int> s;
    for(int i = 1; i <= n; i++)
        s.insert(i);

    int res = -1;
    while(!s.empty())
    {
        res++;

        queue<int> q;
        q.push(*s.begin());
        s.erase(s.begin());
        while(!q.empty())
        {
            int x = q.front();
            q.pop();

            auto it1 = s.begin();
            auto it2 = arr[x].begin();

            vector<int> v;
            while(it1 != s.end())
            {
                if(it2 == arr[x].end() || *it2 > *it1)
                {
                    q.push(*it1);
                    it1++;
                    s.erase(prev(it1));
                }
                else if(*it1 == *it2)
                {
                    it1++;
                    it2++;
                }
                else
                {
                    it2++;
                }
            }
        }
    }
    
    printf("%d\n", res);
    return 0;
}