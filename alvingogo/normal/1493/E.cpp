#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

bool cmp(string a,string b){
    for(int i=a.length()-1;i>=0;i--){
        if(a[i]=='1'){
            a[i]='0';
        }
        else{
            a[i]='1';
            break;
        }
    }
    return a==b;
}
int main(){
    AquA;
    int n;
    cin >> n;
    string l,r;
    cin >> l >> r;
    if(r=="0"){
        cout << "0" << "\n";
    }
    else if(l[0]!=r[0]){
        cout << string(r.length(),'1') << "\n";
    }
    else{
        if(l!=r && !(cmp(l,r))){
            r[r.length()-1]='1';
        }
        cout << r << "\n";
    }
    return 0;
}