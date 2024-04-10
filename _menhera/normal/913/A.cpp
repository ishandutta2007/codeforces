#include<bits/stdc++.h>
using namespace std;
int N, M;
int main()
{
    scanf("%d%d", &N, &M);
    if(N>30) N = 30;
    printf("%d\n", M%(1<<N));
    return 0;
}