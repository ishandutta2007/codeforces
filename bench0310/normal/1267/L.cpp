#include <bits/stdc++.h>

using namespace std;

bool solve(string s,int n,vector<int> cnt)
{
    int l=s.size();
    for(int o=0;o<l;o++)
    {
        int t=0;
        for(int i=0;i<=(s[o]-'a');i++) t+=cnt[i];
        if(t<n) return 0;
        t=n;
        for(int i=0;i<26;i++)
        {
            int a=min(cnt[i],t);
            cnt[i]-=a;
            t-=a;
            if(i==(s[o]-'a')) n=a;
        }
    }
    return 1;
}

int main()
{
    int n,l,k;
    cin >> n >> l >> k;
    string s;
    cin >> s;
    vector<int> cnt(26,0);
    for(int i=0;i<n*l;i++) cnt[s[i]-'a']++;
    string a;
    for(int o=0;o<l;o++)
    {
        for(int i=0;i<26;i++)
        {
            if(cnt[i]==0) continue;
            cnt[i]--;
            a+=('a'+i);
            if(solve(a,k-1,cnt)==0)
            {
                cnt[i]++;
                a.pop_back();
            }
            else break;
        }
    }
    vector<string> v(n);
    v[k-1]=a;
    int eq=k-1;
    for(int o=0;o<l;o++)
    {
        int now=0;
        int t=0;
        for(int i=k-1-eq;i<k-1;i++)
        {
            while(cnt[now]==0) now++;
            v[i]+=('a'+now);
            cnt[now]--;
            if(now==(a[o]-'a')) t++;
        }
        eq=t;
    }
    int now=0;
    for(int o=0;o<n;o++)
    {
        while((int)v[o].size()<l)
        {
            while(cnt[now]==0) now++;
            v[o]+=('a'+now);
            cnt[now]--;
        }
    }
    for(string t:v) cout << t << endl;
    return 0;
}