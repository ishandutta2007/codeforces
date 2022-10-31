#include<iostream>
#define x first
#define y second
using namespace std;
int n, i, ok, j;
pair<int, int> v[100005];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i].x >> v[i].y;
    }
    if(n % 2 == 1){
        cout<<"No";
        return 0;
    }
    ok = 1;
    v[n + 1] = v[1];
    for(i = 1, j = n / 2 + 1; i <= n / 2; i++, j++){
        if(v[i].x - v[i + 1].x != v[j + 1].x - v[j].x || v[i].y - v[i + 1].y != v[j + 1].y - v[j].y){
            ok = 0;
            break;
        }
    }
    if(ok == 1){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}