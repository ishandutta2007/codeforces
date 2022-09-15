#include <bits/stdc++.h>
using namespace std;


int N;
char a[202020];
int b[202020];

int ipos[202020];
int main()
{
    scanf("%d", &N);
    set<int> ev;
    for(int i=0; i<2*N; ++i)
    {
        scanf(" %c", a+i);
        if(a[i] == '-')
        {
            scanf("%d", b+i);
            ipos[b[i]] = i;
        }
        else
            ev.insert(i);
    }
    for(int i=1; i<=N; ++i)
    {
        int targ = ipos[i];
        auto it = ev.lower_bound(targ);
        if(it == ev.begin())
        {
            puts("NO");
            return 0;
        }
        --it;
        b[*it] = i;
        ev.erase(it);
    }
    priority_queue<int, vector<int>, greater<int> > Q;
    for(int i=0; i<2*N; ++i)
    {
        if(a[i] == '+')
        {
            Q.emplace(b[i]);
        }
        else
        {
            if(Q.size() == 0 || Q.top() != b[i])
            {
                puts("NO");
                return 0;
            }
            Q.pop();
        }
    }
    puts("YES");
    for(int i=0; i<2*N; ++i) if(a[i] == '+') printf("%d ", b[i]);
    puts("");
}