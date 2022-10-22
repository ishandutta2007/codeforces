#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int> signs, int n, int needGet)
{
    if (signs.empty())
        return vector<int>();
    
    int nPlus = 0, nMinus = 0;
    for (int c: signs)
        if (c == 1)
            nPlus++;
        else
            nMinus++;
    
    int minv = nPlus - nMinus * n, maxv = nPlus * n - nMinus;
    
    if (!(needGet >= minv && needGet <= maxv))
        return vector<int>();
    
    int nextPlus = nPlus - (signs.back() == 1);
    int nextMinus = nMinus - (signs.back() == -1);
    
    for (int x = 1; x <= n; x++)
    {
        int y = needGet - signs.back() * x;
        if (y >= nextPlus - nextMinus * n && y <= nextPlus * n - nextMinus)
        {
            signs.pop_back();
            vector<int> ans = solve(signs, n, y);
            ans.push_back(x);
            return ans;
        }
    }
    
    assert(!"impossible");
}

int main()
{
    vector<int> signs;
    signs.push_back(1);
    
    int nPlus = 0, nMinus = 0;
    
    while (true)
    {
        char a, b;
        scanf(" %c %c", &a, &b);
        if (b == '=') break;
        
        signs.push_back(b == '+' ? 1 : -1);
        if (b == '+') nPlus++;
        else nMinus++;
    }
    
    int n;
    scanf("%d", &n);
    
    vector<int> v = solve(signs, n, n);
    
    if (v.empty())
    {
        printf("Impossible\n");
        return 0;
    }
    else
    {
        printf("Possible\n");
        for (int i = 0; i < (int)signs.size(); i++)
            if (i == 0)
                printf("%d ", v[0]);
            else
                printf("%c %d ", signs[i] == 1 ? '+' : '-', v[i]);
        printf("= %d\n", n);
        return 0;
    }
    
    return 0;
}