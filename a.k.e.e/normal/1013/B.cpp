#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;
const int MAXN=100005;

int n,x;
int a[MAXN];
int cnt[MAXN],tot[MAXN],same[MAXN];

int main()
{
    int maxa=0;
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	maxa=max(maxa,a[i]);
    	cnt[a[i]]++;
    	tot[a[i]&x]++;
    	if(a[i]==(a[i]&x))same[a[i]]++;
    }
    int ans=3;
    for(int i=0;i<=maxa;i++)
    {
    	if(cnt[i]>=2)ans=min(ans,0);
    	if(cnt[i] && tot[i])
		{
			if(cnt[i]==1 && tot[i]==1 && same[i])continue;
			ans=min(ans,1);
		}
    	if(tot[i]>=2)ans=min(ans,2);
    }
    if(ans==3)ans=-1;
    cout<<ans<<endl;
    return 0;
}