#include<iostream>
using namespace std;
int v[5], i, ok0, ok1, x;
void solve(int a, int b){
    if(v[a] - v[b] > 1 || v[b] - v[a] > 1){
        cout<<"NO";
    }
    else{
        cout<<"YES\n";
        if(v[a] < v[b]){
            swap(a, b);
        }
        for(i = 1; i <= v[b]; i++){
            cout<< a - 1 <<" "<< b - 1 <<" ";
        }
        if(v[a] > v[b]){
            cout<< a - 1 <<" ";
        }
    }
}
int main(){
    cin>> v[1] >> v[2] >> v[3] >> v[4];
    if(v[2] + v[3] + v[4] == 0){
        if(v[1] == 1){
            cout<<"YES\n0";
        }
        else{
            cout<<"NO\n";
        }
        return 0;
    }
    if(v[2] + v[3] + v[1] == 0){
        if(v[4] == 1){
            cout<<"YES\n3";
        }
        else{
            cout<<"NO";
        }
        return 0;
    }
    if(v[1] + v[2] == 0){
        solve(3, 4);
        return 0;
    }
    if(v[3] + v[4] == 0){
        solve(1, 2);
        return 0;
    }
    if(v[2] < v[1] || v[3] < v[4]){
        cout<<"NO";
        return 0;
    }
    v[2] -= v[1];
    v[3] -= v[4];
    if(v[2] - v[3] > 1 || v[3] - v[2] > 1){
        cout<<"NO";
        return 0;
    }
    if(v[2] - v[3] == 0){
        x = v[2];
    }
    else{
        if(v[2] - v[3] == 1){
            x = v[3];
            ok0 = 1;
        }
        else{
            x = v[2];
            ok1 = 1;
        }
    }
    cout<<"YES\n";
    if(ok0 == 1){
        cout<<"1 ";
    }
    for(i = 1; i <= v[1]; i++){
        cout<<"0 1 ";
    }
    for(i = 1; i <= x; i++){
        cout<<"2 1 ";
    }
    for(i = 1; i <= v[4]; i++){
        cout<<"2 3 ";
    }
    if(ok1 == 1){
        cout<<"2 ";
    }
}