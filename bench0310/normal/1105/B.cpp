#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> v[26];
    vector<int> id;
    id.push_back(0);
    for(int i=1;i<n;i++)
    {
        if(s[i]!=s[i-1]) id.push_back(i);
    }
    id.push_back(n);
    for(int i=0;i<(int)id.size()-1;i++)
    {
        int num=s[id[i]]-'a';
        v[num].push_back(id[i+1]-id[i]);
    }
    int best=0;
    for(int o=0;o<26;o++)
    {
        int cnt=0;
        for(int i=0;i<(int)v[o].size();i++) cnt+=v[o][i]/k;
        best=max(best,cnt);
    }
    cout << best << endl;
    return 0;
}