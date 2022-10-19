#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD=998244353;

ll ar, ntest;

int main(){
    cin >> ntest;
    while (ntest--){
        cin >> ar;
        ar=360-2*ar;
        int check=-1;
        for (int i=2; i<=360; i++){
            if (ar%i) continue;
            int unit=ar/i;
            if (360%unit==0){
                check=360/unit;
                break;
            }
        }
        cout << check << endl;
    }
    return 0;
}