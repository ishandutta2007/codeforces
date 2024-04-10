#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=100000+5;
const int MOD=998244353;

ll n, a[N], d[4][N];
string s;

int main(){
    cin >> n >> s;
    int cur=0;
    for (int i=1; ;i++){
        cout << s[cur];
        cur+=i;
        if (cur>=n) break;
    }
    return 0;
}