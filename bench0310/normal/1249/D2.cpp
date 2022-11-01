#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int N=200000;
	int n,k;
	scanf("%d%d",&n,&k);
	vector<pair<int,int>> v[N+1];
	vector<int> d(N+5,0);
	for(int i=1;i<=n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        d[a]++;
        d[b+1]--;
        v[a].push_back({b,i});
    }
	vector<int> res;
	priority_queue<pair<int,int>> q;
	int now=0;
	for(int i=1;i<=N;i++)
    {
        now+=d[i];
        for(pair<int,int> p:v[i]) q.push(p);
        while(now>k)
        {
            res.push_back(q.top().second);
            d[q.top().first+1]++;
            q.pop();
            now--;
        }
    }
    printf("%d\n",(int)res.size());
    for(int a:res) printf("%d ",a);
    printf("\n");
	return 0;
}