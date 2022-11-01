#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a,long long b)
{
    if(!b) return a;
    else return gcd(b,a%b);
}

long long lcm(long long a,long long b)
{
    return a*b/gcd(a,b);
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	vector<int> v[n];
	for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a>b) swap(a,b);
        int d=b-a;
        if(d<n-d) v[d].push_back(a);
        else if(d>n-d) v[n-d].push_back(b);
        else
        {
            v[d].push_back(a);
            v[d].push_back(b);
        }
    }
    for(int i=0;i<n;i++) sort(v[i].begin(),v[i].end());
    bool res=1;
    long long fin=1;
    for(int o=1;o<n;o++)
    {
        if(v[o].empty()) continue;
        vector<int> d;
        for(int i=0;i<(int)v[o].size()-1;i++) d.push_back(v[o][i+1]-v[o][i]);
        d.push_back(n-(v[o][v[o].size()-1]-v[o][0]));
        bool found=0;
        int temp;
        vector<int> divisors;
        for(int i=1;i<(int)d.size();i++) if((d.size()%i)==0) divisors.push_back(i);
        for(int i=0;i<(int)divisors.size();i++)
        {
            bool ok=1;
            int now=divisors[i];
            for(int j=0;j<(int)d.size();j++)
            {
                if(d[j]!=d[(j+now)%d.size()])
                {
                    ok=0;
                    break;
                }
            }
            if(ok)
            {
                found=1;
                temp=now;
                break;
            }
        }
        if(!found)
        {
            res=0;
            break;
        }
        else fin=lcm(fin,(long long)(v[o][temp]-v[o][0]));
        if(fin>=n)
        {
            res=0;
            break;
        }
    }
    if(res) printf("Yes\n");
    else printf("No\n");
	return 0;
}