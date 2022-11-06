#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n = 0;
    vector<int> a(4);
    for(int i = 0; i < 4; i++)
    {
        scanf("%d", &a[i]);
        n += a[i];
    }

    for(int s = 0; s < 4; s++)
    {
        vector<int> v = a;
        int p = s;

        if(v[p] == 0)
            continue;

        v[p]--;

        bool ok = 1;
        vector<int> res;
        res.push_back(p);
        for(int i = 0; i < n - 1; i++)
        {
            int t;
            if(p == 0)
                t = 1;
            else if(p == 3)
                t = 2;
            else if(p == 1)
            {
                if(v[0])
                    t = 0;
                else
                    t = 2;
            }
            else
            {
                if(v[3])
                    t = 3;
                else
                    t = 1;
            }

            if(v[t] == 0)
            {
                ok = 0;
                break;
            }

            v[t]--;
            res.push_back(t);
            p = t;
        }
        if(ok)
        {
            puts("YES");
            for(int x : res)
                printf("%d ", x);
            puts("");
            return 0;
        }
    }

    puts("NO");
    return 0;
}