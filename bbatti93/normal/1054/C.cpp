#include <bits/stdc++.h>

using namespace std;

int n, ki, l[1001], r[1001], c[1001];

int main()
{
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> l[i];
        c[i]=0;
    }
    for(int i=0;i<n;i++) {
        cin >> r[i];
    }
    for(int i=n;i>0;i--) {
        for(int j=0;j<n;j++) {
            if(c[j]) continue;
            if(l[j]==0 && r[j]==0) c[j]=i;
        }
        int db=0;
        for(int j=0;j<n;j++){
            l[j]-=db;
            if(c[j]==i) db++;
        }
        db=0;
        for(int j=n-1;j>=0;j--){
            r[j]-=db;
            if(c[j]==i) db++;
        }
    }
    bool jo=true;
    for(int i=0;i<n;i++) if(c[i]==0) jo=false;
    if(jo) {
        cout << "YES" << endl;
        for(int i=0;i<n;i++) cout << c[i] << " ";
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}