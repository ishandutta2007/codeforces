#include <bits/stdc++.h>

using namespace std;

vector<int> vec;

int main(){
    int N;
    cin >> N;
    for(int i=1; i<=N; i++){
        int l, r;
        cin >> l >> r;
        vec.push_back(r);
    }
    int k;
    cin >> k;
    for(int i= 0; i<N; i++){
        if(k <= vec[i]){
            cout << N-i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
}