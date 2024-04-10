#include <bits/stdc++.h>

using namespace std;

int N;
string s, t;

bool solve(string k){
    string p = k;
    if(N != 1){
        k = k+k;
    }
    for(int i = 1; i<k.size(); i++){
        if(s[1] == k[i] && s[0] == k[i-1]){
            return false;
        }
        if(t[1] == k[i] && t[0] == k[i-1]){
            return false;
        }
    }
    cout << "YES" << endl;
    while(N--){
        cout << p;
    }
    exit(0);
}

bool chk(string k){
    for(int i  = 1; i<k.size(); i++){
        if(s[1] == k[i] && s[0] == k[i-1]){
            return false;
        }
        if(t[1] == k[i] && t[0] == k[i-1]){
            return false;
        }
    }
    cout << "YES" << endl;
    int X = N;
    while(X--){
        cout << k[0];
    }
    X = N;
    while(X--){
        cout << k[1];
    }
    X = N;
    while(X--){
        cout << k[2];
    }
    exit(0);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    cin >> s >> t;
    if(s[0] != s[1] && t[0] != t[1]){
        chk("abc");
        chk("acb");
        chk("bac");
        chk("bca");
        chk("cab");
        chk("cba");
    }
    solve("abc");
    solve("acb");
    solve("bac");
    solve("bca");
    solve("cab");
    solve("cba");
    cout << "NO" << endl;
}