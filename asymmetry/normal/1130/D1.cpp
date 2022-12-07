#include <bits/stdc++.h>

using namespace std;

int n, m, a, b, w, xd, lul;
vector <int> c[20001];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; ++i)
    {
        scanf("%d%d", &a, &b);
        c[a].push_back(b);
    }
    for(int gh=1; gh<=n; ++gh)
    {
        w=0;
        for(int i=1; i<=n; ++i)
        {
            xd=100000000;
            for(int j=0; j<c[i].size(); ++j)
            {
                if(i<c[i][j])
                {
                    xd=min(xd, c[i][j]-i);
                }
                else
                {
                    xd=min(xd, n-i+c[i][j]);
                }
            }
            if(xd!=100000000)
            {
                lul=c[i].size()-1;
                if(gh<=i)
                {
                    w=max(w, xd+lul*n+i-gh);
                }
                else
                {
                    w=max(w, xd+lul*n+n-gh+i);
                }
            }
        }
        printf("%d ", w);
    }
    return 0;
}