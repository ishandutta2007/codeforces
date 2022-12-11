#include <bits/stdc++.h>

using namespace std;

int K, N;
int arr[2005][2005];
int cmin[2005], cmax[2005], rmin[2005], rmax[2005];
vector<int> add[2005], rem[2005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for(int i = 1; i<=N; i++){
        string s;
        cin >> s;
        for(int j = 1; j<=N; j++){
            arr[i][j] = (s[j-1] == 'B');
        }
    }
    int ans = 0, c = 0;
    for(int i =1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            if(arr[i][j]){
                if(!rmin[i]){
                    rmin[i] = j;
                }
                rmax[i] = j;
            }
            if(arr[j][i]){
                if(!cmin[i]){
                    cmin[i] = j;
                }
                cmax[i] = j;
            }
        }
        if(!rmin[i]){
            c++;
        }
        if(!cmin[i]){
            c++;
        }
    }
    for(int i = K; i<=N; i++){
        for(int j = i-K+1; j<=i; j++){
            if(cmax[j]-cmin[j]+1 <= K && cmax[j]){
                add[cmax[j]].push_back(j);
            }
        }
        int cnt = 0;
        for(int j = 1; j<K; j++){
            if(rmax[j] <= i && rmin[j] >= i-K+1 && rmax[j]){
                cnt++;
            }
            for(int n : add[j]){
                rem[cmin[n]].push_back(j);
                cnt++;
            }
        }
        for(int j = K; j<=N; j++){
            if(rmax[j] <= i && rmin[j] >= i-K+1 && rmax[j]){
                cnt++;
            }
            for(int n : add[j]){
                rem[cmin[n]].push_back(n);
                cnt++;
            }
            ans = max(cnt ,ans);
            if(rmax[j-K+1] <= i && rmin[j-K+1] >= i-K+1 && rmax[j-K+1]){
                cnt--;
            }
            for(int n : rem[j-K+1]){
                cnt--;
            }
        }
        for(int j = 1; j<=N; j++){
            rem[j].clear();
            add[j].clear();
        }
    }
    cout << ans + c << endl;
}

/*
4 3
WBWB
BWBW
WBWB
BWBW

*/