#include <bits/stdc++.h>

using namespace std;

struct obj{
    long long hp, dmg;
    bool operator < (obj o) const{
        return hp-dmg > o.hp - o.dmg;
    }
};

int N;
long long A, B;
obj arr[200005];

int main(){
    cin >> N >> A >> B;
    for(int i= 1; i<=N; i++){
        cin >> arr[i].hp >> arr[i].dmg;
    }
    sort(arr+1, arr+1+N);
    long long tot = 0;
    for(int i = 1; i<B; i++){
        tot += max(arr[i].hp, arr[i].dmg);
    }
    for(int i = B; i<=N; i++){
        tot += arr[i].dmg;
    }
    if(!B){
        cout << tot << endl;
        return 0;
    }
    long long ans = tot;
    for(int i= 1; i<B; i++){
        long long temp = tot;
        temp -= max(arr[i].hp, arr[i].dmg);
        temp += max(arr[i].hp*(1LL<<A), arr[i].dmg);
        temp -= arr[B].dmg;
        temp += max(arr[B].hp, arr[B].dmg);
        ans = max(ans, temp);
    }
    for(int i= B; i<=N; i++){
        long long temp = tot;
        temp -= arr[i].dmg;
        temp += max(arr[i].hp*(1LL<<A), arr[i].dmg);
        ans = max(ans, temp);
    }
    cout << ans << endl;
}