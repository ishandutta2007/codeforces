#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    vector<int> p(1001);
    for(int i=0;i<=1000;i++) p[i]=i;
    for(int o=2;o<=1000;o++)
    {
        if(p[o]!=o) continue;
        for(int i=o*o;i<=1000;i+=o) p[i]=min(p[i],o);
    }
    while(t--)
    {
        int n;
        scanf("%d",&n);
        vector<int> a(n);
        map<int,int> m;
        int cnt=1;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            a[i]=p[a[i]];
            if(m.find(a[i])==m.end()) m[a[i]]=cnt++;
        }
        printf("%d\n",cnt-1);
        for(int i=0;i<n;i++) printf("%d%c",m[a[i]]," \n"[i==n-1]);
    }
    return 0;
}