#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int mnx, mxx, mny, mxy;
vector<int> rows[100005], cols[100005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    mnx = 1, mxx = N+1, mny = 0, mxy = M+1;
    for(int i = 1; i<=K; i++){
        int x, y;
        cin >> x >> y;
        rows[x].push_back(y);
        cols[y].push_back(x);
    }
    for(int i = 1; i<=M; i++){
        cols[i].push_back(0);
        cols[i].push_back(N+1);
        sort(cols[i].begin(), cols[i].end());
    }
    for(int i = 1; i<=N; i++){
        rows[i].push_back(0);
        rows[i].push_back(M+1);
        sort(rows[i].begin(), rows[i].end());
    }
    long long cnt = 0;
    while(true){
        int y = min(mxy-1, *upper_bound(rows[mnx].begin(), rows[mnx].end(), mny)-1);
        if(y <= mny){
            break;
        }
        cnt += y-mny;
        mxy = y;
        int x = min(mxx-1, *upper_bound(cols[mxy].begin(), cols[mxy].end(), mnx)-1);
        if(x <= mnx){
            break;
        }
        cnt += x-mnx;
        mxx = x;
        y = max(mny+1, *(--lower_bound(rows[mxx].begin(), rows[mxx].end(), mxy))+1);
        if(y >= mxy){
            break;
        }
        cnt += mxy-y;
        mny = y;
        x = max(mnx+1, *(--lower_bound(cols[mny].begin(), cols[mny].end(), mxx))+1);
        if(x >= mxx){
            break;
        }
        cnt += mxx-x;
        mnx = x;
    }
    if(cnt == 1LL*N*M-K){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}