#include<bits/stdc++.h>
using namespace std;
int N;
int cnt[101010];
int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; ++i)
    {
        int x; scanf("%d", &x);
        cnt[x]++;
    }
    for(int i=0; i<101010; ++i)
    {
        if(cnt[i]%2==1)
        {
            puts("Conan");
            return 0;
        }
    }
    puts("Agasa");
    return 0;
}