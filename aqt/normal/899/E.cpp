#include <bits/stdc++.h>

using namespace std;

int N;
int par[200005], sz[200005];
int lft[200005], rht[200005];
int arr[200005];
priority_queue<pair<int, int>> pq;

int getrt(int n){
    return par[n] = (par[n] == n ? n : getrt(par[n]));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i= 1; i<=N; i++){
        par[i] = i;
        sz[i] = 1;
        cin >> arr[i];
        lft[i] = i-1;
        rht[i] = i+1;
        if(arr[i] == arr[i-1]){
            sz[getrt(i-1)]++;
            par[i] = getrt(i-1);
        }
        pq.push({sz[getrt(i)], -getrt(i)});
    }
    int cnt = 0;
    while(pq.size()){
        auto p = pq.top();
        pq.pop();
        int n = -p.second, l = p.first;
        //cout << "p: " << n << " " << l << " " << getrt(n) << endl;
        if(sz[n] != l || getrt(n) != n){
            continue;
        }
        cnt++;
        int lst = lft[n], crnt = n;;
        for(int i = 1; i<=l; i++){
            rht[lst] = rht[crnt];
            crnt = rht[crnt];
        }
        //cout << lst << " " << crnt << endl;
        lft[crnt] = lst;
        if(arr[crnt] == arr[lst] && crnt != N+1 && lst != 0){
            sz[getrt(lst)] += sz[getrt(crnt)];
            par[getrt(crnt)] = getrt(lst);
            pq.push({sz[getrt(lst)], -getrt(lst)});
        }
    }
    cout << cnt << endl;
}