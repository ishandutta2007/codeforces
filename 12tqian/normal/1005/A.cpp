#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>


using namespace std;


int main(){
    int n;
    cin >> n;
    int cur = 0;
    vector<int> p;
    for(int i = 0; i<n;i ++){
        int d;
        cin >> d;
        cur += 1;
        if(d == 1&& i != 0){
            p.emplace_back(cur-1);
            cur = 1;

        }
    }
    p.emplace_back(cur);
    cout << p.size() << endl;
    for(int i = 0; i<p.size(); i++){
        cout << p[i] << " ";
    }
    return 0;
}