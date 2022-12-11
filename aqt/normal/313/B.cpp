#include <bits/stdc++.h>

using namespace std;

int N, Q;
int arr[100005];

int main(){
    string s;
    cin >> s;
    N = s.size();
    for(int i = 1; i<N; i++){
        if(s[i] == s[i-1]){
            arr[i+1]++;
        }
        arr[i+1] += arr[i];
    }
    cin >> Q;
    while(Q--){
        int l, r;
        cin >> l>>r;
        cout << arr[r]-arr[l] << endl;
    }
}