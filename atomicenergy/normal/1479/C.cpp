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
    
    int l, r;
    cin >> l >> r;
    vector<pair<pair<int, int>, int> > ans;
    if(l == 1){
        ans.push_back({{1, 32}, 1});
        l = 2;
        if(r == 1){
            cout << "YES" << endl;
            cout << 32 << " " << ans.size() << endl;
            for(auto p : ans){
                cout << p.first.first << " " << p.first.second << " " << p.second << endl;
            }
            return 0;
        }
    }
    ans.push_back({{1, 2}, l-1});
    r -= (l-1);
    l = 1;
    
    for(int i=3; i<32; i++){
        for(int j=i+1; j<=32; j++){
            ans.push_back({{i, j}, 1 << max(0, (31 - j))});
        }
    }
    //31 goes from 1-1
    //30 goes from 1-2
    //29 goes from 1-4
    //...
    //n goes from 1 - (2 ^ (31 - n))
    //3 goes from 1 - 268435456 (excessive)

    for(int i=3; i<32; i++){
        if((1 << (31 - i)) + 1 > r ) continue;
        ans.push_back({{2, i}, (r - (1 << (31 - i)))});
        r = (r - (1 << (31 - i)));

    }
    ans.push_back({{2, 32}, 1});
    cout << "YES" << endl;
    cout << 32 << " " << ans.size() << endl;
    for(auto p : ans){
        cout << p.first.first << " " << p.first.second << " " << min(1000000, p.second) << endl;
    }
}