#include <bits/stdc++.h>
using namespace std;


vector<int> arr[300001];

vector<int> solve(vector<int> a)
{
    int N = a.size();
    for(int i=1; i<=N; ++i) arr[i].push_back(-1);
    for(int i=0; i<N; ++i)
        arr[a[i]].push_back(i);
    for(int i=1; i<=N; ++i) arr[i].push_back(N);
    vector<int> sv(N+1, 0);
    vector<int> ans(N, N+1);
    for(int i=1; i<=N; ++i)
    {
        for(int j=0; j<(int)arr[i].size()-1; ++j)
            sv[i] = max(sv[i], arr[i][j+1]-arr[i][j]);
        if(sv[i] != N+1)
            ans[sv[i]-1] = min(ans[sv[i]-1], i);
    }
    for(int i=1; i<N; ++i)
        ans[i] = min(ans[i], ans[i-1]);
    for(int i=0; i<N; ++i)
        if(ans[i] == N+1) ans[i] = -1;
    for(int i=1; i<=N; ++i) arr[i].clear();
    return ans;
}

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        int N; scanf("%d", &N);
        vector<int> A(N);
        for(int i=0; i<N; ++i)
            scanf("%d", &A[i]);
        for(auto x: solve(A))
            printf("%d ", x);
        puts("");
    }
}