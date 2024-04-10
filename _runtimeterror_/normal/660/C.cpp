#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n, k, ans=0;
    scanf("%d %d",&n,&k);

    vector<int> a(n),b(n,0);

    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);

    b[0]=a[0]==0;
    for(int i=1;i<n;++i)
        b[i]=b[i-1]+(a[i]==0);

    int id=-1;

    for(int i=0;i<n;++i)
    {
        int l=b[i]-(a[i]==0);
        int x=upper_bound(b.begin(),b.end(),l+k)-b.begin()-1;
        if(x-i+1>ans)
            ans=x-i+1,id=i;
    }
    if(id!=-1)
    {
        for(int i=id;i<n && k;++i)
        {
            if(a[i]==0)
                ++a[i],--k;
        }
    }
    printf("%d\n",ans);
    for(int i=0;i<n;++i)
        printf("%d ",a[i]);
}