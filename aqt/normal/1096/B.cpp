#include <bits/stdc++.h>

using namespace std;

long long pre, suf;
string s;

int main(){
    long long N;
    cin >> N;
    getline(cin, s);
    getline(cin, s);
    int let = s[0];
    if(s[0] != s[N-1]){
        for(int i = 1; i<N; i++){
            if(s[i] == s[0]){
                pre++;
            }
            else{
                break;
            }
        }
        pre++;
        for(int i = N-2; i>=0; i--){
            if(s[i] == s[N-1]){
                suf++;
            }
            else{
                break;
            }
        }
        suf++;
        cout << (suf + pre + 1)%998244353 << endl;
    }
    else{
        for(int i = 1; i<N; i++){
            if(s[i] == s[0]){
                pre++;
            }
            else{
                break;
            }
        }
        pre+=2;
        for(int i = N-2; i>=0; i--){
            if(s[i] == s[N-1]){
                suf++;
            }
            else{
                break;
            }
        }
        suf+=2;
        cout << (suf*pre)%998244353 << endl;
    }
}