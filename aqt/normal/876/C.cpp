#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> ans;
    for(int i = 0; i<min(N, 100); i++){
        int M = N-i;
        int tot = 0;
        while(M){
            tot += M%10;
            M/=10;
        }
        if(tot == i){
            ans.push_back(N-i);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int n : ans){
        cout << n << endl;
    }
}