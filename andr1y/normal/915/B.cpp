#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define SPEED ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ld long double
int main(){
    SPEED;
    ll n, pos, l, r;
    cin >> n >> pos >> l >> r;
    if(l==1 && r==n) cout << 0;
    else if(l==1 && r!=n) cout << abs(pos-r)+1;
    else if(l!=1 && r==n) cout << abs(pos-l)+1;
    else cout << r - l + min(abs(pos - l), abs(pos - r)) + 2;
}