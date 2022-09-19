#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll r ,g ,b;
    cin >> r >> g >> b;
    ll t = (r+g+b)/3;
    ll m =(r + g + b)%3;

    ll n = 0;
    /*
    for(int i =0;i<t;i++){
        if(r < g){
            swap(r,g);
        }
        if(r < b){
            swap(r,b);
        }
        if(g < b){
            swap(g,b);
        }
        if (r < 2){
            n++;
            break;
        }
        else{
            if (g  == 0){
                break;
            } else {
                r-=2;
                g-=1;
                n++;
            }
        }
    }
    cout << n;
    */

    cout << min(t,min(r+b,min(r+g,g+b)));
    return 0;
}