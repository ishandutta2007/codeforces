#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
short int a[1001][1001];
int main(){
    ll n,m,k,x,y,x2,y2;
    bool f;
    ll i2,j2;
    cin >> n >> m >> k ;
    for(int i = 0;i<k;i++){
        cin >> x >> y;
        a[x][y] = 1;

        f = true;
        x2 = x;
        y2 = y;
        for(i2 = x2;i2<x2+2;i2++){
            for(j2 = y2;j2<y2+2;j2++){
                if(a[i2][j2] == 0) f= false;
            }
        }
        if(f == true){
            cout << i+1 << endl;
            return 0;
        }

        f = true;
        x2 = max((ll)0,x-1);
        y2 = y;
        for(i2 = x2;i2<x2+2;i2++){
            for(j2 = y2;j2<y2+2;j2++){
                if(a[i2][j2] == 0) f= false;
            }
        }
        if(f == true){
            cout << i+1 << endl;
            return 0;
        }

        f = true;
        x2 = max((ll)0,x-1);
        y2 = max((ll)0,y-1);
        for(i2 = x2;i2<x2+2;i2++){
            for(j2 = y2;j2<y2+2;j2++){
                if(a[i2][j2] == 0) f= false;
            }
        }
        if(f == true){
            cout << i+1 << endl;
            return 0;
        }

        f = true;
        x2 = x;
        y2 = max((ll)0,y-1);
        for(i2 = x2;i2<x2+2;i2++){
            for(j2 = y2;j2<y2+2;j2++){
                if(a[i2][j2] == 0) f= false;
            }
        }
        if(f == true){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << 0 <<endl;
    return 0;
}