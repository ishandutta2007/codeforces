#include<bits/stdc++.h>
using namespace std;
bool isleaf[1010101];
int p[1010101];
int cnt[1010101];
int main()
{
    memset(isleaf, true, sizeof(isleaf));
    int N;
    scanf("%d", &N);
    for(int i=2; i<=N; ++i)
    {
        scanf("%d", p+i);
        isleaf[p[i]]=false;
    }
    for(int i=2; i<=N; ++i)
    {
        if(isleaf[i])
            cnt[p[i]]++;
    }
    for(int i=1; i<=N; ++i)
    {
        if(!isleaf[i] && cnt[i] < 3)
        {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    
}