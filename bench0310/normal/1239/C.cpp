#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    long long p;
    scanf("%d%I64d",&n,&p);
    vector<pair<long long,int>> v(n);
    set<long long> times;
    for(int i=0;i<n;i++)
    {
        scanf("%I64d",&v[i].first);
        v[i].second=i;
        times.insert(v[i].first);
    }
    sort(v.begin(),v.end());
    vector<long long> res(n);
    set<int> line; //in line for soup
    queue<pair<int,long long>> q; //in line for soup in order of rtime
    long long rtime=0; //time at which last person in the queue gets the soup
    set<int> waiting; //in their seats waiting to become eligible
    int idx=0;
    long long now=-1;
    while(1)
    {
        if(times.upper_bound(now)==times.end()) break;
        now=*times.upper_bound(now);
        while(idx<n&&v[idx].first==now)
        {
            waiting.insert(v[idx++].second);
        }
        if(!q.empty()&&q.front().second==now)
        {
            line.erase(q.front().first);
            q.pop();
        }
        if(!waiting.empty())
        {
            if(line.empty())
            {
                int id=*waiting.begin();
                waiting.erase(id);
                res[id]=now+p;
                rtime=res[id];
                line.insert(id);
                q.push({id,res[id]});
                times.insert(res[id]);
            }
            else if((*line.begin())>(*waiting.begin()))
            {
                int id=*waiting.begin();
                waiting.erase(id);
                res[id]=rtime+p;
                rtime+=p;
                line.insert(id);
                q.push({id,res[id]});
                times.insert(res[id]);
            }
        }
    }
    for(int i=0;i<n;i++) printf("%I64d%c",res[i]," \n"[i==n-1]);
    return 0;
}