#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n, k, i, sum, nr;
char v[100005];
int main(){
    cin>> k;
    cin>> v + 1;
    n = strlen(v + 1);
    for(i = 1; i <= n; i++){
        v[i] -= '0';
        sum += v[i];
    }
    sort(v + 1, v + n + 1);
    i = 1;
    while(sum < k){
        nr++;
        sum += 9 - v[i];
        i++;
    }
    cout<< nr;
    return 0;
}