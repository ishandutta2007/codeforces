#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	vector<int> v(n);
	for(int i=0;i<n;i++) scanf("%d",&v[i]);
	sort(v.begin(),v.end());
	vector<bool> b(n,0);
	int res=0;
	for(int o=0;o<n;o++)
    {
        if(b[o]) continue;
        res++;
        for(int i=o;i<n;i++) if((v[i]%v[o])==0) b[i]=1;
    }
    printf("%d\n",res);
	return 0;
}