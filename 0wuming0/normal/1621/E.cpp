#include"bits/stdc++.h"
using namespace std;
#define ll long long
int a[100005];
int n,m;
int finds(int s)
{//cout<<"---"<<s<<" "<<a[0]<<endl;
    if(s>a[n-1])return n;
    int l=-1,r=n-1;
    while(l+1!=r)
    {
        int m=l+r;
        m/=2;
        if(a[m]<s)l=m;
        else r=m;
    }//cout<<r<<endl;
    return r;
}
int aim[100005];
vector<int>save[100005];
ll sum[100005];
int temp[100005];
ll avg[100005];
vector<int>v[100005];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)scanf("%d",a+i);
        sort(a,a+n,cmp);
        n=m;
        sort(a,a+n);
        for(int i=0;i<m;i++)
        {
            int k;
            scanf("%d",&k);
            sum[i]=0;
            while(k--)
            {
                int a;
                scanf("%d",&a);
                v[i].push_back(a);
                sum[i]+=a;
            }
            if(sum[i]%v[i].size())
            {
                avg[i]=sum[i]/v[i].size()+1;
            }
            else avg[i]=sum[i]/v[i].size();
        }
        for(int i=0;i<=n;i++)save[i].clear();
        for(int i=0;i<n;i++)
        {
            aim[i]=finds(avg[i]);
            save[aim[i]].push_back(i);
        }
        int now=0;
        {
            int i;
            int last=n-1;
            for(i=n;i>=0;i--)
            {
                now+=save[i].size();
                temp[i]=last;
                if(now>n-i)
                {
                    break;
                }
                else if(now==n-i)
                {
                    last=i-1;
                }
            }
            if(i>=0)
            {//cout<<"ok"<<i<<endl;
                int l,r=i;
                now-=save[i].size();
                now--;
                for(;i>=0;i--)
                {
                    now+=save[i].size();
                    if(now>n-i)
                    {
                        break;
                    }
                    else if(now==n-i)l=i;
                }
                if(i>=0)
                {
                    for(int i=0;i<m;i++)for(auto &j:v[i])j=0;
                }
                else
                {
                    for(int i=0;i<m;i++)
                    {
                        if(aim[i]<r)for(auto &j:v[i])j=0;
                        else
                        {//cout<<"???"<<" "<<l<<" "<<r<<endl;
                            if(v[i].size()==1)for(auto &j:v[i])j=1;
                            else
                            {
                                for(auto &j:v[i])
                                {
                                    ll k=sum[i];
                                    k-=j;
                                    int ttt=0;
                                    if(k%(v[i].size()-1))ttt=1;
                                    k/=(v[i].size()-1);
                                    k+=ttt;//cout<<"!!!"<<k<<" "<<finds(k)<<endl;
                                    if(finds(k)<l)j=1;
                                    else j=0;

                                }
                            }
                        }
                    }
                    //>=r
                    //<l
                }
            }
            else
            {
                    for(int i=0;i<m;i++)
                    {
                        //if(aim[i]<r)for(auto &j:v[i])j=0;
                        //else
                        {
                            if(v[i].size()==1)for(auto &j:v[i])j=1;
                            else
                            {
                                for(auto &j:v[i])
                                {
                                    ll k=sum[i];
                                    k-=j;
                                    int ttt=0;
                                    if(k%(v[i].size()-1))ttt=1;
                                    k/=(v[i].size()-1);
                                    k+=ttt;
                                    if(finds(k)<=temp[aim[i]])j=1;
                                    else j=0;

                                }
                            }
                        }
                    }
                //
            }
        }
        for(int i=0;i<m;i++)for(auto j:v[i])printf("%d",j);
        cout<<endl;
        for(int i=0;i<m;i++)v[i].clear();
    }
    return 0;
}