#include<iostream>
#define VAL 2000000000LL
using namespace std;
long long n, h, st, dr, mid, val, x;
long long cautbin(long long n){
    long long st = 1, dr = n, mid;
    while(st <= dr){
        mid = (st + dr) / 2;
        if(n - mid <= mid + h - 1){
            dr = mid - 1;
        }
        else{
            st = mid + 1;
        }
    }
    return st;
}
int main(){
    cin>> n >> h;
    st = 1;
    dr = n;
    while(st <= dr){
        mid = (st + dr) / 2;
       // mid = 6;
        if(mid <= h){
            if(mid > VAL){
                dr = mid - 1;
            }
            else{
                if(mid * (mid + 1) / 2 >= n){
                    dr = mid - 1;
                }
                else{
                    st = mid + 1;
                }
            }
        }
        else{
            x = cautbin(mid) + 1;
            if(mid - x + 1 > VAL){
                dr = mid - 1;
            }
            else{
                val = n - (mid - x + 1) * (mid - x + 2) / 2;
                x--;
                if(val / h < x){
                    dr = mid - 1;
                }
                else{
                    val -= x * h;
                    if(x > VAL){
                        dr = mid - 1;
                    }
                    else{
                        if(val <= x * (x - 1) / 2){
                            dr = mid - 1;
                        }
                        else{
                            st = mid + 1;
                        }
                    }
                }
            }
        }
    }
    cout<< st;
}