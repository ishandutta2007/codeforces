#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n%2)
    {
        cout<<"YES"<<endl;
        cout<<(n-3)+1<<endl;
        for(int i=4;i<=n;i+=2)printf("3 %d %d\n",i,i+1);
        cout<<"1 2 3"<<endl;
        for(int i=4;i<=n;i+=2)printf("3 %d %d\n",i,i+1);
    }
    else
    {
        int t=0;
        for(int i=0;i<n;i++)
        {
            int s;scanf("%d",&s);t^=s;
        }
        if(t)
            cout<<"NO"<<endl;
        else
        {
            n--;
            cout<<"YES"<<endl;
            cout<<(n-3)+1<<endl;
            for(int i=4;i<=n;i+=2)printf("3 %d %d\n",i,i+1);
            cout<<"1 2 3"<<endl;
            for(int i=4;i<=n;i+=2)printf("3 %d %d\n",i,i+1);
        }
    }
    return 0;
}