#include <bits/stdc++.h>
using namespace std;

int main(){
    long n;

    scanf("%d", &n);
    long moves [n];
    long length [n];
    string str;
    cin >> str;
    for(long i = 0; i<n; i++){
        char a = str.at(i);
        if(a == '>'){
            moves[i] = 1;
        }
        else{
            moves[i] = -1;
        }
    }
    for(long i = 0; i<n; i++){
        int d;
        scanf("%d", &d);
        length[i] = d;
    }
    long cur = 0;
    long vis[n] = {0};
    for(long i = 0; i<n+6; i++){
        long temp = length[cur] * moves[cur];
        cur += temp;
        if(cur<0 || cur>= n){
            cout<< "FINITE";
            break;
        }
        if(vis[cur] == 1){
            cout<< "INFINITE";
            break;
        }
        vis[cur] = 1;
    }

    return 0;
}