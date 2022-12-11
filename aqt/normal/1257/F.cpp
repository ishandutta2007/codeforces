#include <bits/stdc++.h>

using namespace std;

int N;
int arr[105];
int temp[105];
vector<int> org;
map<vector<int>, int> mp;

vector<pair<vector<int>, int>> gen(int msk){
    vector<pair<vector<int>, int>> ret;
    for(int m = msk; m>=0; m = (msk&(m-1))){
        for(int n = 1; n<=N; n++){
            temp[n] = __builtin_popcount(arr[n]^m);
        }
        vector<int> v;
        for(int k = 2; k<=N; k++){
            v.push_back(temp[k]-temp[k-1]);
        }
        ret.push_back({v, m});
        if(!m){
            break;
        }
    }
    return ret;
}

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        if(i-1){
            org.push_back(__builtin_popcount(arr[i]) - __builtin_popcount(arr[i-1]));
        }
    }
    auto v = gen((1<<15)-1);
    for(auto k : v){
        mp[k.first] = k.second;
    }
    v = gen(((1<<30)-1)^((1<<15)-1));
    for(auto k : v){
        for(int i = 0; i<N-1; i++){
            k.first[i] = (org[i]-k.first[i]);
        }
        if(mp.count(k.first)){
            cout << (k.second^mp[k.first]);
            return 0;
        }
    }
    cout << -1;
}