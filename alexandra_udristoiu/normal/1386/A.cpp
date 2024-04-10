#include<iostream>
using namespace std;
int t, nr;
long long st, dr, mid, n, x;
int query(long long x){
    cout<<"? "<< x <<"\n";
    cout.flush();
    int r;
    cin>> r;
    return r;
}
void cauta(long long st, long long dr){
    if(st == dr){
        nr = 0;
        x = n;
    }
    else{
        long long mid = (st + dr) / 2;
        cauta(mid + 1, dr);
        nr++;
        if(nr % 2 == 0){
            x += mid;
        }
        else{
            x -= mid;
        }
    }
}
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        cauta(1, n - 1);
        query(x);
        st = 1;
        dr = n - 1;
        while(st <= dr){
            mid = (st + dr) / 2;
            if(nr % 2 == 1){
                x += mid;
            }
            else{
                x -= mid;
            }
            nr++;
            if(query(x) == 0){
                st = mid + 1;
            }
            else{
                dr = mid - 1;
            }
        }
        cout<<"= "<< st <<"\n";
    }
}