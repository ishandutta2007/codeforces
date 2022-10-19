#include <bits/stdc++.h>
using namespace std;
const int N=100005;

int n;
char a[N],ans[N];
int main()
{
    cin>>a;
    n=strlen(a);
    char j='a';
    for(int i=0;i<n;++i)
    {
        if(a[i]<=j && j<='z')
        {
            ans[i]=j;
            ++j;
        }
        else
        {
            ans[i]=a[i];
        }
    }
    if(j<='z')
        cout<<"-1"<<endl;
    else
        cout<<ans<<endl;
    return 0;
}