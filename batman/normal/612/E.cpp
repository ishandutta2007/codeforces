#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define INF ((ll)1e14)
#define N (1001*1000)

ll n,a[N],c_num,b[N],c_cnt[N];
bool mark[N];
pair <ll,ll> c[N];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
        if(!mark[a[i]])
        {
            c[c_num].second=a[i];
            ll p=a[i];
            while(!mark[p])
                c[c_num].first++,mark[p]=1,p=a[p];
            c_cnt[c[c_num].first]++;    
            c_num++;    
        }   
    for(int i=0;i<=n;i+=2)
        if(c_cnt[i]%2==1)
            return cout<<-1,0;
    for(int i=0;i<N;i++)mark[i]=0;      
    sort(c,c+c_num);
    mark[0]=1;
    for(int i=0;i<c_num;i++)
    {
        if(c[i].first%2)
        {
            ll p=c[i].second;
            vector <ll> now;
            while(!mark[p])
                mark[p]=1,now.push_back(p),p=a[p];
            for(int j=0;j<c[i].first;j++)
                b[now[(j+(ll)(c[i].first/2))%c[i].first]]=now[j];   
            continue;
        }
        ll p1=c[i].second,p2=c[i+1].second;
        while(!mark[p1])
        {
            mark[p1]=mark[p2]=1;
            b[p1]=p2,b[p2]=a[p1];
            p1=a[p1],p2=a[p2];
        }
        i++;
    }   
    for(int i=1;i<=n;i++)cout<<b[i]<<" ";       
    return 0;
}