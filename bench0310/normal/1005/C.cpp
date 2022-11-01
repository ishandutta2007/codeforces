#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
    int a[n];
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(m.find(a[i])!=m.end()) m[a[i]]++;
        else m.insert({a[i],1});
    }
    int res=0;
    for(int i=0;i<n;i++)
    {
        m[a[i]]--;
        bool ok=0;
        for(int j=1;j<=30;j++) if(m.find((1<<j)-a[i])!=m.end()&&m[(1<<j)-a[i]]>0) ok=1;
        if(ok==0) res++;
        m[a[i]]++;
    }
    printf("%d\n",res);
	return 0;
}