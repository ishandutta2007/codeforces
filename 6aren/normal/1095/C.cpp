#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=100000+5;
const int MOD=998244353;

ll n, k ,a[100];
string s;

int mu2(int u){
    int res=1;
    for (int i=1; i<=u; i++){
        res*=2;
    }
    return res;
}

int main(){
    cin >> n >> k;
    int id=0, cnt=0;
    while (n){
        if (n%2) cnt++;
        a[id]=n%2;
        id++;
        n/=2;
    }
    k-=cnt;
    while (k>0){
        int check=0;
        for (int i=id; i>=1; i--){
            if (a[i]){
                a[i]--;
                a[i-1]+=2;
                check=1;
                k--;
                break;
            }
        }
        if (!check) break;
    }
    if (k!=0) cout << "NO";
    else {
        cout << "YES \n";
        for (int i=0; i<id; i++){
            for (int j=0; j<a[i]; j++){
                cout << mu2(i) << " ";
            }
        }
    }
    return 0;
}