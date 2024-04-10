#include<iostream>
#include<algorithm>
using namespace std;
int n, i, st, dr, mid;
long long sol;
int v[200005];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
        if(v[i] < 0){
            v[i] = -v[i];
        }
    }
    sort(v + 1, v + n + 1);
    for(i = 1; i < n; i++){
        st = i + 1;
        dr = n;
        while(st <= dr){
            mid = (st + dr) / 2;
            if(v[mid] - v[i] <= v[i]){
                st = mid + 1;
            }
            else{
                dr = mid - 1;
            }
        }
        sol += dr - i;
    }
    cout<< sol;
}