#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	int q;
	scanf("%d",&q);
	vector<int> v(q,0);
	vector<int> last(n,0);
	for(int i=0;i<q;i++)
    {
        int t;
        scanf("%d",&t);
        if(t==1)
        {
            int p,x;
            scanf("%d%d",&p,&x);
            a[p-1]=x;
            last[p-1]=i;
        }
        else
        {
            int x;
            scanf("%d",&x);
            v[i]=x;
        }
    }
    vector<int> best(q,0);
    best[q-1]=v[q-1];
    for(int i=q-2;i>=0;i--) best[i]=max(v[i],best[i+1]);
    for(int i=0;i<n;i++) printf("%d ",max(a[i],best[last[i]]));
    printf("\n");
	return 0;
}