#include <bits/stdc++.h>

using namespace std;

int N, M;
int lft[1000005], rht[1000005];
vector<int> cmp;
int par[2000005], cyc[2000005];

int getrt(int n){
    return par[n] = (par[n] == n ? n : getrt(par[n]));
}

bool chk(int t){
    for(int i = 1; i<=t; i++){
        par[i] = i;
        cyc[i] = 0;
    }
    for(int i =1; i<=N; i++){
        if(lft[i] > t){
            return 0;
        }
        else if(rht[i] > t){
            int p = getrt(lft[i]);
            cyc[p]++;
        }
        else{
            int pl = getrt(lft[i]), pr = getrt(rht[i]);
            if(pl == pr){
                cyc[pr]++;
            }
            else{
                par[pl] = pr;
                cyc[pr] += cyc[pl];
            }
        }
    }
    for(int i = 1; i<=t; i++){
        if(cyc[i] >= 2){
            return 0;
        }
    }
    return 1;
}

int getidx(int n){
    return lower_bound(cmp.begin(), cmp.end(), n) - cmp.begin();
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i= 1; i<=N; i++){
        cin >> lft[i] >> rht[i];
        cmp.push_back(lft[i]);
        cmp.push_back(rht[i]);
    }
    cmp.push_back(-1);
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    for(int i = 1; i<=N; i++){
        lft[i] = getidx(lft[i]);
        rht[i] = getidx(rht[i]);
    }
    M = cmp.size()-1;
    int l = 1, r = M, ans = 0;
    while(l <= r){
        int mid = l+r>>1;
        if(chk(mid)){
            r = mid - 1;
            ans = mid;
        }
        else{
            l = mid + 1;
        }
    }
    cout << cmp[ans] << "\n";
}