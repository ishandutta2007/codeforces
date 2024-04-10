#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;

int a[N], maxi[N], n;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int maxii=0;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        maxi[i]=0;
        for (int j=1; j<=a[i]; j++){
            int x;
            cin >> x;
            maxi[i]=max(maxi[i], x);
        }
        maxii=max(maxi[i], maxii);
    }
    long long res=0;
    for (int i=1; i<=n; i++){
        res+=1LL*a[i]*(maxii-maxi[i]);
    }
    cout << res;
}