#include"bits/stdc++.h"
using namespace std;
int b[200005],nn;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        nn=0;
        int num=0;
        for(int i=1;i<=n;i++)
        {
            int a;
            scanf("%d",&a);
            if(a==0)
            {
                if(num==0)
                {
                    num=1;
                    b[nn++]=a;
                }
            }
            else
            {
                b[nn++]=a;
            }
        }
        if(nn>4)
        {
            cout<<"no"<<endl;
            continue;
        }
        for(int i=0;i<nn;i++)for(int j=i+1;j<nn;j++)for(int k=j+1;k<nn;k++)
        {
            b[nn]=b[i]+b[j]+b[k];
            bool f=0;
            for(int l=0;l<nn;l++)if(b[nn]==b[l])f=1;
            if(f==0)
            {
                cout<<"no"<<endl;
                goto ne;
            }
        }
        cout<<"yes"<<endl;
        ne:;
    }
    return 0;
}