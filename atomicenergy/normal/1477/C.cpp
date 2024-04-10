using namespace std;

#define visual

#ifdef visual
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <assert.h>
#include <functional>
#include <math.h>
#include <string>
#include <ctime>
#endif
#ifndef visual
#include <bits/stdc++.h>
#endif

typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    set<pair<pair<ll, ll>, int>> v;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        v.insert({{x, y}, i});

    }
    auto cur = *(v.begin());
    vector<int> ans;
    ans.push_back(cur.second);
    v.erase(cur);
    while(!v.empty()){
        auto oth = cur;
        for(auto o : v){
            if((o.first.first - cur.first.first)*(o.first.first - cur.first.first)
            + (o.first.second - cur.first.second)*(o.first.second - cur.first.second)
            >=
            (oth.first.first - cur.first.first)*(oth.first.first - cur.first.first)
            + (oth.first.second - cur.first.second)*(oth.first.second - cur.first.second)
            ) oth = o;
        }
        ans.push_back(oth.second);
        v.erase(oth);
        cur = oth;
    }
    for(int i=0; i<ans.size(); i++){
        cout << ans[i]+1 << " ";      
    }
    cout << endl;
    
    
}