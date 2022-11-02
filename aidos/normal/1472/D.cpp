#include <bits/stdc++.h>

using namespace std;
const int maxn = (int)2e5 + 100;
typedef long long ll;
int n;
int a[maxn];


void solve(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    reverse(a, a + n);
    ll A[2] = {0, 0};
    for(int i = 0; i < n; i++) {
        if(i % 2 == a[i] % 2) {
            A[i % 2] += a[i];
        }
    }
    if(A[0] > A[1]) {
        printf("Alice\n");
    } else if(A[0] < A[1]) {
        printf("Bob\n");
    } else {
        printf("Tie\n");
    }
}


int main() {
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t = 1;
    scanf("%d", &t);

    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        //cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}