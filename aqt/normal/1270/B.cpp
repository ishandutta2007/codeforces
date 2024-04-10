#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> v;
        for(int i = 1; i<=N; i++){
            int n;
            cin >> n;
            v.push_back(n);
        }
        bool b = 0;
        for(int i = 1; i<N; i++){
            if(abs(v[i]-v[i-1]) >= 2){
                cout << "YES\n";
                cout << i << " " << (i+1) << "\n";
                b = 1;
                break;
            }
        }
        if(!b){
            cout << "NO\n";
        }
    }
}