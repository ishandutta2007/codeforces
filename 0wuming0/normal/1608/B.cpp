#include"bits/stdc++.h"
using namespace std;
int ans[100005],nn;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        if(abs(a-b)>1||a+b+2>n)
        {
            cout<<-1<<endl;
            continue;
        }
        nn=0;
        int l=1,r=a+b+2;
        for(int i=n;i>r;i--)ans[nn++]=i;
        while(1)
        {
            if(l>r)break;
            ans[nn++]=r--;
            if(l>r)break;
            ans[nn++]=l++;
        }
        if(a>b)
        {
            for(int i=0;i<nn;i++)ans[i]=n+1-ans[i];
        }
        for(int i=0;i<nn;i++)printf("%d%c",ans[i]," \n"[i==nn-1]);
    }
    return 0;
}