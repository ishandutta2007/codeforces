#include <bits/stdc++.h>

using namespace std;

int n, l;
int t[100];
float s;

int main()
{
    cin>>n;
    for(int i=0; i<n; ++i)
    {
        cin>>t[i];
        s+=t[i];
    }
    sort(t, t+n);
    while(s/n<4.5)
    {
        s+=5-t[l];
        ++l;
    }
    printf("%d", l);
    return 0;
}