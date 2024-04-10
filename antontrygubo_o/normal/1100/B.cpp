#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);    

    int n, m;
    cin>>n>>m;
    vector<int> a(m);
    for (int i = 0; i<m; i++) {cin>>a[i]; a[i]--;}
    
    set<pair<int, int>> my;
    for (int i = 0; i<n; i++) my.insert(make_pair(0, i));
    vector<int> counter(n);
    
    int rounds = 0;
    for (int i = 0; i<m; i++)
    {
        my.erase(make_pair(counter[a[i]], a[i]));
        my.insert(make_pair(counter[a[i]]+1, a[i]));
        counter[a[i]]++;
        auto it = my.begin();
        if (it->first>rounds) {rounds++; cout<<1;}
        else cout<<0;
    }
    
}