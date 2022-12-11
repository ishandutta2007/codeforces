#include <bits/stdc++.h>

using namespace std;

int N, H;
int arr[300005];
vector<int> v;

bool check(int s){
    int tot = 0;
    for(int i = s; i<v.size(); i+=2){
        tot += v[i];
        if(tot > H){
            return 0;
        }
    }
    if(v.size()%2 == s){
        tot += v.back();
    }
    if(tot > H){
        return 0;
    }
    return 1;
}

int main(){
    cin >> N >> H;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    int ans = 0;
    for(int n = 1; n<=N; n++){
        for(int i = 1; i<=n; i++){
            v.push_back(arr[i]);
        }
        sort(v.begin(), v.end());
        if(check(1)){
            ans = n;
        }
        if(check(0)){
            ans = n;
        }
        v.clear();
    }
    cout << ans << endl;
}