#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
short int a[1001][1001];
int main(){
    string a;
    cin >> a;
    for(int i =0;i<a.size();i++){
        if((a[i]-'0')<(a[a.size()-1]-'0') and ((a[i]-'0')%2 == 0)){
            swap(a[i],a[a.size()-1]);
            cout << a << endl;
            return 0;
        }
    }

    for(int i =a.size()-1;i>=0;i--){
        if((a[i]-'0')%2 == 0){
            swap(a[i],a[a.size()-1]);
            cout << a << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}