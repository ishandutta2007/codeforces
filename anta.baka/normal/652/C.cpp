#include <iostream>
using namespace std;
const int N=300000;
int a[N],b[N+1],c[N];

int main()
{
    //ifstream cin("input.txt");
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>a[i],b[a[i]]=i,c[i]=n;
    for(int i=0,ff,ss; i<m; i++)
    {
        cin>>ff>>ss;
        if(b[ff]>b[ss])
            swap(ff,ss);
        c[b[ff]]=min(c[b[ff]],b[ss]);
    }
    for(int i=n-2; i>=0; i--)
        c[i]=min(c[i],c[i+1]);
    long long res=0;
    for(int i=0; i<n; i++)
        res+=c[i]-i;
    cout<<res;
    return 0;
}