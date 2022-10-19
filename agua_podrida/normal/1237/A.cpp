#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    bool arr = true;
    for(int i = 0; i < n; i++) {
        if(abs(a[i]) % 2 == 1) {
            if(arr) a[i]++;
            else a[i]--;
            arr = !arr;
        }
        a[i] /= 2;
    }
    for(int i = 0; i < n; i++) cout<<a[i]<<'\n';
}