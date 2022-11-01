#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> v(n);
    for(int i=0;i<n;i++) scanf("%d",&v[i]);
    int x=0;
    for(int i=0;i<n;i++)
    {
        int a=v[i]+x;
        printf("%d ",a);
        x=max(x,a);
    }
    printf("\n");
    return 0;
}