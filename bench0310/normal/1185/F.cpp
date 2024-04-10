#include <bits/stdc++.h>

using namespace std;
const int N=100005,M=200005;
const int inf=2000000005;

vector<int> order((1<<9),0);
vector<pair<int,int>> a((1<<9),{0,0});
vector<pair<int,int>> b((1<<9),{0,0});
vector<int> price((1<<9),inf);
vector<pair<int,int>> idx((1<<9),{0,0});

void update(int mask,int cost,int id)
{
    if(a[mask]==make_pair(0,0)) a[mask]={cost,id};
    else if(b[mask]==make_pair(0,0))
    {
        b[mask]={cost,id};
        if(a[mask].first>b[mask].first) swap(a[mask],b[mask]);
    }
    else
    {
        if(cost<a[mask].first)
        {
            swap(a[mask],b[mask]);
            a[mask]={cost,id};
        }
        else if(cost<b[mask].first) b[mask]={cost,id};
    }
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int o=0;o<n;o++)
    {
        int t=0;
        int sz;
        scanf("%d",&sz);
        for(int i=0;i<sz;i++)
        {
            int temp;
            scanf("%d",&temp);
            t|=(1<<(temp-1));
        }
        order[t]++;
    }
    for(int o=0;o<m;o++)
    {
        int cost;
        scanf("%d",&cost);
        int t=0;
        int sz;
        scanf("%d",&sz);
        for(int i=0;i<sz;i++)
        {
            int temp;
            scanf("%d",&temp);
            t|=(1<<(temp-1));
        }
        update(t,cost,o);
    }
    for(int o=0;o<(1<<9);o++)
    {
        for(int i=0;i<(1<<9);i++)
        {
            if(a[o].first==0||a[i].first==0) continue;
            int cost=inf;
            pair<int,int> p;
            if(a[o].second==a[i].second)
            {
                if(b[o].first==0&&b[i].first==0) continue;
                else if(b[o].first==0)
                {
                    cost=a[o].first+b[i].first;
                    p={a[o].second,b[i].second};
                }
                else if(b[i].first==0)
                {
                    cost=a[i].first+b[o].first;
                    p={a[i].second,b[o].second};
                }
                else
                {
                    cost=min(a[o].first+b[i].first,a[i].first+b[o].first);
                    if(a[o].first+b[i].first<=a[i].first+b[o].first) p={a[o].second,b[i].second};
                    else p={a[i].second,b[o].second};
                }
            }
            else
            {
                cost=a[o].first+a[i].first;
                p={a[o].second,a[i].second};
            }
            int dest=(o|i);
            if(cost<price[dest])
            {
                price[dest]=cost;
                idx[dest]=p;
            }
        }
    }
    int best=-1;
    int low;
    pair<int,int> res;
    for(int o=0;o<(1<<9);o++)
    {
        if(idx[o]==make_pair(0,0)) continue;
        int good=0;
        for(int i=0;i<(1<<9);i++)
        {
            bool ok=1;
            int c=o,d=i;
            while(c|d)
            {
                if((c&1)<(d&1)) ok=0;
                c/=2;
                d/=2;
            }
            if(ok) good+=order[i];
        }
        if(good>best)
        {
            best=good;
            low=price[o];
            res=idx[o];
        }
        else if(good==best)
        {
            if(price[o]<low)
            {
                low=price[o];
                res=idx[o];
            }
        }
    }
    //cout << "best: " << best << endl;
    printf("%d %d\n",res.first+1,res.second+1);
	return 0;
}