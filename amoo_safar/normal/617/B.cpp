#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    ll t = 1;
    int f = 0;
    ll c = 1;
    int a;
    for(int i=0;i<n;i++){
        cin >> a;
        if(a == 1){
            if(f == 1){
                t *= c;
                c = 1;
            } else {
                f = 1;
                c = 1;
            }
        } else {
            c++;
        }
    }
    if(f == 0) cout << 0;
    else cout << t << endl;
    return 0;
}