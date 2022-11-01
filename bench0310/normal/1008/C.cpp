#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	vector<int> v(n);
	multiset<int> s;
	for(int i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
        s.insert(v[i]);
    }
    sort(v.begin(),v.end());
    int res=0;
    for(int i=0;i<n;i++)
    {
        if(s.upper_bound(v[i])!=s.end())
        {
            res++;
            s.erase(s.find(*s.upper_bound(v[i])));
        }
        else s.erase(s.begin());
    }
    printf("%d\n",res);
	return 0;
}