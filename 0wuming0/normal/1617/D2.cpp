#include"bits/stdc++.h"
using namespace std;
int saveans[10005];
int ans[10005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int _0,_1;
        for(int i=0;i<n/3;i++)
        {
            cout<<"? "<<i*3+1<<" "<<i*3+2<<" "<<i*3+3<<endl;
            cin>>saveans[i];
            if(saveans[i]==0)_0=i;
            if(saveans[i]==1)_1=i;
        }
        int ans0,ans1;
        int s1,s2,t1,t2,temp;
        int a1=_0*3+1,a2=_0*3+2,a3=_0*3+3,b1=_1*3+1,b2=_1*3+2,b3=_1*3+3;
        cout<<"? "<<a1<<" "<<b1<<" "<<b2<<endl;
        cin>>s1;
        cout<<"? "<<a2<<" "<<b1<<" "<<b2<<endl;
        cin>>s2;
        cout<<"? "<<a1<<" "<<a2<<" "<<b1<<endl;
        cin>>t1;
        cout<<"? "<<a1<<" "<<a2<<" "<<b2<<endl;
        cin>>t2;
        if(s1==0||s2==0)
        {
            ans[b3]=1;
            ans1=b3;
        }
        else
        {
            ans[b1]=1;
            ans[b2]=1;
            ans1=b1;
        }
        if(t1==1||t2==1)
        {
            ans[a3]=0;
            ans0=a3;
        }
        else
        {
            ans[a1]=0;
            ans[a2]=0;
            ans0=a1;
        }
        if(s1==0||s2==0)
        {
            cout<<"? "<<ans0<<" "<<ans1<<" "<<b1<<endl;
            cin>>temp;
            if(temp)ans[b1]=1;
            else ans[b1]=0;
            ans[b2]=ans[b1]^1;
        }
        else
        {
            cout<<"? "<<ans0<<" "<<ans1<<" "<<b3<<endl;
            cin>>temp;
            if(temp)ans[b3]=1;
            else ans[b3]=0;
        }
        if(t1==1||t2==1)
        {
            cout<<"? "<<ans0<<" "<<ans1<<" "<<a1<<endl;
            cin>>temp;
            if(temp)ans[a1]=1;
            else ans[a1]=0;
            ans[a2]=ans[a1]^1;
        }
        else
        {
            cout<<"? "<<ans0<<" "<<ans1<<" "<<a3<<endl;
            cin>>temp;
            if(temp)ans[a3]=1;
            else ans[a3]=0;
        }
        for(int i=0;i<n/3;i++)
        {
            if(i==_0)continue;
            if(i==_1)continue;
            int a1=i*3+1,a2=i*3+2,a3=i*3+3;
            if(saveans[i]==0)
            {
                cout<<"? "<<a1<<" "<<a2<<" "<<ans1<<endl;
                cin>>temp;
                if(temp==0)
                {
                    ans[a1]=0;
                    ans[a2]=0;
                    cout<<"? "<<ans0<<" "<<ans1<<" "<<a3<<endl;
                    cin>>temp;
                    if(temp)ans[a3]=1;
                    else ans[a3]=0;
                }
                else
                {
                    ans[a3]=0;
                    cout<<"? "<<ans0<<" "<<ans1<<" "<<a1<<endl;
                    cin>>temp;
                    if(temp)ans[a1]=1;
                    else ans[a1]=0;
                    ans[a2]=ans[a1]^1;
                }
            }
            else
            {
                cout<<"? "<<a1<<" "<<a2<<" "<<ans0<<endl;
                cin>>temp;
                if(temp==1)
                {
                    ans[a1]=1;
                    ans[a2]=1;
                    cout<<"? "<<ans0<<" "<<ans1<<" "<<a3<<endl;
                    cin>>temp;
                    if(temp)ans[a3]=1;
                    else ans[a3]=0;
                }
                else
                {
                    ans[a3]=1;
                    cout<<"? "<<ans0<<" "<<ans1<<" "<<a1<<endl;
                    cin>>temp;
                    if(temp)ans[a1]=1;
                    else ans[a1]=0;
                    ans[a2]=ans[a1]^1;
                }
            }
        }
        vector<int>v;
        for(int i=1;i<=n;i++)if(ans[i]==0)v.push_back(i);
        cout<<"! "<<v.size();
        for(auto i:v)cout<<" "<<i;
        cout<<endl;
    }
    return 0;
}