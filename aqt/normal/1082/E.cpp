#include <bits/stdc++.h>

using namespace std;

int N, K;
int arr[500005];
int pre[500005];
vector<int> pos[500005];

int main(){
    cin >> N >> K;
    int tot = 0;
    for(int i=1; i<=500000; i++){
        pos[i].push_back(0);
    }
    for(int i=1; i<=N; i++){
        cin >> arr[i];
        pos[arr[i]].push_back(i);
        pre[i] = pre[i-1];
        if(arr[i] == K){
            tot++;
            pre[i]++;
        }
    }
    int ans = tot;
    for(int n = 1; n<=500000; n++){
        int mini = 0, crnt = 0;
        if(n == K){
            continue;
        }
        for(int k = 1; k<pos[n].size(); k++){
            crnt++;
            crnt -= pre[pos[n][k]]-pre[pos[n][k-1]];
            mini = min(mini, crnt-1);
            ans = max(ans, tot+crnt-mini);
        }
    }
    cout << ans << endl;
}