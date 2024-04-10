#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    scanf("%d", &n);
    vector<int> A(n);
    for(int i = 0; i < n; i++) scanf("%d", &A[i]);
    vector<int> L, R, D;
    for(int i = 0; i < n - 1; i++){
        int ind = -1;
        int min_ = 1000000001;
        for(int j = i; j < n; j++){
            if(A[j] < min_){
                min_ = A[j];
                ind = j;
            }
        }
        if(i == ind) continue;
        L.push_back(i + 1);
        R.push_back(n);
        D.push_back(ind - i);
        vector<int> tmp;
        for(int j = i; j < n; j++) tmp.push_back(A[j]);
        for(int j = i; j < n; j++) A[j] = tmp[(j - i + ind - i) % (n - i)];
    }
    cout << L.size() << "\n";
    for(int i = 0; i < L.size(); i++) cout << L[i] << " " << R[i] << " " << D[i] << "\n";
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    
}