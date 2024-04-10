#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> opt1, opt2;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        int a, b;
        cin >> a >> b;
        if(b > a){
            opt1.push_back({-b, i});
        }
        else{
            opt2.push_back({b, i});
        }
    }
    if(opt1.size() > opt2.size()){
        sort(opt1.begin(), opt1.end());
        cout << opt1.size() << "\n";
        for(auto p : opt1){
            cout << p.second << " ";
        }
    }
    else{
        sort(opt2.begin(), opt2.end());
        cout << opt2.size() << "\n";
        for(auto p : opt2){
            cout << p.second << " ";
        }
    }
}