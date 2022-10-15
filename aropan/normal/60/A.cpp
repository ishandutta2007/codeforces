#include <cstdio>
#include <iostream>

using namespace std;

int n, m;
int l, r;

int main()
{
/*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
//*/
    scanf("%d %d", &n, &m);
    l = 0;
    r = n + 1;
    for (int i = 0; i < m; i++)
    {
        string temp, s;
        int x;
        cin >> temp >> temp >> s >> temp >> x;
        
        if (s == "left") r = min(r, x);
        if (s == "right") l = max(l, x);
    }
    
    if (r > l + 1)
        printf("%d\n", r - l - 1);
    else
        printf("-1\n");
    return 0;
}