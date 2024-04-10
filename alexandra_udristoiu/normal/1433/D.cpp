#include<iostream>
using namespace std;
int n, t, i, j, nr;
int v[5005], viz[5005];
pair<int, int> w[5005];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        for(i = 1; i <= n; i++){
            cin>> v[i];
            viz[i] = 0;
        }
        nr = 0;
        for(i = 2; i <= n; i++){
            if(v[i] != v[1]){
                w[++nr] = make_pair(1, i);
                viz[i] = viz[1] = 1;
                break;
            }
        }
        if(i == n + 1){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        for(i = 2; i <= n; i++){
            if(viz[i] == 0){
                for(j = 1; j <= n; j++){
                    if(viz[j] == 1 && v[i] != v[j]){
                        w[++nr] = make_pair(i, j);
                        viz[i] = 1;
                        break;
                    }
                }
            }
        }
        for(i = 1; i < n; i++){
            cout<< w[i].first <<" "<< w[i].second <<"\n";
        }
    }
}