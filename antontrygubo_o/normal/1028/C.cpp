#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct pt
{
    int x, y;
    bool operator==(pt& other);
};

pt ptmin(pt a, pt b)
{
    pt res;
    res.x = min(a.x, b.x);
    res.y = min(a.y, b.y);
    return res;
}

pt ptmax(pt a, pt b)
{
    pt res;
    res.x = max(a.x, b.x);
    res.y = max(a.y, b.y);
    return res;
}

void print(pt a)
{
    cout<<a.x<<' '<<a.y;
}

const int N = 1000000001;

bool pt::operator==(pt& other) 
{
    return (this->x==other.x&&this->y==other.y);
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;
    vector<pair<pt, pt>> a(n);
    for (int i = 0; i<n; i++) cin>>a[i].first.x>>a[i].first.y>>a[i].second.x>>a[i].second.y;
    vector<pt> minstart(n);
    vector<pt> maxstart(n);
    vector<pt> minend(n);
    vector<pt> maxend(n);

    minstart[0] = a[0].second;
    maxstart[0] = a[0].first;
    
    for (int i = 1; i<n; i++)
    {
       minstart[i] = ptmin(minstart[i-1], a[i].second);
       maxstart[i] = ptmax(maxstart[i-1], a[i].first);
    }
    
    minend[n-1] = a[n-1].second;
    maxend[n-1] = a[n-1].first;
    
    for (int i = n-2; i>=0; i--)
    {
       minend[i] = ptmin(minend[i+1], a[i].second);
       maxend[i] = ptmax(maxend[i+1], a[i].first);
    }
    
    if (ptmin(maxend[1], minend[1])==maxend[1]) {print(maxend[1]); return 0;}
    for (int i = 1; i<n-1; i++)
    {
        pt min1 = ptmin(minstart[i-1], minend[i+1]);
        pt max1 = ptmax(maxstart[i-1], maxend[i+1]);
        if (ptmin(min1, max1)==max1) {print(max1); return 0;}
    }
    
    print (minstart[n-2]);
    
    
}