#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=1e5+10,mod=1e9+7,inf=1e18;

int mark[N];

int main()
{
    //freopen("ss.inp","r",stdin);
    int t1;
    cout<<"a"<<"\n";
    cout.flush();
    cin>>t1;
    int len=t1+1;
    int d;
    if (len>300)
    {
        for (int i=1;i<len;i++) cout<<"b";
        cout<<"\n";
        cout.flush();
        cin>>t1;
        return 0;
    }
    for (int i=1;i<=len;i++) cout<<"a";
    cout<<"\n";
    cout.flush();
    cin>>d;
    if (d==0) return 0;
    if (d==len)
    {
        for (int i=1;i<len;i++) cout<<"b";
        cout<<"\n";
        cout.flush();
        cin>>t1;
        return 0;
    }
    int x,cnt=0;
    for (int i=1;i<len;i++)
    {
        for (int j=1;j<i;j++) cout<<"a";
        cout<<"b";
        for (int j=i+1;j<=len;j++) cout<<"a";
        cout<<"\n";
        cout.flush();
        cin>>x;
        if (x==d-1) mark[i]=1,cnt++;
    }
    if (cnt<d) mark[len]=1;
    for (int i=1;i<=len;i++)
        if (mark[i]) cout<<"b";
        else cout<<"a";
    cout<<"\n";
    cout.flush();
    cin>>x;
    return 0;
}