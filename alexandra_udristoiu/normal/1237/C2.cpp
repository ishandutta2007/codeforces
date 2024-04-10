#include<iostream>
#include<algorithm>
using namespace std;
int n, i, u;
struct str{
    int x, y, z, ind;
};
str v[50005];
int cmp(str a, str b){
    if(a.x != b.x){
        return a.x < b.x;
    }
    if(a.y != b.y){
        return a.y < b.y;
    }
    return a.z < b.z;
}
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i].x >> v[i].y >> v[i].z;
        v[i].ind = i;
    }
    sort(v + 1, v + n + 1, cmp);
    u = 1;
    for(i = 2; i <= n; i++){
        if(u != 0 && v[i].x == v[u].x && v[i].y == v[u].y && v[i].z == v[u].z){
            cout<< v[u].ind <<" "<< v[i].ind <<"\n";
            u--;
        }
        else{
            v[++u] = v[i];
        }
    }
    n = u;
    u = 1;
    for(i = 2; i <= n; i++){
        if(u != 0 && v[i].x == v[u].x && v[i].y == v[u].y){
            cout<< v[u].ind <<" "<< v[i].ind <<"\n";
            u--;
        }
        else{
            v[++u] = v[i];
        }
    }
    n = u;
    u = 1;
    for(i = 2; i <= n; i++){
        if(u != 0 && v[i].x == v[u].x){
            cout<< v[u].ind <<" "<< v[i].ind <<"\n";
            u--;
        }
        else{
            v[++u] = v[i];
        }
    }
    n = u;
    for(i = 1; i < u; i += 2){
        cout<< v[i].ind <<" "<< v[i + 1].ind <<"\n";
    }
}