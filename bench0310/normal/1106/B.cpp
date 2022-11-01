#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    long long a[n],c[n],t[m],d[m];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> c[i];
    for(int i=0;i<m;i++) cin >> t[i] >> d[i];
    for(int i=0;i<m;i++) t[i]--;
    vector<pair<long long,long long> > s;
    for(int i=0;i<n;i++) s.push_back(make_pair(c[i],i));
    sort(s.begin(),s.end());
    vector<long long> v;
    int idx=0;
    for(int o=0;o<m;o++)
    {
        long long cnt=0;
        if(d[o]<=a[t[o]])
        {
            cnt=d[o]*c[t[o]];
            a[t[o]]-=d[o];
            d[o]=0;
        }
        else
        {
            d[o]-=a[t[o]];
            cnt+=a[t[o]]*c[t[o]];
            a[t[o]]=0;
            while(d[o])
            {
                if(idx>=n) break;
                if(d[o]<=a[s[idx].second])
                {
                    cnt+=d[o]*s[idx].first;
                    a[s[idx].second]-=d[o];
                    d[o]=0;
                }
                else
                {
                    d[o]-=a[s[idx].second];
                    cnt+=a[s[idx].second]*s[idx].first;
                    a[s[idx].second]=0;
                }
                if(!d[o]) break;
                idx++;
            }
        }
        if(d[o]==0) v.push_back(cnt);
        else v.push_back(0);
    }
    for(int i=0;i<m;i++) cout << v[i] << endl;
    return 0;
}