#include <bits/stdc++.h>

using namespace std;

int ab(int a)
{
    if(a>=0) return a;
    else return -a;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        vector<int> v(n);
        for(int i=0;i<n;i++) scanf("%d",&v[i]);
        int l=0,r=0;
        for(int i=0;i<n-1;i++) if(ab(v[i]-v[i+1])>=2) tie(l,r)=make_pair(i,i+1);
        if(r>0) printf("YES\n%d %d\n",l+1,r+1);
        else printf("NO\n");
    }
    return 0;
}