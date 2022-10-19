#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a,b,c;
    cin>>a>>b>>c;
    int nl=0,nm=0,nr=0;
    for(int i=0;i<m;i++)
    {
        int t;
        cin>>t;
        if(t<c)nl++;
        else if(t>c)nr++;
        else nm++;
        b-=t;
    }
    //n-=m;
    if(b-(n-m)<0)cout<<"-1"<<endl;
    else
    {
        int s1=1,s2=max(c-1,1),s3=c,s4=min(c+1,a),s5=a;
        int num1=n/2-nl,num2=n/2-nr;
        if(num1<0)cout<<"-1"<<endl;
        else
        {
            int mins,maxs;
            mins=num1*s1+(n-m-num1)*c;/*
            maxs=num2*s5+(n-m-num2)*c;
            if(mins<=b&&b<=maxs)
            {
                if((n-m)*c==b)
                {
                    for(int i=1;i<=n-m;i++)
                        cout<<c<<" \n"[i==n-m];
                }
                else if((n-m)*c>b)
                {
                    int flag=0;
                    //num1,n-m-num1
                    //1    c
                    int ans1=(b-n+m)/(c-1);
                    //b-ans*c
                    int ans2=n-m-ans1-1;
                    int ans3=b-ans2-c*ans1;
                    for(int i=0;i<ans1;i++)
                    {
                        cout<<c<<" ";
                    }
                    for(int i=0;i<ans2;i++)
                    {
                        cout<<1<<" ";
                    }
                    cout<<ans3<<endl;
                }
                else
                {
                    int flag=0;
                    //num1,n-m-num1
                    //1    c
                    int ans2=(b-(n+m)*c)/(a-c);
                    //b-ans*c
                    int ans1=n-m-ans1-1;
                    int ans3=b-ans2*a-c*ans1;
                    for(int i=0;i<ans1;i++)
                    {
                        cout<<c<<" ";
                    }
                    for(int i=0;i<ans2;i++)
                    {
                        cout<<a<<" ";
                    }
                    cout<<ans3<<endl;
                }
            }
            else cout<<"-1"<<endl;*/
            if(mins<=b)
            {
                int flag=0;
                //num1,n-m-num1
                //1    c
                int ans2=(b-(n+m)*c)/(a-c);
                //b-ans*c
                int ans1=n-m-ans1-1;
                int ans3=b-ans2*a-c*ans1;
                for(int i=0;i<n-m;i++)
                {
                    if(i<num1)cout<<1;
                    else cout<<c;
                    cout<<" \n"[i==n-m-1];
                }
            }
            else cout<<"-1"<<endl;
        }
    }
    return 0;
}