#include <bits/stdc++.h>

using namespace std;

int N, M;
int power[5000], nxt[5000];

int main(){
    cin >> N >> M;
    for(int i =1 ; i<=2*N; i++){
        cin >> power[i];
    }
    fill(nxt, nxt+2*N+1, 0);
    for(int i = 1; i<=M; i++){
        int a, b;
        cin >> a >> b;
        nxt[a] = b;
        nxt[b] = a;
    }
    int turn;
    cin >> turn;
    turn %=2;
    int cnt = 2*N, lat = 0;
    while(cnt--){
        if(turn){
            if(!lat){
                for(int i = 1; i<=2*N; i++){
                    if(nxt[i]){
                        lat =
                        power[lat] - power[nxt[lat]] > power[i] - power[nxt[i]] ? lat : i;
                    }
                }
                if(!lat){
                    for(int i = 1; i<=2*N; i++){
                        if(power[i]){
                            lat = power[lat] > power[i] ? lat : i;
                        }
                    }
                }
            }
            power[lat] = 0;
            nxt[nxt[lat]] = 0;
            nxt[lat] = 0;
            cout << lat << endl;
            cout.flush();
            lat = 0;
        }
        else{
            int n;
            cin >> n;
            if(nxt[n]){
                lat = nxt[n];
            }
            nxt[nxt[n]] = 0;
            nxt[n] = 0;
            power[n] = 0;
        }
        turn = (turn+1)%2;
    }
}