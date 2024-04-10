#include <bits/stdc++.h>

using namespace std;

vector <int> v[100000 + 100];
bool bfs[100000 + 100], mark[100000 + 100];

void f(int n){
    if (mark[n] == false) {
        for (int i = 0; i < v[n].size(); i++){
            if (mark[v[n][i]] == true){
                if (bfs[v[n][i]] == 1){
                    bfs[n] = 0;
                    mark[n] = true;
                }
                else{
                    bfs[n] = 1;
                    mark[n] = true;
                }
                break;
            }
        }
        if (mark[n] == false){
            bfs[n] = 1;
            mark[n] = true;
        }
    }
    for (int i = 0; i < v[n].size(); i++){
        if (mark[v[n][i]] == false){
            if (bfs[n] == 1){
                bfs[v[n][i]] = 0;
                mark[v[n][i]] = true;
                f(v[n][i]);
            }
            else{
                bfs[v[n][i]] = 1;
                mark[v[n][i]] = true;
                f(v[n][i]);
            }
        }
    }
    return;
}

int main (){
    int n;
    cin >> n;
    for (int i = 1; i < n; i++){
        int u, x;
        cin >> u >> x;
        v[x].push_back(u);
        v[u].push_back(x);
    }
    for (int i = 1; i <= n; i++) // 2 bakhshi kardan
        f(i);

    long long cnt1 = 0, cnt2 = 0;

    for (int i = 1; i <= n; i++){
        if (bfs[i] == 1)
            cnt1 ++;
        else
            cnt2 ++;
    }
    long long k = cnt1 * cnt2;
    cout << k - n + 1;
    return 0;
}