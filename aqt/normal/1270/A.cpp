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
        int n,a ,b;
        cin >> n >> a >> b;
        for(int i = 0; i<a; i++){
            int t;
            cin >> t;
            v.push_back(t);
        }
        int opt1 = *max_element(v.begin(), v.end());
        v.clear();
        for(int i = 0; i<b; i++){
            int t;
            cin >> t;
            v.push_back(t);
        }
        int opt2 = *max_element(v.begin(), v.end());
        if(opt1 > opt2){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }
}