#include <bits/stdc++.h>

using namespace std;

int N, X;
bool arr[1<<18];
vector<int> v;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> X;
    vector<int> v;
    v.push_back(0);
    arr[0] = 1;
    for(int i = 1; i<1<<N; i++){
        if(!arr[i^X]){
            v.push_back(i);
            arr[i] = 1;
        }
    }
    cout << v.size()-1 << "\n";
    for(int i = 1; i<v.size(); i++){
        cout << (v[i]^v[i-1]) << " ";
    }
}