#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll x[2005],y[2005];
ll ans;
int n;
ll a[2005],b[2005];
vector<pair<ll,ll> >v1,v2;
bool cmp(pair<ll,ll>p1,pair<ll,ll>p2)
{
    if(p1.second<0||p1.second==0&&p1.first<0)
    {
        p1.first=-p1.first;
        p1.second=-p1.second;
    }
    if(p2.second<0||p2.second==0&&p2.first<0)
    {
        p2.first=-p2.first;
        p2.second=-p2.second;
    }
    if(p1.first==0||p2.first==0)return p1.first>p2.first;
    if(p1.first>0&&p2.first<0||p1.first<0&&p2.first>0)return p1.first>p2.first;
    return p1.second*p2.first<p2.second*p1.first;
}
void solve()
{
    for(int i=2;i<=n;i++)
    {
        a[i]=x[i]-x[1];
        b[i]=y[i]-y[1];
        if(b[i]>0||b[i]==0&&a[i]>0)v1.push_back(pair<ll,ll>(a[i],b[i]));
        else v2.push_back(pair<ll,ll>(a[i],b[i]));
    }
    sort(v1.begin(),v1.end(),cmp);
    sort(v2.begin(),v2.end(),cmp);
    ll num1=v1.size(),num2=v2.size();
    ll now1=0,now2=0;
    //cout<<"<<<"<<ans<<" "<<x[1]<<" "<<y[1]<<endl;
    //ans+=num1*(num1-1)/2*num2*(num2-1)*(num2-2)/6;
    //ans+=num2*(num2-1)/2*num1*(num1-1)*(num1-2)/6;
    while(now1!=v1.size()||now2!=v2.size())
    {//cout<<num1<<" "<<num2<<endl;
        if(now1==v1.size())
        {
            now2++;
            num2--;
            ans+=num2*(num2-1)/2*num1*(num1-1)/2;
            //cout<<"?"<<num1*num2*(num2-1)*(num2-2)/6+num1*(num1-1)/2*num2*(num2-1)/2<<endl;
            num1++;
        }
        else if(now2==v2.size())
        {
            now1++;
            num1--;
            ans+=num2*(num2-1)/2*num1*(num1-1)/2;
            //cout<<"?"<<num2*num1*(num1-1)*(num1-2)/6+num2*(num2-1)/2*num1*(num1-1)/2<<endl;
            num2++;
        }
        else if(cmp(v1[now1],v2[now2]))
        {//cout<<v1[now1].first<<" "<<v1[now1].second<<" "<<v2[now2].first<<" "<<v2[now2].second<<"!!!"<<endl;
            now1++;
            num1--;
            ans+=num2*(num2-1)/2*num1*(num1-1)/2;
            //cout<<"?"<<num2*num1*(num1-1)*(num1-2)/6+num2*(num2-1)/2*num1*(num1-1)/2<<endl;
            num2++;
        }
        else
        {//cout<<v1[now1].first<<" "<<v1[now1].second<<" "<<v2[now2].first<<" "<<v2[now2].second<<endl;
            now2++;
            num2--;
            ans+=num2*(num2-1)/2*num1*(num1-1)/2;
            //cout<<"?"<<num1*num2*(num2-1)*(num2-2)/6+num1*(num1-1)/2*num2*(num2-1)/2<<endl;
            num1++;
        }
    }
    v1.clear();v2.clear();
    //cout<<"<<<"<<ans<<" "<<x[1]<<" "<<y[1]<<endl;
}
int main()
{

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld",x+i,y+i);
    }
    for(int i=1;i<=n;i++)
    {
        swap(x[1],x[i]);
        swap(y[1],y[i]);
        solve();
    }
    cout<<ans/2<<endl;
    return 0;
}