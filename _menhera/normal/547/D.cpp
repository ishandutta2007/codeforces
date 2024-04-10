#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;

char ans[MAXN+1];
map<pair<int, int>, int> M;
set<int> conn[2*MAXN+2];

void bktk(int a, char c)
{
    if(conn[a].empty()) return;
    int x = *conn[a].begin();
    conn[a].erase(x); conn[x].erase(a);
    if(M.count({a, x})) ans[M[{a,x}]] = c;
    bktk(x, c^'r'^'b');
}

int main()
{
    int N; scanf("%d", &N);
    for(int i=0; i<N; ++i)
    {
        int a, b; scanf("%d%d", &a, &b);
        conn[2*a].insert(2*b+1); conn[2*b+1].insert(2*a);
        M[{2*a, 2*b+1}] = M[{2*b+1, 2*a}] = i;
    }
    for(int i=2; i<=2*MAXN+1; ++i)
        if(conn[i].size()&1)
        {
            int targ = (i&1)^1;
            conn[targ].insert(i); conn[i].insert(targ);
        }
    if(conn[0].size()&1)
        conn[0].insert(1), conn[1].insert(0);
    for(int i=0; i<=2*MAXN+1; ++i)
        while(!conn[i].empty())
            bktk(i, 'r');
    puts(ans);
}