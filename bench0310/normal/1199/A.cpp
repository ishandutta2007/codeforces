#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	vector<int> a(n+1,0);
	for(int o=1;o<=n;o++) scanf("%d",&a[o]);
	for(int o=1;o<=n;o++)
    {
        bool b=1;
        for(int i=max(o-x,1);i<o;i++) if(a[i]<=a[o]) b=0;
        for(int i=min(o+y,n);i>o;i--) if(a[i]<=a[o]) b=0;
        if(b)
        {
            printf("%d\n",o);
            break;
        }
    }
	return 0;
}