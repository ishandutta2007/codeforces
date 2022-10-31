#include<iostream>
#include<algorithm>
#define f first
#define s second
using namespace std;
int n, i, nr0, nr1, r;
int v[2][1005], sol[2][1005];
pair<long long, int> p[1005];
void solve(int n, int v[], int sol[]){
    for(i = 1; i <= n; i++){
        cout<<"1 1 2 "<< v[i] <<"\n";
        cout.flush();
        cin>> p[i].f;
        p[i].s = v[i];
    }
    sort(p + 1, p + n + 1);
    int st = 1, dr = n;
    for(i = 1; i < n; i++){
        cout<<"2 1 "<< p[n].s <<" "<< p[i].s <<"\n";
        cout.flush();
        cin>> r;
        if(r == -1){
            sol[st++] = p[i].s;
        }
        else{
            sol[dr--] = p[i].s;
        }
    }
    sol[st] = p[n].s;
}
int main(){
    cin>> n;
    for(i = 3; i <= n; i++){
        cout<<"2 1 2 "<< i <<"\n";
        cout.flush();
        cin>> r;
        if(r == -1){
            v[0][++nr0] = i;
        }
        else{
            v[1][++nr1] = i;
        }
    }
    solve(nr0, v[0], sol[0]);
    solve(nr1, v[1], sol[1]);
    cout<<"0 1 ";
    for(i = 1; i <= nr0; i++){
        cout<< sol[0][i] <<" ";
    }
    cout<<" 2 ";
    for(i = 1; i <= nr1; i++){
        cout<< sol[1][i] <<" ";
    }
    cout<<"\n";
}