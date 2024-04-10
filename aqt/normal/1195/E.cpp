#include <bits/stdc++.h>

using namespace std;

int N, M, a, b;
long long s, x, y, z;
int arr[3005][3005];
pair<int, int> dq[3005][3005];
int l[3005], r[3005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> a >> b;
    cin >> s >> x >> y >> z;
    for(int i = 1; i<=N; i++){
        r[i] = -1;
        for(int j = 1; j<=M; j++){
            if(i == 1 && j == 1){

            }
            else{
                s = (s*x+y)%z;
            }
            arr[i][j] = (int) s;
        }
    }
    for(int i = 1; i<=N; i++){
        for(int k = 1; k<b; k++){
            while(l[i] <= r[i] && dq[i][r[i]].first >= arr[i][k]){
                r[i]--;
            }
            dq[i][++r[i]] = {arr[i][k], k};
        }
    }
    long long ans = 0;
    for(int j = b; j<=M; j++){
        for(int i = 1; i<=N; i++){
            while(l[i] <= r[i] && dq[i][r[i]].first >= arr[i][j]){
                r[i]--;
            }
            dq[i][++r[i]] = {arr[i][j], j};
            while(dq[i][l[i]].second <= j-b){
                l[i]++;
            }
        }
        l[0] = 0, r[0] = -1;
        for(int k = 1; k<a; k++){
            while(l[0] <= r[0] && dq[0][r[0]].first >= dq[k][l[k]].first){
                r[0]--;
            }
            dq[0][++r[0]] = {dq[k][l[k]].first, k};
        }
        for(int k = a; k<=N; k++){
            while(l[0] <= r[0] && dq[0][r[0]].first >= dq[k][l[k]].first){
                r[0]--;
            }
            dq[0][++r[0]] = {dq[k][l[k]].first, k};
            while(dq[0][l[0]].second <= k-a){
                l[0]++;
            }
            ans += dq[0][l[0]].first;
        }
    }
    cout << ans << endl;
}