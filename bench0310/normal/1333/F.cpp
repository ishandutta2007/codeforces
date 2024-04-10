#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> sieve(n+1,0);
    for(int i=1;i<=n;i++) sieve[i]=i;
    vector<int> v(n+1,0);
    for(long long i=2;i<=n;i++)
    {
        v[i/sieve[i]]++;
        if(sieve[i]!=i) continue;
        for(long long j=i*i;j<=n;j+=i) sieve[j]=min(sieve[j],(int)i);
    }
    for(int i=1;i<=n;i++) for(int j=0;j<v[i];j++) printf("%d ",i);
    printf("\n");
    return 0;
}