#include <bits/stdc++.h>

using namespace std;

int N, Q;
int MAXV = 500000;
vector<int> fac[500005];
int arr[200005];
int typ[500005];
long long cnt[500005];
bool tkn[200005];

int main(){
    for(int n = 2; n<=MAXV; n++){
        if(typ[n] != -1){
            for(int i = n; i<=MAXV; i+=n){
                fac[i].push_back(n);
                if(typ[i] != -1 && fac[n].size() == 1){
                    typ[i]++;
                }
            }
            for(long long i = 1LL*n*n; i<=MAXV; i+=1LL*n*n){
                typ[i] = -1;
            }
        }
    }
    cin >> N >> Q;
    long long tot = 0, ans = 0;
    for(int i= 1; i<=N; i++){
        cin >> arr[i];
        /*
        cout << "NUM: " << arr[i] << "\n";
        cout << "SZ: " << fac[arr[i]].size() << "\n";
        for(int f : fac[arr[i]]){
            cout << f << "\n";
        }
        */
    }
    while(Q--){
        int n;
        cin >> n;
        if(tkn[n]){
            tkn[n] = 0;
            tot--;
            n = arr[n];
            for(int f : fac[n]){
                if(typ[f] == -1){
                    continue;
                }
                assert(cnt[f] > 0);
                cnt[f]--;
                if(typ[f]%2){
                    ans -= cnt[f];
                }
                else{
                    ans += cnt[f];
                }
            }
        }
        else{
            tkn[n] = 1;
            tot++;
            n = arr[n];
            for(int f : fac[n]){
                if(typ[f] == -1){
                    continue;
                }
                if(typ[f]%2){
                    ans += cnt[f];
                }
                else{
                    ans -= cnt[f];
                }
                assert(cnt[f] >= 0);
                cnt[f]++;
            }
        }
//        assert(tot*(tot-1)/2 >= ans);
//        cout << tot << " " << ans << endl;
        cout << tot*(tot-1)/2 - ans << "\n";
    }
}