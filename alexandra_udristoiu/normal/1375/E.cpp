#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, i, nr, j, x;
int a[1005];
vector<int> v[1005];
pair<int, int> p[1005];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> a[i];
        p[i] = make_pair(a[i], i);
    }
    for(i = 1; i < n; i++){
        for(j = i + 1; j <= n; j++){
            if(a[i] > a[j]){
                nr++;
                v[j].push_back(i);
            }
        }
    }
    cout<< nr <<"\n";
    sort(p + 1, p + n + 1);
    for(i = n; i >= 1; i--){
        x = p[i].second;
        for(j = 0; j < v[x].size(); j++){
            cout<< v[x][j] <<" "<< x <<"\n";
        }
    }
}