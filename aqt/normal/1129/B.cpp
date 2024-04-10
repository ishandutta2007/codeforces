#include <bits/stdc++.h>

using namespace std;

int K;
vector<int> ans;

int main(){
    cin >> K;
    int s = 0;
    for(int i = 1; i<=2000; i++){
        if(s-i+1000000-1 >= K){
            ans.push_back(K-s+i+1);
            break;
        }
        else{
            s += 1000000;
            ans.push_back(1000000);
        }
    }
    cout << ans.size()+1 << "\n";
    cout << -1 << " ";
    for(int n : ans){
        cout << n << " ";
    }
}