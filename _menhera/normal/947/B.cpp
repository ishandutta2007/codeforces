#include<bits/stdc++.h>
using namespace std;
int N;
int V[101010];
int T[101010];
int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; ++i) scanf("%d", V+i);
    for(int i=0; i<N; ++i) scanf("%d", T+i);
    long long totalmolten = 0;
    priority_queue<long long,vector<long long>,greater<long long> > Q;
    for(int i=0; i<N; ++i)
    {
        long long ans = 0;
        Q.push(totalmolten+V[i]);
        while(!Q.empty() && Q.top() <= totalmolten+T[i])
        {
            ans += Q.top() - totalmolten;
            Q.pop();
        }
        ans += T[i] * Q.size();
        totalmolten += T[i];
        printf("%lld ", ans);
    }
    puts("");
    return 0;
}