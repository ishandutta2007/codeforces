#include <bits/stdc++.h>
using namespace std;

char arr[1010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n;
    scanf("%s", arr);

    n = strlen(arr);

    vector<vector<int>> res;
    while(1)
    {
        int p = 0;
        int q = n - 1;

        vector<int> v;
        while(p < q)
        {
            while(p < n && arr[p] != '(')
                p++;
            while(q >= 0 && arr[q] != ')')
                q--;

            if(p < q)
            {
                v.push_back(p + 1);
                v.push_back(q + 1);
                arr[p] = arr[q] = 'x';
            }
        }

        if(v.empty())
            break;

        res.push_back(v);
    }

    printf("%d\n", (int)res.size());
    for(auto &v : res)
    {
        sort(v.begin(), v.end());

        printf("%d\n", (int)v.size());
        for(int x : v)
            printf("%d ", x);
        puts("");
    }

    return 0;
}