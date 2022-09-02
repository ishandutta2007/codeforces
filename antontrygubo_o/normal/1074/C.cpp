#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void print(vector<int> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

const ll p = 1e9 + 7;


vector<pair<int, int>> boundary;

int manh(pair<int, int> a, pair<int, int> b)
{
    return fabs(a.first - b.first) + fabs(a.second - b.second);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);    

    int n;
    cin>>n;
    
    vector<pair<int, int>> my(n);
    for (int i = 0; i<n; i++) cin>>my[i].first>>my[i].second;
    
    int maxx = my[0].first;
    int maxy = my[0].second;
    int minx = my[0].first;
    int miny = my[0].second;
    
    for (int i = 0; i<n; i++)
    {
        maxx = max(maxx, my[i].first);
        minx = min(minx, my[i].first);
        maxy = max(maxy, my[i].second);
        miny = min(miny, my[i].second);
    }
    
    for (int i = 0; i<n; i++)
    {
        if (my[i].first==maxx||my[i].first==minx||my[i].second==maxy||my[i].second==miny) boundary.push_back(my[i]);
    }
    
    int b = boundary.size();
    
    int result = 0;
    for (int i = 0; i<n; i++) result+=manh(my[i], my[(i+1)%n]);
    
    int res = 0;
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<b; j++)
        for (int k = j; k<b; k++)
        res = max(res, manh(my[i], boundary[j]) + manh(my[i], boundary[k]) + manh(boundary[j], boundary[k]));
    }
    cout<<res<<' ';
    for (int i = 4; i<=n; i++) cout<<result<<' ';
    
    
    
}