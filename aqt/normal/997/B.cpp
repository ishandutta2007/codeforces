#include <bits/stdc++.h>

using namespace std;

long long N;
set<int> v[21];

int main(){
    cin >> N;
    v[0].insert(0);
    for(int i = 1; i<21; i++){
        for(int k : v[i-1]){
            v[i].insert(k+1);
            v[i].insert(k+5);
            v[i].insert(k+10);
            v[i].insert(k+50);
        }
    }
    if(N <= 20){
        cout << v[N].size() << endl;
    }
    else{
        N -= 12;
        cout << 49*N+341 << endl;
    }
}