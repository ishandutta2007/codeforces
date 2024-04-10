#include <bits/stdc++.h>

using namespace std;

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
    {
        int n;
        scanf("%d",&n);
        vector<int> a(4*n);
        for(int i=0;i<4*n;i++) scanf("%d",&a[i]);
        sort(a.begin(),a.end());
        int b=a[0]*a.back();
        bool ok=1;
        for(int i=0;i+1<4*n-i-2;i+=2)
        {
            if(a[i]!=a[i+1]||a[4*n-i-1]!=a[4*n-i-2]||a[i]*a[4*n-i-1]!=b) ok=0;
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}