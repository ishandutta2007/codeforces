#include <bits/stdc++.h>
using namespace std;


bool square[200005];
int net[200005];
int main(int argc,char* argv[]){
    int tc;
    cin >> tc;

    for(int i = 0;i * i < 200005;i++){
        square[i * i ] = true;
    }
    for(int i = 200004; i>= 0; i --){
        if(i == 200004){
            net[i] = 1000000727;
        }else if(square[i]){
            net[i] = i;
        }else{
            net[i] = net[i+1];
        }
    }

    for(int i = 0; i < tc; i++  ){
        int n;
        cin >> n;

        int ret[n+1];

        int now;
        now = n-1;
        while(now >= 0){
            int nextsquare = net[now];
            int start = nextsquare - now;
            for(int i= start; i <= now; i ++){
                ret[i] = nextsquare - i;
            }
            now = start - 1;
        }
        for(int i = 0; i < n; i++){
            cout << ret[i] << " ";
        }
        cout << "\n";
    }


}