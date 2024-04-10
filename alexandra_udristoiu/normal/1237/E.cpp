#include<iostream>
#define f first
#define s second
using namespace std;
int n, d, dn;
pair<int, int> p, pn;
int main(){
    cin>> n;
    d = 1;
    p = make_pair(0, 0);
    while(d + 1 < n){
        dn = 2 * d + 1;
        pn = make_pair(d, d);
        if(p.f % 2 == 0){
            dn++;
            pn.s++;
        }
        d = dn;
        p = pn;
    }
    if(d == n || d + 1 == n){
        cout<< 1;
    }
    else{
        cout<< 0;
    }
}