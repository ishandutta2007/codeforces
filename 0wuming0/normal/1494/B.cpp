#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d;
        int n;
        int s[4]={0};
        cin>>n;
        cin>>a>>b>>c>>d;
        for(s[0]=0;s[0]<2;s[0]++)
            for(s[1]=0;s[1]<2;s[1]++)
            for(s[2]=0;s[2]<2;s[2]++)for(s[3]=0;s[3]<2;s[3]++)
        {
            int aa=a,bb=b,cc=c,dd=d;
            if(s[0])aa--,dd--;
            if(s[1])aa--,bb--;
            if(s[2])bb--,cc--;
            if(s[3])cc--,dd--;

            if(aa<=n-2&&bb<=n-2&&cc<=n-2&&dd<=n-2&&aa>=0&&bb>=0&&cc>=0&&dd>=0)
            {cout<<"yes"<<endl;goto ne;
            }
        }
        cout<<"no"<<endl;
            ne:;
    }
    return 0;
}