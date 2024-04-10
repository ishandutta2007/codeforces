#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int b,p,f,h,c,sum=0,tmp;
        cin >> b >> p >> f >> h >> c;
        b/=2;
        if (h<c) {
            tmp=min(b,f);
            b-=tmp;
            f-=tmp;
            sum+=c*tmp;
            tmp=min(b,p);
            b-=tmp;
            p-=tmp;
            sum+=h*tmp;
        } else {
            tmp=min(b,p);
            b-=tmp;
            p-=tmp;
            sum+=h*tmp;
            tmp=min(b,f);
            b-=tmp;
            f-=tmp;
            sum+=c*tmp;
        }
        cout << sum << endl;
    }
}