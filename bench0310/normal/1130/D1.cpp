#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<int> v[n+1];
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    vector<int> idx(n+1);
    for(int o=1;o<=n;o++)
    {
        for(int i=0;i<(int)v[o].size();i++)
        {
            if(o<v[o][i]) v[o][i]-=o;
            else v[o][i]=n-(o-v[o][i]);
        }
        sort(v[o].begin(),v[o].end());
        idx[o]=v[o].size()-1;
    }
    /*for(int o=1;o<=n;o++)
    {
        for(int i=0;i<(int)v[o].size();i++) cout << v[o][i] << " ";
        cout << endl;
    }*/
    for(int s=1;s<=n;s++)
    {
        int left=m;
        vector<int> num(n+1,0); //Num of candies of type i on train
        vector<int> id=idx;
        int cnt=-1;
        for(int i=s;;i++)
        {
            cnt++;
            if(i==n+1) i=1;
            left-=num[i];
            num[i]=0;
            if(left==0) break;
            if(id[i]>=0)
            {
                int d=(i+v[i][id[i]]-1)%n+1;
                num[d]++;
                id[i]--;
            }
        }
        cout << cnt << " ";
    }
    cout << endl;
    return 0;
}