#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int N=100005;
	int n;
	scanf("%d",&n);
	vector<int> a(n),b(N,0);
	int cnt=0;
	vector<bool> v(N,0);
	for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(b[a[i]]==0) cnt++;
        b[a[i]]++;
    }
    long long res=0;
    for(int i=0;i<n;i++)
    {
        b[a[i]]--;
        if(b[a[i]]==0) cnt--;
        if(v[a[i]]) continue;
        v[a[i]]=1;
        res+=cnt;
    }
    printf("%I64d\n",res);
	return 0;
}