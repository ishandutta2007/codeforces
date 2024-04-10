#include"bits/stdc++.h"
using namespace std;
int main()
{
    int x,y;
    cin>>x>>y;
    if(y==0&&(x==0||x==1))cout<<"0"<<endl;
    else if(x==y&&y==1)cout<<"1"<<endl;
    else if((x==0||x==-1)&&y==1)cout<<"2"<<endl;
    else
    {
        int a=1,b=1;
        for(int ans=3;;ans++)
        {
            if(ans%2==0)
            {
                int a0=a;if(a0<0)a0--;a0=-a0;
                if(b<0)b--;b=-b;
                if(y==b&&(a-x)*(a0-x)<=0)
                {
                    cout<<ans<<endl;
                    return 0;
                }
            }
            else
            {
                int b0=b;if(b0<0)b0--;b0=-b0;
                if(a<0)a--;a=-a;
                if(x==a&&(b-y)*(b0-y)<=0)
                {
                    cout<<ans<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}