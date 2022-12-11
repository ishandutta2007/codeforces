#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[1005][1005];
int rcmp[1005][1005], ccmp[1005][1005];
int rsz[1005], csz[1005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i= 1; i<=N; i++){
        for(int j= 1; j<=M; j++){
            cin >> arr[i][j];
        }
    }
    for(int i= 1; i<=N; i++){
        vector<int> v;
        for(int j = 1; j<=M; j++){
            v.push_back(arr[i][j]);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        rsz[i] = v.size();
        for(int j = 1; j<=M; j++){
            int l = 0, r = rsz[i]-1;
            while(l <= r){
                int mid = (l+r)>>1;
                if(v[mid] == arr[i][j]){
                    rcmp[i][j] = mid+1;
                    break;
                }
                else if(v[mid] < arr[i][j]){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
        }
    }
    for(int i= 1; i<=M; i++){
        vector<int> v;
        for(int j = 1; j<=N; j++){
            v.push_back(arr[j][i]);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        csz[i] = v.size();
        for(int j = 1; j<=N; j++){
            int l = 0, r = csz[i]-1;
            while(l <= r){
                int mid = (l+r)>>1;
                if(v[mid] == arr[j][i]){
                    ccmp[j][i] = mid+1;
                    break;
                }
                else if(v[mid] < arr[j][i]){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
        }
    }
    for(int i= 1; i<=N; i++){
        for(int j= 1; j<=M; j++){
            int res = 0;
            res = max(rcmp[i][j], ccmp[i][j]) + max(rsz[i]-rcmp[i][j], csz[j]-ccmp[i][j]);
            printf("%d ", res);
        }
        printf("\n");
    }
}