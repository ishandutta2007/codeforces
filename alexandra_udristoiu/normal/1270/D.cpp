#include<iostream>
using namespace std;
int n, k, x, vx, y, vy, r, vr, ok, nr, j, i;
int main(){
    cin>> n >> k;
    cout<<"? ";
    for(i = 1; i <= k; i++){
        cout<< i <<" ";
    }
    cout<< endl;
    cin>> x >> vx;
    cout<<"? ";
    for(i = 1; i <= k + 1; i++){
        if(i != x){
            cout<< i <<" ";
        }
    }
    cout<< endl;
    cin>> y >> vy;
    if(y == k + 1){
        for(i = 1; i <= k; i++){
            if(i != x){
                cout<<"? ";
                for(j = 1; j <= k + 1; j++){
                    if(j != i){
                        cout<< j <<" ";
                    }
                }
                cout<< endl;
                cin>> r >> vr;
                if(r == x){
                    nr++;
                }
            }
        }
        if(vy < vx){
            cout<<"! "<< nr + 1;
        }
        else{
            cout<<"! "<< k - nr;
        }
    }
    else{
        cout<<"? ";
        for(i = 1; i <= k + 1; i++){
            if(i != y){
                cout<< i <<" ";
            }
        }
        cout<< endl;
        cin>> r >> vr;
        if(r == x){
            ok = 1;
            nr++;
        }
        for(i = 1; i < k + 1; i++){
            if(i != x && i != y){
                cout<<"? ";
                for(j = 1; j <= k + 1; j++){
                    if(j != i){
                        cout<< j <<" ";
                    }
                }
                cout<< endl;
                cin>> r >> vr;
                if(r == x){
                    nr++;
                }
            }
        }
        if( (vy < vx && ok == 1) || (vy > vx && ok == 0) ){
            cout<<"! "<< nr + 1;
        }
        else{
            cout<<"! "<< k - nr;
        }
    }
}