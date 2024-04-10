#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,sz;
	scanf("%d%d",&n,&sz);
	int k=min((8*sz)/n,20);
	int num=min(n,(1<<k));
	vector<int> a(n);
	set<int> s;
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a.begin(),a.end());
	vector<int> v={a[0]};
	for(int i=1;i<n;i++) if(a[i]!=a[i-1]) v.push_back(a[i]);
	int res=n;
	int m=v.size();
	for(int i=0;i<m;i++)
    {
        int one=v[i];
        int two=v[min(m-1,i+num-1)];
        int now=0;
        int l,r;
        l=-1,r=n-1;
        while(l<r-1)
        {
            int mid=(l+r)/2;
            if(a[mid]>=one) r=mid;
            else l=mid;
        }
        now+=r;
        l=0,r=n;
        while(l<r-1)
        {
            int mid=(l+r)/2;
            if(a[mid]<=two) l=mid;
            else r=mid;
        }
        now+=(n-r);
        res=min(res,now);
    }
    printf("%d\n",res);
	return 0;
}