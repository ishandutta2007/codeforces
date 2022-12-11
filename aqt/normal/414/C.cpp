#include <bits/stdc++.h>

using namespace std;

int N, Q;
int arr[(1<<20)+5], BIT[(1<<20)+5];
vector<int> cmp;
long long inv[25][2];

int sum(int p){
    int s = 0;
    for(int i = p-1; i>0; i-=i&-i){
        s += BIT[i];
    }
    return s;
}

void upd(int p, int v){
    for(int i = p; i<=(1<<N); i+=i&-i){
        BIT[i] += v;
    }
}

void inver(int b, int t){
    int len = (1<<b);
    for(int i = 0; i<(1<<N); i+=len){
        for(int j = i+(len>>1); j<i+len; j++){
//            cout << arr[j] << " " << b << " " << t << endl;
            upd(arr[j], 1);
        }
        for(int j = i; j<i+(len>>1); j++){
//            cout << arr[j] << " " << b << " " << t << " " << inv[b][t] << endl;
            inv[b][t] += sum(arr[j]);
//            cout << sum(arr[j]) << endl;
//            cout << arr[j] << " " << b << " " << t << " " << inv[b][t] << endl;
        }
        for(int j = i+(len>>1); j<i+len; j++){
            upd(arr[j], -1);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i<(1<<N); i++){
        cin >> arr[i];
        cmp.push_back(arr[i]);
    }
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    for(int i = 0; i<(1<<N); i++){
        arr[i] = lower_bound(cmp.begin(), cmp.end(), arr[i])-cmp.begin()+1;
    }
    for(int b = 1; b<=N; b++){
        inver(b, 0);
    }
    reverse(arr, arr+(1<<N));
    for(int b = 1; b<=N; b++){
        inver(b, 1);
    }
    int mask = 0;
    cin >> Q;
    while(Q--){
        int b;
        cin >> b;
        mask ^= (1<<(b+1))-1;
        long long ans = 0;
        for(int i = 1; i<=N; i++){
            if((1<<i)&mask){
                ans += inv[i][1];
            }
            else{
                ans += inv[i][0];
            }
        }
        printf("%lld\n", ans);
    }
}