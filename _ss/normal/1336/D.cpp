#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e5+10;

int pre1,pre2;

pii get(int x)
{
    cout<<"+ "<<x<<endl;
    pii res;
    cin>>res.fi>>res.se;
    res.fi-=pre1;
    res.se-=pre2;
    pre1+=res.fi;
    pre2+=res.se;
    return res;
}

int ans[N],val[N];

int main()
{
    //freopen("ss.inp","r",stdin);
    int n;
    cin>>n>>pre1>>pre2;
    for (int i=2;i<=2*n;i++) val[i*(i-1)/2]=i;
    get(1);
    pii tmp=get(2);
    if (tmp.se>0) ans[3]=1;
    tmp=get(3);
    if (tmp.fi>0) ans[3]=val[tmp.fi];
    pii tmp2=get(1);
    if (tmp2.fi>0) ans[1]=val[tmp2.fi]-1;
    ans[2]=tmp2.se/(ans[3]+1)-1;
    tmp.se-=(ans[1]+1)*(ans[2]+1);
    ans[4]=tmp.se/(ans[2]+1);
    for (int i=4;i<=n-1;i++)
    {
        pii x=get(i);
        if (x.fi>0) ans[i]=val[x.fi];
        else ans[i]=min(ans[i],1);
        x.se-=(ans[i-2]+1)*(ans[i-1]+1);
        ans[i+1]=x.se/(ans[i-1]+1);
    }
    cout<<"!";
    for (int i=1;i<=n;i++) cout<<" "<<ans[i];
    return 0;
}