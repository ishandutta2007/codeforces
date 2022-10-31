#include<iostream>
#include<algorithm>
using namespace std;
int n, k, i, u, j;
long long sol;
char c[200005];
int v[200005], w[200005];
int cmp(int a, int b){
    return a > b;
}
int main(){
    cin>> n >> k;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    cin>> c + 1;
    for(i = 1; i <= n; i++){
        u = i;
        while(u < n && c[u + 1] == c[i]){
            u++;
        }
        if(u - i + 1 <= k){
            for(j = i; j <= u; j++){
                sol += v[j];
            }
        }
        else{
            for(j = i; j <= u; j++){
                w[j - i + 1] = v[j];
            }
            sort(w + 1, w + u - i + 2, cmp);
            for(j = 1; j <= k; j++){
                sol += w[j];
            }
        }
        i = u;
    }
    cout<< sol;
}