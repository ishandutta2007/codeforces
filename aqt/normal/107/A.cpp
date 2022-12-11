#include <bits/stdc++.h>

using namespace std;

int N, M;
int nxt[1001], cap[1001];
bool idgr[1001], odgr[1001];

int main(){
    cin >> N >> M;
    for(int i= 1; i<=M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        odgr[a] = 1;
        idgr[b] = 1;
        nxt[a] = b;
        cap[a] = c;
    }
    int cnt = 0;
    for(int i = 1; i<=N; i++){
        if(!idgr[i] && odgr[i]){
            cnt++;
        }
    }
    cout << cnt << endl;
    for(int i = 1; i<=N; i++){
        if(!idgr[i] && odgr[i]){
            int d = INT_MAX;
            int n = i;
            while(odgr[n]){
                d = min(d, cap[n]);
                n = nxt[n];
            }
            cout << i << " " << n << " " << d << endl;
        }
    }
}