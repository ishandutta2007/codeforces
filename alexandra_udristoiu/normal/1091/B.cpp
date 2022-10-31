#include<iostream>
#include<algorithm>
#define x first
#define y second
using namespace std;
int n, i, j, ii, nr, m;
pair<int, int> va[1005], vb[1005], w[1000005];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> va[i].x >> va[i].y;
    }
    for(i = 1; i <= n; i++){
        cin>> vb[i].x >> vb[i].y;
    }
    if(n == 1){
        cout<< va[1].x + vb[1].x <<" "<< va[1].y + vb[1].y;
        return 0;
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            w[++m] = make_pair(va[i].x + vb[j].x, va[i].y + vb[j].y);
        }
    }
    sort(w + 1, w + m + 1);
    nr = 1;
    for(i = 2; i <= m; i++){
        if(w[i] == w[i - 1]){
            nr++;
        }
        else{
            nr = 1;
        }
        if(nr == n){
            cout<< w[i].x <<" "<< w[i].y;
            return 0;
        }
    }
}