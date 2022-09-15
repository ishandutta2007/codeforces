#include<bits/stdc++.h>
using namespace std;
int N, K;
int main()
{
    set<int> S;
    scanf("%d%d", &N, &K);
    int g = K;
    for(int i=0; i<N; ++i)
    {
        int t; scanf("%d", &t);
        g = __gcd(g, t);
    }
    for(int i=0; i<K; ++i)
    {
        S.insert(1LL*g*i%K);
    }
    printf("%d\n", (int)S.size());
    for(auto x: S) printf("%d ", x);
    puts("");
    
}