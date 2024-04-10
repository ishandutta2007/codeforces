#include <bits/stdc++.h>

using namespace std;

const int maxN = 200500;

typedef long long ll;

int n, k;

bool special[maxN], used[maxN];
int h[maxN];
vector<int> e[maxN];

tuple<int, ll, int> dfs(int v)
{
    used[v] = true;
    
    tuple<int, ll, int> upAnswer;
    
    for (int u: e[v])
        if (!used[u])
        {
            h[u] = h[v] + 1;
            
            if (special[u])
                get<1>(upAnswer) += h[u];
            
            auto p = dfs(u);
            get<0>(upAnswer) += get<0>(p);
            get<1>(upAnswer) += get<1>(p);
            get<2>(upAnswer) += get<2>(p);
        }
        
    if (special[v])
    {
        get<0>(upAnswer)++;
        get<2>(upAnswer)++;
    }
        
    while (get<0>(upAnswer) > 2 * k - get<2>(upAnswer))
    {
        //printf("merge at %d\n", v + 1);
        get<0>(upAnswer) -= 2;
        get<1>(upAnswer) -= 2 * h[v];
    }
        
    return upAnswer;
}

int main()
{
    scanf("%d %d", &n, &k);
    
    for (int i = 0; i < 2 * k; i++)
    {
        int x;
        scanf("%d", &x);
        special[x - 1] = true;
    }
    
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        
        e[u].push_back(v);
        e[v].push_back(u);
    }
    
    auto p = dfs(0);
    assert(get<0>(p) == 0);
    cout << get<1>(p) << endl;
    
    return 0;
}