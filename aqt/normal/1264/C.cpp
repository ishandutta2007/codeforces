#include <bits/stdc++.h>

using namespace std;

int N, Q;
set<int> st;
long long MOD = 998244353;
long long arr[200005];
long long pre[200005];

long long add(long long a, long long b){
    return (a+b)%MOD;
}

long long sub(long long a, long long b){
    a = add(a, -b);
    if(a < 0){
        a += MOD;
    }
    return a;
}

long long mult(long long a, long long b){
    return a*b%MOD;
}

long long qikpow(long long b, long long e){
    if(!e){
        return 1;
    }
    long long ret = qikpow(b, e/2);
    ret = mult(ret, ret);
    if(e&1){
        ret = mult(ret, b);
    }
    return ret;
}

long long divd(long long a, long long b){
    return mult(a, qikpow(b, MOD-2));
}

long long solve(int l, int r){
    long long sum = pre[r-1];
    if(l-1){
        sum = sub(sum, pre[l-2]);
    }
    return divd(sum, arr[r]);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    st.insert(1);
    st.insert(N+1);
    arr[0] = 1, pre[0] = 1;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        arr[i] = divd(arr[i], 100);
        arr[i] = mult(arr[i], arr[i-1]);
        pre[i] = add(arr[i], pre[i-1]);
    }
    long long ans = solve(1, N);
    while(Q--){
        int n;
        cin >> n;
        if(!st.count(n)){
            int lft = *(--st.lower_bound(n)), rht = *st.lower_bound(n);
            st.insert(n);
            ans = sub(ans, solve(lft, rht-1));
            ans = add(ans, solve(lft, n-1));
            ans = add(ans, solve(n, rht-1));
        }
        else{
            st.erase(n);
            int lft = *(--st.lower_bound(n)), rht = *st.lower_bound(n);
            ans = sub(ans, solve(lft, n-1));
            ans = sub(ans, solve(n, rht-1));
            ans = add(ans, solve(lft, rht-1));
        }
        cout << ans << "\n";
    }
}