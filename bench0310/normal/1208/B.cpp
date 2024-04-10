#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	int res=n;
	map<int,int> id;
	int idx=0;
	for(int i=0;i<n;i++)
    {
        if(id.find(a[i])==id.end()) id.insert({a[i],idx++});
    }
	vector<int> m(idx,0);
    for(int i=0;i<n;i++)
    {
        a[i]=id[a[i]];
        m[a[i]]++;
    }
    vector<int> cnt(n+1,0);
	for(int p:m) cnt[p]++;
	if(cnt[0]+cnt[1]==idx) res=0;
	for(int o=1;o<=n;o++)
    {
        for(int i=0;i<o;i++)
        {
            cnt[m[a[i]]]--;
            m[a[i]]--;
            cnt[m[a[i]]]++;
        }
        if(cnt[0]+cnt[1]==idx) res=min(res,o);
        for(int i=o;i<n;i++)
        {
            cnt[m[a[i]]]--;
            m[a[i]]--;
            cnt[m[a[i]]]++;
            cnt[m[a[i-o]]]--;
            m[a[i-o]]++;
            cnt[m[a[i-o]]]++;
            if(cnt[0]+cnt[1]==idx) res=min(res,o);
        }
        for(int i=n-o;i<n;i++)
        {
            cnt[m[a[i]]]--;
            m[a[i]]++;
            cnt[m[a[i]]]++;
        }
    }
    printf("%d\n",res);
	return 0;
}