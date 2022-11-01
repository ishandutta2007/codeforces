#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    vector<int> p(n+1,0);
    vector<int> l(q),r(q);
    for(int i=0;i<q;i++)
    {
        cin >> l[i] >> r[i];
        l[i]--; r[i]--;
        p[l[i]]++;
        p[r[i]+1]--;
    }
    int t=0;
    int res=0;
    set<int> one,two;
    for(int i=0;i<n;i++)
    {
        t+=p[i];
        if(t) res++;
        if(t==1)
        {
            one.insert(i);
            two.insert(i);
        }
        if(t==2) two.insert(i);
    }
    int m=1000000;
    for(int o=0;o<q-1;o++)
    {
        for(int i=o+1;i<q;i++)
        {
            if(l[o]>r[i]||l[i]>r[o]) m=min(m,distance(one.lower_bound(l[i]),one.upper_bound(r[i]))+distance(one.lower_bound(l[o]),one.upper_bound(r[o])));
            else if(l[o]==r[i]) m=min(m,distance(one.lower_bound(l[i]),one.upper_bound(r[i]-1))+distance(one.lower_bound(l[o]+1),one.upper_bound(r[o]))+(two.find(l[o])!=two.end()));
            else if(l[i]==r[o]) m=min(m,distance(one.lower_bound(l[o]),one.upper_bound(r[o]-1))+distance(one.lower_bound(l[i]+1),one.upper_bound(r[i]))+(two.find(l[i])!=two.end()));
            else if(l[o]<=l[i]&&r[i]<=r[o]) m=min(m,distance(one.lower_bound(l[o]),one.upper_bound(l[i]-1))+distance(two.lower_bound(l[i]),two.upper_bound(r[i]))+distance(one.lower_bound(r[i]+1),one.upper_bound(r[o])));
            else if(l[i]<=l[o]&&r[o]<=r[i]) m=min(m,distance(one.lower_bound(l[i]),one.upper_bound(l[o]-1))+distance(two.lower_bound(l[o]),two.upper_bound(r[o]))+distance(one.lower_bound(r[o]+1),one.upper_bound(r[i])));
            else m=min(m,distance(one.lower_bound(min(l[o],l[i])),one.upper_bound(max(l[o],l[i])-1))+distance(two.lower_bound(max(l[o],l[i])),two.upper_bound(min(r[o],r[i])))+distance(one.lower_bound(min(r[o],r[i])+1),one.upper_bound(max(r[o],r[i]))));
        }
    }
    cout << res-m << endl;
    return 0;
}