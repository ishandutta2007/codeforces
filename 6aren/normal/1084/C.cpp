#include <bits/stdc++.h>
using namespace std;
const long long MOD=1000000007;
string s;
int a[100005];
int main(){
    cin >> s;
    int sw=0;
    int id=0;
    for (int i=0; i<=10004; i++) a[i]=0;
    for (int i=0; i<s.size(); i++){
        if (sw==0 && s[i]=='a'){
            a[id]++;
        }
        if (sw==0 && s[i]=='b') sw=1;
        if (sw==1 && s[i]=='a'){
            sw=0;
            id++;
            a[id]++;
        }
    }
    long long res=1;
    for (int i=0; i<=id; i++){
        //cout << a[i] << endl;
        res=res*(a[i]+1)%MOD;
    }
    res=(res+MOD-1)%MOD;
    cout << res;
}