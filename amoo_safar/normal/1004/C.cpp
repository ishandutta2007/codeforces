#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
short int a[100000];
short int b[100000];
short int c[100000];
long nu[100000];
int main(){
    ll n;
    cin >> n;
    ll t1=0,t2=0,s=0;
    for(int i =0;i<n;i++) cin >> nu[i];
    for(int i=0;i<n;i++){
        if(c[nu[i]-1] == 0){
            c[nu[i]-1] =1;
            a[i] = 1;
            t1++;
        }
    }
    fill(c,c+n,0);
    for(int i=n-1;i>=0;i--){
        if(c[nu[i]-1] == 0){
            c[nu[i]-1] =1;
            b[i] = 1;
            t2++;
        }
    }
    //for(int i =0;i<n;i++) cout << a[i] << " ";
    //cout << endl;
    //for(int i =0;i<n;i++) cout << b[i] << " ";
    //cout << endl;
    for(int i=0;i<n-1;i++){
        t2-=b[i];
        if(a[i] == 1){
            s += t2;

        }
     //   cout << s << " ";
    }
    cout << s;
    return 0;
}