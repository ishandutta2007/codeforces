#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int l, r;
    cin >> l >> r;
    while(l <= r){
        int n = l;
        vector<int> d;
        while(n){
            d.push_back(n%10);
            n /= 10;
        }
        sort(d.begin(), d.end());
        bool b = 1;
        for(int i = 1; i<d.size(); i++){
            b &= d[i] != d[i-1];
        }
        if(b){
            cout << l << endl;
            return 0;
        }
        l++;
    }
    cout << -1 << endl;
}