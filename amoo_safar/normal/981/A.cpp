#include <bits/stdc++.h>
#include <math.h>

using namespace std;
typedef int ll;
bool is_p(string a){
    for(int i = 0;i<a.size();i++){
        if(a[i] != a[a.size()-i-1])return false;
    }
    return true;
}
int main(){
    ll n;
    string b,c="";
    cin >> b;
    for(int i =b.size();i>=1;i--){
        for(int j = 0;j <= b.size()-i;j++){
            c = "";
            for( int k =0;k<i;k++){
                c = c+ b[j+k];
            }
            if(is_p(c) == false){
                cout << i ;
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}