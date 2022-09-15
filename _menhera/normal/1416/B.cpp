#include <bits/stdc++.h>
using namespace std;


vector<tuple<int, int, int>> solve(vector<int> a)
{
    vector<tuple<int, int, int> > V;

    auto op = [&](int i, int j,  int x)
    {
        a[i] -= x*i;
        a[j] += x*i;
        assert(a[i] >= 0 && a[j] >= 0);
        V.emplace_back(i, j, x);
    };
    int N = (int)a.size()-1;

    int sv=0;
    for(int i=1; i<=N; ++i) sv += a[i];
    if(sv%N) return {{-1, -1, -1}};

    for(int i=2; i<=N; ++i)
    {
        int val = (i-a[i]%i)%i;
        op(1, i, val);
        val = a[i]/i;
        op(i, 1, val);
    }
    int distval = a[1]/N;
    for(int i=2; i<=N; ++i)
        op(1, i, distval);
    return V;
}

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        int N; scanf("%d", &N);
        vector<int> A(1+N);
        for(int i=1; i<=N; ++i)
            scanf("%d", &A[i]);
        auto ans = solve(A);
        if(ans.size() == 1 && get<0>(ans[0]) == -1)
            puts("-1");
        else
        {
            printf("%d\n", (int)ans.size());
            for(auto [a, b, c]: ans)
                printf("%d %d %d\n", a, b, c);
        }
    }
}