#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define id pair<int, double>
#define ii pair<id, id>
#define di pair<double, ii>

void print(vector<int> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

const ll p = 1e9 + 7;

struct dancer
{
    int x;
    int y;
    int g;
    int idx;
};

bool sortdancer(dancer a, dancer b)
{
    return a.x<b.x;
}

bool sortnew(pair<int, int> a, pair<int, int> b)
{
    if (a.first!=b.first) return (a.first<b.first);
    else return a.second>b.second;
}

int w, h;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); 
    int n;
    cin>>n>>w>>h;
    vector<pair<int, int>> hor;
    vector<pair<int, int>> ver;
    
    vector<dancer> all(n);
    
    int g, p, t;
    for (int i = 0; i<n; i++)
    {
        cin>>g>>p>>t;
        if (g==1) {all[i].x = p; all[i].y = -t; all[i].g = g; all[i].idx = i;}
        if (g==2) {all[i].x = -t; all[i].y = p; all[i].g = g; all[i].idx = i;}        
    }
    
    set<int> sums;
    
    map<int, vector<dancer>> a;
    for (int i = 0; i<n; i++) {int temp = all[i].x+all[i].y; sums.insert(temp); a[temp].push_back(all[i]);}
    vector<pair<int, int>> result(n);
    for (auto it = sums.begin(); it!=sums.end(); it++)
    {
        int temp = *it;
        sort(a[temp].begin(), a[temp].end(), sortdancer);
        vector<pair<int, int>> ans;
        for (int i = 0; i<a[temp].size(); i++) 
        {
            if (a[temp][i].g==1) ans.push_back(make_pair(a[temp][i].x, h));
            else ans.push_back(make_pair(w, a[temp][i].y));
        }
        sort(ans.begin(), ans.end(), sortnew);
        for (int i = 0; i<a[temp].size(); i++) result[a[temp][i].idx] = ans[i];
    }
    
    for (int i = 0; i<n; i++) cout<<result[i].first<<' '<<result[i].second<<endl;
    
}