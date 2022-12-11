#include <bits/stdc++.h>

using namespace std;

int N;
bool vis[100005];
int nxt[100005];
priority_queue<long long> pq;

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> nxt[i];
    }
    for(int i = 1; i<=N; i++){
        if(!vis[i]){
            int crnt = i;
            int cnt = 0;
            while(!vis[crnt]){
                vis[crnt] = 1;
                cnt++;
                crnt = nxt[crnt];
            }
            pq.push(cnt);
        }
    }
    long long tot = 0;
    if(pq.size() == 1){
        cout << pq.top()*pq.top() << endl;
        return 0;
    }
    long long t = pq.top();
    pq.pop();
    tot = (t+pq.top())*(t+pq.top());
    pq.pop();
    while(pq.size()){
        tot += pq.top()*pq.top();
        pq.pop();
    }
    cout << tot << endl;
}