#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> res;
void f(int n)
{
    if(n == 3)
    {
        res.push_back({ 1, 2, 3 });
        res.push_back({ 1, 2, 3 });
        return;
    }
    if(n == 4)
    {
        res.push_back({ 1, 2, 3 });
        res.push_back({ 2, 3, 4 });
        res.push_back({ 3, 4, 1 });
        res.push_back({ 4, 1, 2 });
        return;
    }

    res.push_back({ n - 2, n - 1, n });
    res.push_back({ n - 2, n - 1, n });

    int t = n - 3;
    while(t)
    {
        if(t == 3)
        {
            res.push_back({ 1, n - 1, 2, n });
            res.push_back({ 2, n - 1, 3, n });
            res.push_back({ 3, n - 1, 1, n });
            break;
        }

        res.push_back({ t - 1, n - 1, t, n });
        res.push_back({ t - 1, n - 1, t, n });
        t -= 2;
    }

    f(n - 2);
}

int main()
{
    int n;
    scanf("%d", &n);

    f(n);

    printf("%d\n", (int)res.size());
    for(auto& v : res)
    {
        printf("%d", (int)v.size());
        for(int x : v)
            printf(" %d", x);
        puts("");
    }

    return 0;
}