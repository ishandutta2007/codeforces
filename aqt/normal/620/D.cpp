#include <bits/stdc++.h>

using namespace std;

int N, M;
long long arr[2005], brr[2005];
long long ans;
long long Asum, Bsum;
vector<pair<int, int>> lst;
pair<long long, pair<int, int>> parr[4000000], pbrr[4000000];

long long calc(int n, int m){
    return abs(Asum-parr[n].first+pbrr[m].first-(Bsum-pbrr[m].first+parr[n].first));
}

long long lwbs(int B, long long tar){
    int l = 1, r = B, ret = 1;
    while(l <= r){
        int mid = l+r>>1;
        if(pbrr[mid].first <= tar){
            l = mid + 1;
            ret = mid;
        }
        else{
            r = mid - 1;
        }
    }
    return ret;
}

long long hgbs(int B, long long tar){
    int l = 1, r = B, ret = 1;
    while(l <= r){
        int mid = l+r>>1;
        if(pbrr[mid].first >= tar){
            r = mid - 1;
            ret = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return ret;
}

void solve(int A, int B, int lvl){
    sort(parr+1, parr+1+A);
    sort(pbrr+1, pbrr+1+B);
    for(int n = 1; n<=A; n++){
        long long o1 = lwbs(B, (Bsum+2*parr[n].first-Asum)/2);
        long long o2 = hgbs(B, (Bsum+2*parr[n].first-Asum)/2);
        long long o3 = hgbs(B, -(Asum-2*parr[n].first-Bsum)/2);
        long long o4 = hgbs(B, -(Asum-2*parr[n].first-Bsum)/2);
        if(ans > calc(n, o1)){
            ans = calc(n, o1);
            lst.clear();
            lst.push_back({parr[n].second.first, pbrr[o1].second.first});
            if(lvl == 2){
                lst.push_back({parr[n].second.second, pbrr[o1].second.second});
            }
        }
        if(ans > calc(n, o2)){
            ans = calc(n, o2);
            lst.clear();
            lst.push_back({parr[n].second.first, pbrr[o2].second.first});
            if(lvl == 2){
                lst.push_back({parr[n].second.second, pbrr[o2].second.second});
            }
        }
        if(ans > calc(n, o3)){
            ans = calc(n, o3);
            lst.clear();
            lst.push_back({parr[n].second.first, pbrr[o3].second.first});
            if(lvl == 2){
                lst.push_back({parr[n].second.second, pbrr[o3].second.second});
            }
        }
        if(ans > calc(n, o4)){
            ans = calc(n, o4);
            lst.clear();
            lst.push_back({parr[n].second.first, pbrr[o4].second.first});
            if(lvl == 2){
                lst.push_back({parr[n].second.second, pbrr[o4].second.second});
            }
        }
    }
}

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        Asum += arr[i];
    }
    cin >> M;
    for(int j = 1; j<=M; j++){
        cin >> brr[j];
        Bsum += brr[j];
    }
    ans = abs(Asum - Bsum);
    for(int i = 1; i<=N; i++){
        parr[i] = {arr[i], {i, 0}};
    }
    for(int j = 1; j<=M; j++){
        pbrr[j] = {brr[j], {j, 0}};
    }
    solve(N, M, 1);
    if(N >= 2 && M >= 2){
        int idx = 0;
        for(int i= 1; i<=N; i++){
            for(int j = i+1; j<=N; j++){
                parr[++idx] = {arr[i]+arr[j], {i, j}};
            }
        }
        idx = 0;
        for(int i = 1; i<=M; i++){
            for(int j = i+1; j<=M; j++){
                pbrr[++idx] = {brr[i] + brr[j], {i, j}};
            }
        }
        solve(N*(N-1)/2, M*(M-1)/2, 2);
    }
    cout << ans << "\n";
    cout << lst.size() << "\n";
    for(auto p : lst){
        cout << p.first << " " << p.second << "\n";
    }
}