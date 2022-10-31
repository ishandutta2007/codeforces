#include<iostream>
#include<algorithm>
using namespace std;
int n, k, x, u, i;
int v[100005];
int main(){
    cin>> n >> k;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    sort(v + 1, v + n + 1);
    u = 1;
    x = 0;
    for(i = 1; i <= k; i++){
        while(u <= n && v[u] == x){
            u++;
        }
        if(u == n + 1){
            cout<<"0\n";
        }
        else{
            cout<< v[u] - x <<"\n";
            x = v[u];
        }
    }
}