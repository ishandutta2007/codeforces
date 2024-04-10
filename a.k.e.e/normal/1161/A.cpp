#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=100005;

int n,k;
int a[MAXN],fir[MAXN],las[MAXN]; 

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    cin>>n>>k;
    for(int i=1;i<=n;i++)fir[i]=k+1;
    for(int i=1;i<=k;i++)
	{
		scanf("%d",&a[i]);
		if(fir[a[i]]==k+1)fir[a[i]]=i;
		las[a[i]]=i;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=max(i-1,1);j<=min(i+1,n);j++)
			if(las[j]<fir[i])++ans;
	cout<<ans<<endl;
    return 0;
}