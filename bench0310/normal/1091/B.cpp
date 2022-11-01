#include <bits/stdc++.h>

using namespace std;

bool arr[1000][1000];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int,int> > a,b;
    int x,y;
    for(int i=0;i<n;i++)
    {
        cin >> x >> y;
        a.push_back(make_pair(x,y));
    }
    for(int i=0;i<n;i++)
    {
        cin >> x >> y;
        b.push_back(make_pair(x,y));
    }
    for(int o=0;o<n;o++)
    {
        bool good=1;
        int tx=a[0].first+b[o].first;
        int ty=a[0].second+b[o].second;
        arr[o][o]=1;
        for(int i=1;i<n;i++)
        {
            x=tx-a[i].first;
            y=ty-a[i].second;
            bool p=0;
            for(int j=0;j<n;j++)
            {
                if(arr[o][j]) continue;
                if(b[j].first==x&&b[j].second==y)
                {
                    arr[o][j]=1;
                    p=1;
                    break;
                }
            }
            if(!p)
            {
                good=0;
                break;
            }
        }
        if(good)
        {
            cout << tx << " " << ty << endl;
            break;
        }
    }
    return 0;
}