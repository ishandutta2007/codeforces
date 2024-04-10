#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
short int a[100000];
short int b[100000];
short int c[100000];
long nu[100000];
int main(){
    ll n,a,mi = 10000000001,ind = -1;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        a -= i;
        a+=(n-1);
        if(a/n < mi){
            mi = a/n;
            ind = i;
        }
    }
    //cout << ind;
    cout << ind+1 << endl;
    return 0;
}