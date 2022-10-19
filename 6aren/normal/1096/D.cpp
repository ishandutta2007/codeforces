#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=100000+5;
const int MOD=998244353;

ll n, a[N], d[4][N];
string s;

int main(){
    cin >> n >> s;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    if (s[0]=='h') d[0][0]=a[0];
    for (int i=1; i<s.size(); i++){
        for (int j=3; j>=0; j--){
            d[j][i]=d[j][i-1];
        }
        if (s[i]=='h') d[0][i]+=a[i];
        else if (s[i]=='a'){
            if (d[1][i-1]!=d[0][i-1]){
                d[1][i]=min(d[0][i-1], d[1][i-1]+a[i]);
            }
        } else if (s[i]=='r'){
            if (d[2][i-1]!=d[1][i-1]){
                d[2][i]=min(d[1][i-1], d[2][i-1]+a[i]);
            }
        } else if (s[i]=='d'){
            if (d[3][i-1]!=d[2][i-1]){
                d[3][i]=min(d[2][i-1], d[3][i-1]+a[i]);
            }
        }
    }
    cout << d[3][n-1] << endl;
    return 0;
}