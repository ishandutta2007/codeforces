#include <iostream>
#include <stdio.h>
#include <math.h>
#include <set>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

const int MAXN = 3000000;
const int MAXM = 3000;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int n;
    scanf("%d", &n);
    pair<int, int> p[MAXN];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &p[i].first, &p[i].second);
    
    vector< pair<int, int> > v[MAXM];
    int c[MAXM];
    
    int b = 1000;
    int m = 1000000;
    
    for (int i = 0; i < 2000; i++)
        c[i] = 0;
    
    for (int i = 0; i < n; i++)
    {
        v[p[i].second / b].push_back(make_pair(p[i].first, i));
        c[p[i].second / b]++;
    }
    
    for (int i = 0; i < m / b + 1; i++)
    {
        sort(v[i].begin(), v[i].end());
        if (i % 2 == 0)
            for (int j = 0; j < c[i]; j++)
                printf("%d ", v[i][j].second + 1);
        if (i % 2 == 1)
            for (int j = c[i] - 1; j >= 0; j--)
                printf("%d ", v[i][j].second + 1);
    }
    return 0;
}