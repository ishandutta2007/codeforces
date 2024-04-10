#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
#define mp make_pair
const ll maxn=1e5+1,mod=1e9+7,inf=1e9;
struct ds
{
    int x,y,z,id;
};

bool cmp(ds obj1,ds obj2)
{
    if (obj1.x==obj2.x)
    {
        if (obj1.y==obj2.y) return obj1.z<obj2.z;
        return obj1.y<obj2.y;
    }
    return obj1.x<obj2.x;
}

ds a[maxn],b[maxn];
int n,mark[maxn];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y>>a[i].z;
        a[i].id=i;
    }
    sort(a+1,a+n+1,cmp);
    a[n+1]={inf,inf,inf};
    vector<int> tmp;
    for (int i=1;i<=n;i++)
        if (a[i].x==a[i+1].x && a[i].y==a[i+1].y) tmp.pb(i);
        else
        {
            tmp.pb(i);
            for (int j=0;j<tmp.size()/2;j++)
            {
                mark[tmp[j*2]]=1;
                mark[tmp[j*2+1]]=1;
                cout<<a[tmp[j*2]].id<<" "<<a[tmp[j*2+1]].id<<endl;
            }
            tmp.clear();
        }
    int tt=0;
    for (int i=1;i<=n;i++)
        if (!mark[i])
        {
            tt++;
            b[tt]=a[i];
        }
    n=tt;
    for (int i=1;i<=n;i++) mark[i]=0,a[i]=b[i];
    a[n+1]={inf,inf,inf};
    for (int i=1;i<=n;i++)
        if (a[i].x==a[i+1].x) tmp.pb(i);
        else
        {
            tmp.pb(i);
            for (int j=0;j<tmp.size()/2;j++)
            {
                mark[tmp[j*2]]=1;
                mark[tmp[j*2+1]]=1;
                cout<<a[tmp[j*2]].id<<" "<<a[tmp[j*2+1]].id<<endl;
            }
            tmp.clear();
        }
    tt=0;
    for (int i=1;i<=n;i++)
        if (!mark[i])
        {
            tt++;
            b[tt]=a[i];
        }
    n=tt;
    for (int i=1;i<=n/2;i++) cout<<b[i*2-1].id<<" "<<b[i*2].id<<endl;
    return 0;
}