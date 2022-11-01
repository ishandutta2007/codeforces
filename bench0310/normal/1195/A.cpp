#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	vector<int> v(k+1,0);
	for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        v[a]++;
    }
    int res=0;
    int cnt=(n+1)/2;
    for(int i=1;i<=k;i++)
    {
        int t=v[i]/2;
        cnt-=t;
        res+=2*t;
        v[i]-=2*t;
    }
    for(int i=1;i<=k;i++)
    {
        if(cnt==0) break;
        if(v[i]==0) continue;
        v[i]--;
        res++;
        cnt--;
    }
    printf("%d\n",res);
	return 0;
}