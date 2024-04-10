#include <bits/stdc++.h>

using namespace std;

int N;
int arr[4], brr[4];
vector<int> v;

void solve(int s){
    for(int i = 0; i<4; i++){
        brr[i] = arr[i];
    }
    v.clear();
    if(brr[s]){
        brr[s]--;
        v.push_back(s);
    }
    else{
        return;
    }
    for(int i = 2; i<=N; i++){
        if(v.back() && brr[v.back()-1]){
            brr[v.back()-1]--;
            v.push_back(v.back()-1);
        }
        else if(v.back() != 3 && brr[v.back()+1]){
            brr[v.back()+1]--;
            v.push_back(v.back()+1);
        }
        else{
            return;
        }
    }
    cout << "YES\n";
    for(int n : v){
        cout << n << " ";
    }
    exit(0);
}

int main(){
    cout.tie(0);
    for(int i = 0; i<4; cin >> arr[i++]);
    for(int i = 0; i<4; N += arr[i++]);
    for(int i = 0; i<4; solve(i++));
    cout << "NO\n";
}