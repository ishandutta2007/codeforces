#include<bits/stdc++.h>
using namespace std;

long long arr[1010101];
int main()
{
    int N;
    scanf("%d", &N);
    long long ans = 0;
    for(int i=0; i<N; ++i)
    {
        long long t; scanf("%lld", &t);
        ans += t;
    }
    for(int i=0; i<N; ++i)
    {
        arr[i] = i; ans -= i;
    }
    long long addv = ans/N;
    for(int i=0; i<N; ++i)
    {
        arr[i] += addv;
    }
    ans -= addv*N;
    for(int i=0; i<ans; ++i) arr[i]++;
    for(int i=0; i<N; ++i) printf("%lld ", arr[i]);
    puts("");
}