#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ans=0;
        if(n==1)
        {
            cout<<"yes"<<endl;
            int a;
            cin>>a;
            cout<<a<<endl;
        }
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            if(a<0)ans=-1;
        }
        if(ans)cout<<"no"<<endl;
        else
        {
            cout<<"yes"<<endl;
            cout<<300<<endl;
            for(int i=0;i<300;i++)
            {
                printf("%d%c",i," \n"[i==299]);
            }
        }
    }
    return 0;
}