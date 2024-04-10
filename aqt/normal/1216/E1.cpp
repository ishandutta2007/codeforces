#include <bits/stdc++.h>

using namespace std;

long long f(long long n){
    long long lst = 1;
    long long nxt = 10;
    long long ret = 0;
    long long crnt = 0;
    long long d = 1;
    while(nxt <= n){
        ret += (nxt-lst)*crnt + (nxt-lst)*(nxt-lst+1)/2*d;
        crnt += (nxt-lst)*d;
        lst *= 10;
        nxt *= 10;
        d++;
    }
    ret += (n-lst+1)*(n-lst+2)/2*d+crnt*(n-lst+1);
    return ret;
}

long long getp(long long n){
    long long lst = 1;
    long long nxt = 10;
    long long ret = 0;
    long long crnt = 0;
    long long d = 1;
    while(1){
        long long t = crnt + d*(nxt-lst);
        if(t >= n){
            break;
        }
        crnt += d*(nxt-lst);
        nxt *= 10;
        lst *= 10;
        d++;
    }
    n-=crnt;
    //cout << "this here: " << n << endl;
    long long l = lst, r = nxt-1, ans = lst-1;
    while(l <= r){
        long long mid = l+r>>1;
        if((mid-lst+1)*d < n){
            l = mid+1;
            ans = mid;
        }
        else{
            r = mid - 1;
        }
    }
    n -= (ans-lst+1)*d;
    ans++;
    string k = to_string(ans);
    return k[n-1]-'0';
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int Q;
    cin >> Q;
    while(Q--){
        long long p;
        cin >> p;
        long long l = 1, r = 500000000, idx = 0;
        while(l <= r){
            long long mid = l+r>>1;
            if(f(mid) < p){
                idx = mid;
                l = mid+1;
            }
            else{
                r = mid - 1;
            }
        }
        //cout << "here: " << idx << endl;
        p -= f(idx);
        cout << getp(p) << endl;
    }
}