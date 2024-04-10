#include <bits/stdc++.h>

using namespace std;

int N;
vector<long long> pr[2];
vector<long long> val[2];

void init(long long n, int idx, int t){
    if(idx == pr[t].size()){
        return;
    }
    if(1e18/n < pr[t][idx]){
        return;
    }
    if(pr[t][idx]*n > n && pr[t][idx]*n <= 1e18){
        val[t].push_back(pr[t][idx]*n);
        init(pr[t][idx]*n, idx, t);
    }
    init(n, idx+1, t);
}

long long chk(long long n){
    long long cnt = 0;
    int idx2 = 0;
    for(;idx2<val[1].size(); idx2++){
        if(val[1][idx2] > n){
            break;
        }
    }
    idx2--;
    for(int idx1 = 0; idx1<val[0].size(); idx1++){
        while(val[0][idx1] > n/val[1][idx2]){
            if(idx2 == 0){
                //cout << n << " " << cnt << endl;
                return cnt;
            }
            else{
                idx2--;
            }
        }
        cnt += idx2+1;
    }
    //cout << n << " " << cnt << endl;
    return cnt;
}

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        pr[0].push_back(n);
    }
    long long K;
    cin >> K;
    sort(pr[0].begin(), pr[0].end());
    for(int i = 1; i<pr[0].size(); i++){
        pr[1].push_back(pr[0][i]);
        pr[0].erase(pr[0].begin()+i);
    }
    val[0].push_back(1);
    val[1].push_back(1);
    init(1, 0, 0);
    init(1, 0, 1);
    sort(val[0].begin(), val[0].end());
    sort(val[1].begin(), val[1].end());
    /*
    for(long long n : val[0]){
        cout << n << " ";
    }
    cout << endl;
    for(long long n : val[1]){
        cout << n << " ";
    }
    cout << endl;
    */
    long long l = 1, r = 1e18, ans = 0;
    while(l <= r){
        long long mid = l+r>>1;
        long long midval = chk(mid);
        if(K == midval){
            ans = mid;
            r = mid - 1;
        }
        else if(midval > K){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << ans << endl;
}