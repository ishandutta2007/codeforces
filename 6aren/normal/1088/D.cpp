#include <bits/stdc++.h>
using namespace std;
int a[30],b[30],c[30],d[30];

int luythua(int u){
    int res=1;
    for (int i=1;i<=u;i++) res*=2;
    return res;
}
int calc(int u[]){
    int res=0;
    for (int i=29;i>=0;i--){
        res=res*2+u[i];
    }
    return res;
}

int main(){
    for (int i=29;i>=0;i--){
        c[i]=0;
        d[i]=0;
    }
    int x;
    cout << '?' << " " << calc(c) << " " << calc(d) << endl;
    fflush(stdout);
    cin >> x;
    int i=29;
    while (x!=0){
        c[i]=1;
        d[i]=1;
        int y;
        cout << '?' << " " << calc(c) << " " << calc(d) <<endl;
        fflush(stdout);
        cin >> y;
        c[i]=0;
        d[i]=0;
        if (y!=x){
            if (y==-1) {
                c[i]=1;
                d[i]=0;
            } else if (y==1){
                c[i]=0;
                d[i]=1;
            }
            cout << '?' << " " << calc(c) << " " << calc(d) << endl;
            fflush(stdout);
            cin >> x;
        }
        i--;
    }
    for (int i=29;i>=0;i--){
        if (c[i]==d[i]){
            c[i]=1;
            d[i]=0;
            cout << '?' << " " << calc(c) << " " << calc(d) << endl;
            fflush(stdout);
            cin >> x;
            if (x==1) {
                c[i]=0;
                d[i]=0;
            } else {
                c[i]=1;
                d[i]=1;
            }
        }
    }
    cout <<'!' << " " << calc(c) << " " << calc(d) << endl;
}