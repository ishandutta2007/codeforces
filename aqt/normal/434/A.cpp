#include <bits/stdc++.h>

using namespace std;

int K, N;
int arr[100005];
vector<int> v[100005];

int main(){
    cin >> K>>N;
    long long tot = 0;
    cin >> arr[1];
    for(int i = 2; i<=N; i++){
        cin >> arr[i];
        tot += abs(arr[i] - arr[i-1]);
        if(arr[i] != arr[i-1]){
            v[arr[i]].push_back(arr[i-1]);
            v[arr[i-1]].push_back(arr[i]);
        }
    }
    long long b = 0;
    for(int k= 1; k<=K; k++){
        if(v[k].empty()){
            continue;
        }
        sort(v[k].begin(), v[k].end());
        long long t = 0;
        for(int n : v[k]){
            t -= abs(n-k);
        }
        int midx = v[k].size()/2;
        int mid = v[k][midx];
        for(int n : v[k]){
            t += abs(n-mid);
        }
        b = min(b, t);
    }
    cout << tot + b << endl;
}