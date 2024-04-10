#include<iostream>
#include<vector>
using namespace std;
int n, i, x, nr, vecin, j;
vector<int> v[1005];
int main(){
    cin>> n;
    for(i = 2; i <= n; i++){
        cin>> x;
        v[x].push_back(i);
    }
    for(i = 1; i <= n; i++){
        if(v[i].size() == 0){
            continue;
        }
        nr = 0;
        for(j = 0; j < v[i].size(); j++){
            vecin = v[i][j];
            if(v[vecin].size() == 0){
                nr++;
            }
        }
        if(nr < 3){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}