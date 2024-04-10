#include<iostream>
#include<algorithm>
#define f first
#define s second
#define DIM 200005
using namespace std;
int n, t, i, st, dr, mid;
long long sum;
pair<int, int> v[DIM];
int verif(int x){
    int nr = 0, i;
    long long s = 0;
    for(i = n; i >= 1; i--){
        if(v[i].f > x){
            s += v[i].f;
            nr++;
        }
        else{
            if(v[i].s >= x && nr < n / 2 + 1){
                s += x;
                nr++;
            }
            else{
                s += v[i].f;
            }
        }
    }
    if(nr >= n / 2 + 1 && s <= sum){
        return 1;
    }
    return 0;
}
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n >> sum;
        for(i = 1; i <= n; i++){
            cin>> v[i].f >> v[i].s;
        }
        sort(v + 1, v + n + 1);
        st = 1;
        dr = 1000000000;
        while(st <= dr){
            mid = (st + dr) / 2;
            if(verif(mid)){
                st = mid + 1;
            }
            else{
                dr = mid - 1;
            }
        }
        cout<< dr <<"\n";
    }
}