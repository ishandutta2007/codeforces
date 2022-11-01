#include <bits/stdc++.h>

using namespace std;
const int N=200000;

int n,m;
vector<int> v(N);
set<int> s[N];

bool solve(int days)
{
    int now=0;
    vector<int> cnt=v;
    vector<pair<int,int> > off; //day,type
    for(int i=0;i<n;i++)
    {
        set<int>::iterator it=s[i].upper_bound(days);
        if(it!=s[i].begin()) off.push_back(make_pair(*prev(it),i));
    }
    sort(off.begin(),off.end());
    int idx=0;
    for(int o=1;o<=days;o++)
    {
        now++;
        while(idx<(int)off.size()&&off[idx].first==o)
        {
            while(now&&cnt[off[idx].second])
            {
                cnt[off[idx].second]--;
                now--;
            }
            idx++;
        }
    }
    for(int i=0;i<n;i++) now-=2*cnt[i];
    return (now>=0);
}

int main()
{
	scanf("%d%d",&n,&m);
	int sum=0;
	for(int i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
        sum+=v[i];
    }
	for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        s[b-1].insert(a);
    }
    int l=0,r=2*sum;
    while(l<r-1)
    {
        int mid=(l+r)/2;
        if(solve(mid)) r=mid;
        else l=mid;
    }
    printf("%d\n",r);
	return 0;
}