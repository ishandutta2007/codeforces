#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int,2>> res={{0,0},{1,0},{0,1}};
    array<int,2> now={1,1};
    for(int i=0;i<n;i++)
    {
        res.push_back({now[0],now[1]});
        res.push_back({now[0]+1,now[1]});
        res.push_back({now[0],now[1]+1});
        now[0]++;
        now[1]++;
    }
    res.push_back({now[0],now[1]});
    cout << res.size() << "\n";
    for(auto [x,y]:res) cout << x << " " << y << "\n";
    return 0;
}