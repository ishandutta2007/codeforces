#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        vector<int> v;
        int n;
        cin >> n;
        int s = 0;
        for(int i = 0; i<n; i++){
            int k;
            cin >> k;
            v.push_back(k);
            s += k;
        }
        sort(v.begin(), v.end());
        cout << (s+n-1)/n << endl;
    }
}