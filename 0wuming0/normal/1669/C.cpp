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
        map<int,int>mp;
        int c=0,d=0;
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            if(i%2)
            {
                c|=a%2+1;
            }
            else d|=a%2+1;
        }
        if(c!=3&&d!=3)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}