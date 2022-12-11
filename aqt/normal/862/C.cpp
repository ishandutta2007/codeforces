#include <bits/stdc++.h>

using namespace std;

int main(){
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    if(N == 2 && M == 0){
        cout << "NO" << endl;
        return 0;
    }
    else if(N%4 == 2 && M == 0){
        cout << "YES\n" << endl;
        int L = (N-6)/4*4;
        for(int i = 1<<17; i<(1<<17)+L; i++){
            cout << i << " ";
        }
        cout << 1 << " " << 2 << " " << 4 << " " << 8 << " " << 16 << " " << 31 << endl;
        return 0;
    }
    int L = (N-1)/4*4;
    int n1 = rand()%(1<<17), n2 = rand()%(1<<17), n3 = rand()%(1<<17);
    cout << "YES\n";
    for(int i = 1<<17; i<(1<<17)+L; i++){
        cout << i << " ";
    }
    if(N%4 == 0){
        cout << n1 << " " << n2 << " " << n3 << " " << (M^n1^n2^n3) << "\n";
    }
    else if(N%4 == 1){
        cout << M << "\n";
    }
    else if(N%4 == 2){
        cout << n1 << " " << (M^n1) << "\n";
    }
    else{
        cout << n1 << " " << n2 << " " << (M^n1^n2) << "\n";
    }
}