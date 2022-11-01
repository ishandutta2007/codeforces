#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	vector<int> d(n+1,0);
	for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        d[a]++;
        d[b]++;
    }
    bool res=1;
    for(int i=1;i<=n;i++) if(d[i]==2) res=0;
    if(res) printf("YES\n");
    else printf("NO\n");
	return 0;
}