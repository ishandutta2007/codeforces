#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    int hat[n+1];
    for(int i=0;i<=n;i++) hat[i]=0;
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
        hat[arr[i]]++;
        v.push_back(make_pair(arr[i],i));
    }
    sort(v.begin(),v.end());
    bool imp=0;
    for(int i=1;i<n;i++)
    {
        if(hat[i]%(n-i))
        {
            imp=1;
            break;
        }
    }
    if(imp) cout << "Impossible" << endl;
    else
    {
        int b[n],cur=1;
        int i=0;
        while(1)
        {
            if(i>=n) break;
            int num=v[i].first;
            while(v[i].first==num)
            {
                for(int o=i;o<i+n-num;o++) b[v[o].second]=cur;
                i+=n-num;
                cur++;
            }
        }
        bool good=1;
        int total[n];
        for(int o=0;o<n;o++) total[o]=0;
        for(int o=0;o<n;o++) total[b[o]-1]++;
        for(int o=0;o<n;o++)
        {
            if((n-total[b[o]-1])!=arr[o])
            {
                good=0;
                break;
            }
        }
        if(good)
        {
            cout << "Possible" << endl;
            for(int o=0;o<n;o++) cout << b[o] << " ";
        }
        else cout << "Impossible";
        cout << endl;
    }
    return 0;
}