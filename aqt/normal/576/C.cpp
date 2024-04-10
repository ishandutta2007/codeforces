#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<pair<int, int>, int>> part[1005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        int x, y;
        cin >> x >> y;
        part[y/1000].push_back({{x, y}, i});
    }
    for(int i = 0; i<=1000; i++){
        sort(part[i].begin(), part[i].end());
        if(i&1){
            reverse(part[i].begin(), part[i].end());
        }
        for(auto n : part[i]){
            cout << n.second << " ";
        }
    }
}