#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define INF ((ll)1e14)
#define N (201*1000)
#define K (4001*1000)

ll n,a[N],ans;
bool mark[K];
set <ll> s;

int main()
{
    scanf("%d",&n);
    for(ll i=0;i<n;i++)scanf("%d",&a[i]),s.insert(a[i]);
    sort(a,a+n);
    for(ll i=n-1;i>=0;i--)
        if(!mark[a[i]])
        {
            mark[a[i]]=1;
            for(long long j=2*a[i];;j+=a[i])
            {
                set <ll>::iterator it=s.lower_bound(j);
                it--;
                if(j-*it<a[i])
                    ans=max((long long)ans,*it-j+a[i]);
                it++;
                if(it==s.end() || mark[j])break;    
            }
        }
    printf("%d",ans);
    return 0;
}