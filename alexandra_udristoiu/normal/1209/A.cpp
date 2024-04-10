#include<iostream>
#include<algorithm>
using namespace std;
int n, i, j, nr;
int v[105], viz[105];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    sort(v + 1, v + n + 1);
    for(i = 1; i <= n; i++){
        if(viz[i] == 0){
            nr++;
            for(j = i + 1; j <= n; j++){
                if(v[j] % v[i] == 0){
                    viz[j] = 1;
                }
            }
        }
    }
    cout<< nr;
}