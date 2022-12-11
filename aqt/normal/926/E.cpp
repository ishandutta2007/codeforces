#include <bits/stdc++.h>

using namespace std;

int N;
int arr[200005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int par[200005], l[200005], r[200005];

int getrt(int n){
    return par[n] = (par[n] == n ? n : getrt(par[n]));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i =1 ; i<=N; i++){
        cin >> arr[i];
        l[i] = r[i] = par[i] = i;
        if(arr[i] == arr[i-1]){
            pq.push({i-1, i});
        }
    }
    par[N+1] = N+1;
    int O = N;
    while(pq.size()){
        pair<int, int> p = pq.top();
        pq.pop();
        if(arr[getrt(p.first)] == arr[getrt(p.second)]){
            O--;
            l[getrt(p.second)] = min(l[getrt(p.second)], l[getrt(p.first)]);
            r[getrt(p.second)] = max(r[getrt(p.second)], r[getrt(p.first)]);
            par[getrt(p.first)] = getrt(p.second);
            int n = getrt(p.second);
            arr[n]++;
            if(arr[n] == arr[getrt(l[n]-1)]){
                pq.push({getrt(l[n]-1), n});
            }
            if(arr[n] == arr[getrt(r[n]+1)]){
                pq.push({n, getrt(r[n]+1)});
            }
        }
    }
    cout << O << "\n";
    for(int i =1 ; i<=N; i++){
        if(getrt(i) == i){
            cout << arr[i] << " ";
        }
    }
}