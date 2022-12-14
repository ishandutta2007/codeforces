#include <bits/stdc++.h>

using namespace std;

long long c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
long long gcd(long long a, long long b){
    while(a && b){
        if(a > b)a %= b; else b %= a;
    }
    return a + b;
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    while(n--){
        cin >> a1 >> b1 >> c1;
        long long ku = __gcd(a1, b1);
        a1 /= ku;
        b1 /= ku;
        while(b1 != 1){
                k = gcd(b1, c1);
                if(k == 1)break;
                while(b1 % k == 0)b1 /= k;
        }
        if(b1 == 1)cout << "Finite\n"; else cout << "Infinite\n";
    }
    return 0;
}