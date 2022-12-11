#include <bits/stdc++.h>

using namespace std;

int T;

bool chk(vector<int> v){
    int N = v.size();
    for(int i = 0; i<N; i++){
        if(v[i] == 1){
            int c = 2;
            for(int j = (i+1)%N; j%N != i; j++){
                if(v[j%N] != c){
                    return 0;
                }
                c++;
            }
        }
    }
    return 1;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> v;
        for(int i= 0; i<N; i++){
            int n;
            cin >> n;
            v.push_back(n);
        }
        if(chk(v)){
            cout << "YES" << endl;
            continue;
        }
        for(int i = 0; i<N; i++){
            v[i] = N-v[i]+1;
        }
        if(chk(v)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}