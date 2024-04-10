#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
const int LIM=1e6+7;
int prime[LIM];
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        prime[1]=1;
        for(int i = 2; i < LIM; ++i) if(prime[i]==0) for(int j = 2*i; j < LIM; j+=i) prime[j]=1;
        int n;
        cin >> n;
        rep(i, n) {
                long long a;
                cin >> a;
                long long b=sqrt(a);
                if(b*b==a && prime[b]==0) cout << "YES"; else cout << "NO";
                cout << '\n';
        }
}