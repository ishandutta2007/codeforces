#include<iostream>
using namespace std;
int n, m, i, j, ii, nr, x, y, jj, sol;
int w[17], frst[17], lst[17], d[16][2];
char s[105];
int modul(int x){
    if(x > 0){
        return x;
    }
    return -x;
}
int main(){
    cin>> n >> m;
    for(i = n; i >= 1; i--){
        cin>> s + 1;
        for(j = 1; j <= m + 2; j++){
            if(s[j] == '1'){
                if(frst[i] == 0){
                    frst[i] = lst[i] = j;
                }
                lst[i] = j;
            }
        }
        if(frst[i] != 0){
            w[nr] = i;
            nr++;
        }
    }
    for(i = 0, j = nr - 1; i < j; i++, j--){
        swap(w[i], w[j]);
    }
    if(nr == 0){
        cout<< 0;
        return 0;
    }
    if(nr == 1){
        if(w[0] == 1){
            sol = lst[1] - 1;
        }
        else{
            sol = lst[ w[0] ] - 1 + w[0] - 1;
        }
        cout<< sol;
        return 0;
    }
    if(w[0] == 1){
        d[0][0] = 2 * (lst[1] - 1);
        d[0][1] = m + 1;
    }
    else{
        d[0][0] = 2 * (lst[ w[0] ] - 1) + w[0] - 1;
        d[0][1] = m + 1 + w[0] - 1;
    }
    for(i = 1; i < nr - 1; i++){
        d[i][0] = min(d[i - 1][0] + 2 * (lst[ w[i] ] - 1) + w[i] - w[i - 1], d[i - 1][1] + m + 1 + w[i] - w[i - 1]);
        d[i][1] = min(d[i - 1][1] + 2 * (m + 2 - frst[ w[i] ]) + w[i] - w[i - 1], d[i - 1][0] + m + 1 + w[i] - w[i - 1]);
    }
    sol = min(d[i - 1][0] + lst[ w[i] ] - 1, d[i - 1][1] + m + 2 - frst[ w[i] ]) + w[nr - 1] - w[nr - 2];
    cout<< sol;
    return 0;
}