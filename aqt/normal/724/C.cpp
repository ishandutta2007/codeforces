#include <bits/stdc++.h>

using namespace std;

int N, M, K;
map<int, vector<pair<pair<int, int>, int>>> mp1, mp2;
long long ans[100005];
pair<int, int> arr[100005];
long long t = 0;

void upd(bool r, bool dir, int crntx, int crnty, int nxtx, int nxty){
    int lstx = crntx, lsty = crnty;
    vector<pair<pair<int, int>, int>> d;
    if(dir){
        d = mp2[crntx+crnty];
        mp2[crntx+crnty].clear();
    }
    else{
        d = mp1[crntx-crnty];
        mp1[crntx-crnty].clear();
    }
    sort(d.begin(), d.end());
    if(r){
        reverse(d.begin(), d.end());
    }
    for(int i = 0; i<d.size(); i++){
        t += abs(d[i].first.first - lstx) + abs(d[i].first.second - lsty);
        if(ans[d[i].second] == -1){
            ans[d[i].second] = t;
        }
        lstx = d[i].first.first, lsty = d[i].first.second;
    }
    t += abs(nxtx - lstx) + abs(nxty - lsty);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    for(int k = 1; k<=K; k++){
        ans[k] = -1;
        cin >> arr[k].first >> arr[k].second;
        mp1[arr[k].first-arr[k].second].push_back({{arr[k].first, arr[k].second}, k});
        mp2[arr[k].first+arr[k].second].push_back({{arr[k].first, arr[k].second}, k});
    }
    int crntx = 0, crnty = 0;
    int dir = 0;
    int C = N+M+2;
    while(C--){
        //cout << "ding: " << crntx << " " << crnty << " " << dir << endl;
        int nxtx = 0, nxty = 0;
        if(dir == 0){
            if(N-crntx < M-crnty){
                nxtx = N;
                nxty = crnty + N - crntx;
                dir = 3;
            }
            else{
                nxtx = crntx + M - crnty;
                nxty = M;
                dir = 1;
            }
            upd(0, 0, crntx, crnty, nxtx, nxty);
        }
        else if(dir == 1){
            if(N-crntx < crnty){
                nxtx = N;
                nxty = crnty - (N - crntx);
                dir = 2;
            }
            else{
                nxtx = crnty + crntx;
                nxty = 0;
                dir = 0;
            }
            upd(0, 1, crntx, crnty, nxtx, nxty);
        }
        else if(dir == 2){
            if(crntx < crnty){
                nxtx = 0;
                nxty = crnty - crntx;
                dir = 1;
            }
            else{
                nxtx = crntx - crnty;
                nxty = 0;
                dir = 3;
            }
            upd(1, 0, crntx, crnty, nxtx, nxty);
        }
        else{
            if(crntx < M-crnty){
                nxtx = 0;
                nxty = crnty + crntx;
                dir = 0;
            }
            else{
                nxtx = crntx - (M - crnty);
                nxty = M;
                dir = 2;
            }
            upd(1, 1, crntx, crnty, nxtx, nxty);
        }
        if((nxtx == 0 || nxtx == N) && (nxty == 0 || nxty == M)){
            break;
        }
        crntx = nxtx, crnty = nxty;
    }
    for(int k = 1; k<=K; k++){
        if(ans[k] + 1){
            ans[k] >>= 1;
        }
        cout << ans[k] << "\n";
    }
}