#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int>> v;

void solve(int idx)
{
    //cout << "in " << idx << endl;
    if(idx<0||idx>=n) return;
    vector<pair<int,int>> a;
    for(int i=0;i<n;i++) if(i!=idx) a.push_back(v[i]);
    set<int> s;
    for(int i=1;i<(int)a.size();i++) s.insert(a[i].first-a[i-1].first);
    if(s.size()==1)
    {
        printf("%d\n",v[idx].second+1);
        exit(0);
    }
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
    {
        int temp;
        scanf("%d",&temp);
        v.push_back({temp,i});
    }
    sort(v.begin(),v.end());
    if(n<=3)
    {
        printf("1\n");
        return 0;
    }
    vector<int> d;
    set<int> s;
    for(int i=1;i<n;i++)
    {
        int now=v[i].first-v[i-1].first;
        s.insert(now);
        d.push_back(now);
    }
    if(s.size()>3)
    {
        printf("-1\n");
        return 0;
    }
    if(s.size()==1)
    {
        printf("%d\n",v[0].second+1);
        return 0;
    }
    for(int a:s)
    {
        //cout << "a: " << a << endl;
        vector<int> t;
        for(int i=0;i<n-1;i++)
        {
            if(d[i]!=a) t.push_back(i);
        }
        /*cout << "sz: " << t.size() << endl;
        for(int i=0;i<(int)t.size();i++) cout << t[i] << " ";
        cout << endl;*/
        if(t.size()==1)
        {
            solve(t[0]);
            solve(t[0]+1);
        }
        if(t.size()==2)
        {
            if(t[0]+1==t[1])
            {
                solve(t[1]);
            }
        }
    }
    printf("-1\n");
	return 0;
}