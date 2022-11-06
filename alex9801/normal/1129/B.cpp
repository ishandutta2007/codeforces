#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int k, i;
    scanf("%d", &k);

    vector<int> r;
    r.push_back(1);
    r.push_back(-2);
    if(k % 2 == 1)
    {
        int l = 1997;
        int b = (k + 2 + l) / 2;
        for(i = 0; i < l; i++)
        {
            int t = min(1000000, b);
            r.push_back(t);
            b -= t;
        }
    }
    else
    {
        int l = 1998;
        int b = (k + 2 + l) / 2;
        for(i = 0; i < l; i++)
        {
            int t = min(1000000, b);
            r.push_back(t);
            b -= t;
        }
    }

    printf("%d\n", (int)r.size());
    for(int x : r)
        printf("%d ", x);

    return 0;
}