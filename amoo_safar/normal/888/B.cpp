#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1000];
int b[603];
int main(){
    ll n;
    cin >> n;
    ll r=0,u=0,l=0,d=0;
    char a;
    for(int i =0;i<n;i++){
        cin >> a;
        if(a == 'R') r++;
        if(a == 'U') u++;
        if(a == 'D') d++;
        if(a == 'L') l++;
    }
    cout << 2*min(r,l)+2*min(u,d);
    return 0;
}