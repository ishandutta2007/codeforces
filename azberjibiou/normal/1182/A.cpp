#include <bits/stdc++.h>
using namespace std;
int N;
long long asdf(int k)
{
    long long ans=1;
    for(int i=1;i<=k;i++)
        ans*=2;
    return ans;
}
int main()
{
    scanf("%d", &N);
    if(N%2==1)
        printf("0");
    else
    {
        printf("%d", asdf(N/2));
    }
}