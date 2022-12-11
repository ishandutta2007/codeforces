#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int arr[100005], cst[100005];

int main(){
    cin >> N >> M >> K;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    for(int i= 1; i<=M; i++){
        cin >> cst[i];
    }
    sort(arr+1, arr+1+N);
    sort(cst+1, cst+1+M);
    int l = 1, r = min(N, M), cnt = 0, nxt = 0;
    while(l <= r){
        int mid = l+r>>1;
        vector<pair<int, int>> v;
        for(int i = N, j = mid; i>0 && j>0; i--, j--){
            v.push_back({max(0, cst[j]-arr[i]), min(cst[j], arr[i])});
        }
        sort(v.begin(), v.end());
        int totc = 0, totm = 0;
        bool ok = 1;
        for(auto p : v){
            if(totc + p.first <= K){
                totc += p.first;
                totm += p.second;
            }
            else{
                ok = 0;
                break;
            }
        }
        if(ok){
            cnt = mid;
            nxt = max(0, totm-(K-totc));
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout << cnt << " " << nxt << endl;
}