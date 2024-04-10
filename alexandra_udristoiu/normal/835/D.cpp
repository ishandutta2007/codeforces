#include<iostream>
#include<cstring>
using namespace std;
int n, i, j, ii, jj, mid;
int sum[5005], d[5005][5005], lg[10005];
char c[5005], s[10005];
int main(){
    cin>> c + 1;
    n = strlen(c + 1);
    for(i = 1; i <= n; i++){
        s[2 * i - 1] = c[i];
        s[2 * i] = '*';
    }
    ii = lg[1] = 1;
    for(i = 2; i < n + n; i++){
        if(ii + lg[ii] > i){
            lg[i] = min(ii + lg[ii] - i, lg[2 * ii - i]);
        }
        else{
            lg[i] = 1;
        }
        while(lg[i] < i && s[ i - lg[i] ] == s[i + lg[i] ]){
            lg[i]++;
        }
        if(i + lg[i] > ii + lg[ii]){
            ii = i;
        }
    }
    for(i = 1; i <= n; i++){
        for(j = i; j <= n; j++){
            ii = 2 * i - 1;
            jj = 2 * j - 1;
            mid = ii + (jj - ii + 1) / 2;
            if(mid - lg[mid] + 1 > ii){
                d[i][j] = 0;
                continue;
            }
            mid = i + (j - i + 1) / 2 - 1;
            d[i][j] = 1 + d[i][mid];
            sum[ d[i][j] ]++;
        }
    }
    for(i = n - 1; i >= 1; i--){
        sum[i] += sum[i + 1];
    }
    for(i = 1; i <= n; i++){
        cout<< sum[i] <<" ";
    }
    return 0;
}