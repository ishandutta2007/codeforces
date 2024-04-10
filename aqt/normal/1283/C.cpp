#include <bits/stdc++.h>

using namespace std;

int nxt[200005];
bool has[200005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> nxt[i];
        has[nxt[i]] = 1;
    }
    vector<int> h, t;
    for(int i = 1; i<=N; i++){
        if(!has[i]){
            int crnt = i;
            while(nxt[crnt]){
                crnt = nxt[crnt];
            }
            h.push_back(i);
            t.push_back(crnt);
        }
    }
    for(int n = 0; n<h.size(); n++){
        nxt[t[n]] = h[(n+1)%h.size()];
    }
    for(int i = 1; i <=N; i++){
        cout << nxt[i] << " ";
    }
}