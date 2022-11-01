#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (301*1000)
#define INF ((ll)1e9)

ll n,sum1,sum2;
vector <ll> t1,t2;
pair <ll,ll> a[N];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].first,a[i].second=i;
    sort(a+1,a+n+1);
    for(int i=n,j=1;i>=j;i--,j++)
    {
        if(i==j)
        {
            if(sum1>=sum2)t2.push_back(a[i].second);
            else t1.push_back(a[i].second);
        }
        else if(i%2)t1.push_back(a[i].second),t2.push_back(a[j].second),sum1+=a[i].first,sum2+=a[j].first;
        else t2.push_back(a[i].second),t1.push_back(a[j].second),sum2+=a[i].first,sum1+=a[j].first;
    }
    cout<<t1.size()<<"\n";
    for(int i=0;i<t1.size();i++)cout<<t1[i]<<" ";
    cout<<"\n"<<t2.size()<<"\n";
    for(int i=0;i<t2.size();i++)cout<<t2[i]<<" ";
    return 0;
}