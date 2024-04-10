#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
long long N, M, total;
long long fact[250101];
void factorialing()
{
    fact[0]=1;
    for(int i=1;i<=N;i++)
    {
        fact[i]=fact[i-1]*i;
        fact[i]%=M;
    }
}
int main()
{
    gibon
    cin >> N >> M;
    factorialing();
    for(int i=0;i<N;i++)
    {
        long long preans=1;
        preans*=(N-i), preans%=M;
        preans*=(N-i), preans%=M;
        preans*=fact[i+1], preans%=M;
        preans*=fact[N-i-1], preans%=M;
        total+=preans, total%=M;
    }
    cout << total;
}