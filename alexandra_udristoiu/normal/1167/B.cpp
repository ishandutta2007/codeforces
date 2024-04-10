#include<iostream>
#define f first
#define s second
using namespace std;
int i, j, prod, ok;
int sol[10];
int v[] = {0, 4, 8, 16, 15, 23, 42};
pair<int, int> p[10000];
int main(){
    for(i = 1; i < 6; i++){
        for(j = i + 1; j <= 6; j++){
            p[ v[i] * v[j] ] = make_pair(v[i], v[j]);
        }
    }
    cout<<"? 1 2\n";
    cout.flush();
    cin>> prod;
    sol[1] = p[prod].f;
    sol[2] = p[prod].s;
    cout<<"? 2 3\n";
    cout.flush();
    cin>> prod;
    if(sol[1] == p[prod].f || sol[1] == p[prod].s){
        swap(sol[1], sol[2]);
    }
    sol[3] = p[prod].f + p[prod].s - sol[2];
    for(i = 4; i <= 5; i++){
        cout<<"? "<< i - 1 <<" "<< i <<"\n";
        cout.flush();
        cin>> prod;
        sol[i] = prod / sol[i - 1];
    }
    for(i = 1; i <= 6; i++){
        ok = 1;
        for(j = 1; j <= 5; j++){
            if(v[i] == sol[j]){
                ok = 0;
                break;
            }
        }
        if(ok == 1){
            sol[6] = v[i];
            break;
        }
    }
    cout<<"! ";
    for(i = 1; i <= 6; i++){
        cout<< sol[i] <<" ";
    }
}