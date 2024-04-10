#include<bits/stdc++.h>
using namespace std;
int N;
bool is(int x)
{
    for(int i=0; i<=1010; ++i)
    {
        if(i*i==x) return true;
    }
    return false;
}
int main()
{
    scanf("%d", &N);
    int maxv = -1e7;
    for(int i=0; i<N; ++i)
    {   
        int x; scanf("%d", &x);
        if(!is(x)) maxv = max(maxv, x);
    }
    printf("%d\n", maxv);
    return 0;

}