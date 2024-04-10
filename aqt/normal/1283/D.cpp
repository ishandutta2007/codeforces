#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[200005];
long long pre[200005];
set<int> ans, tree;
queue<int> qu;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        tree.insert(arr[i]);
        qu.push(arr[i]+1);
        qu.push(arr[i]-1);
    }
    sort(arr+1, arr+1+N);
    arr[N+1] = INT_MAX;
    for(int i = 1; i<=N; i++){
        pre[i] += pre[i-1];
    }
    arr[0] = INT_MIN;
    long long res = 0;
    while(M){
        int n = qu.front();
        qu.pop();
        if(tree.count(n) || ans.count(n)){
            continue;
        }
        M--;
        int k = (lower_bound(arr+1, arr+1+N, n)-arr);
        int k1 = arr[k-1];
        int k2 = *lower_bound(arr+1, arr+1+N, n);
        long long dis1 = 1LL*n-k1, dis2 = 1LL*k2-n;
        qu.push(n-1), qu.push(n+1);
        ans.insert(n);
        res += min(dis1, dis2);
    }
    cout << res << "\n";
    for(int n : ans){
        cout << n << " ";
    }
}