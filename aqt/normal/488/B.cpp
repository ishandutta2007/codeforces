#include <bits/stdc++.h>

using namespace std;

int N;
int a[4], b[4];
multiset<int> m;

void chk(){
    for(int i=0; i<4; i++){
        b[i] = a[i];
    }
    sort(b, b+4);
//    cout << b[0] << " " << b[1] << " " << b[2] << " " << b[3] << endl;
    if((b[0]+b[1]+b[2]+b[3])&3 || (b[1]+b[2])&1){
        return ;
    }
    if((b[3]-b[0] == (b[1]+b[2])/2 && (b[0]+b[1]+b[2]+b[3])/4 == b[3]-b[0])){
        cout << "YES" << endl;
        for(int i = N; i<4; i++){
            cout << a[i] << endl;
        }
        exit(0);
    }
}

int main(){
    cin >> N;
    if(N == 0){
        cout << "YES" << endl;
        cout << 1 << endl;
        cout << 1 << endl;
        cout << 3 << endl;
        cout << 3 << endl;
        return 0;
    }
    for(int i = 0; i<N; i++){
        cin >> a[i];
    }
    if(N == 1){
        for(int i = 1; i<=500; i++){
            a[1] = i;
            for(int j = i; j<=1500; j++){
                a[2] = j;
                if((max(j, a[0])+min(i, a[0])&1)){
                    continue;
                }
                a[3] = (max(j, a[0])+min(i, a[0]))/2 + min(a[0], i);
                chk();
            }
        }
    }
    if(N == 2){
        b[0] = a[0];
        b[1] = a[1];
        for(int i = 1; i<=1500 ;i++){
            a[2] = b[2] = i;
            for(int k = 1; k<=1500; k++){
                a[3] = b[3] = k;
                chk();
            }
        }
    }
    if(N == 3){
        b[0] = a[0];
        b[1] = a[1];
        b[2] = a[2];
        for(int i = 1; i<=1500; i++){
            a[3] = b[3] = i;
            chk();
        }
    }
    if(N == 4){
        chk();
    }
    cout << "NO" << endl;
}