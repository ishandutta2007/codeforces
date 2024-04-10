#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> arr[3][300005];
long long fact[300005];
long long MOD = 998244353;

long long mult(long long a, long long b){
    return (a*b)%MOD;
}

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

long long solve(int idx){
    int lsts = 0, cnt = 0;
    sort(arr[idx]+1, arr[idx]+1+N);
    long long ret = 1;
    for(int i= 1; i<=N; i++){
        //cout << arr[idx][i].second << " " << lsts << endl;
        //cout << "idx: " << i << " " << arr[idx][i].first << " " << arr[idx][i].second << endl;
        if(arr[idx][i].second < lsts){
            ret = 0;
        }
        lsts = arr[idx][i].second;
        if(arr[idx][i].first != arr[idx][i-1].first || arr[idx][i].second != arr[idx][i-1].second){
            ret = mult(ret, fact[cnt]);
            cnt = 1;
        }
        else{
            cnt++;
        }
    }
    ret = mult(ret, fact[cnt]);
    //cout << " " << idx << " " << ret << "\n";
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[0][i].first >> arr[0][i].second;
        arr[1][i].first = arr[0][i].first;
        arr[2][i].first = arr[0][i].second;
    }
    fact[0] = 1;
    for(int i = 1; i<=N; i++){
        fact[i] = mult(fact[i-1], i);
    }
    cout << sub(fact[N], sub(add(solve(1), solve(2)), solve(0))) << "\n";
}