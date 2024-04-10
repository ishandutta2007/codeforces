#include <bits/stdc++.h>

using namespace std;

int N, Q;
int basis[20];
int ans[100005];
int arr[100005];
pair<int, int> qu[100005];
int val[100005];
long long pows[100005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    pows[0] = 1;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        pows[i] = pows[i-1] * 2;
        pows[i] %= 1000000007;
    }
    for(int q = 1; q<=Q; q++){
        cin >> qu[q].first;
        qu[q].second = q;
        cin >> val[q];
    }
    sort(qu+1, qu+1+Q);
    int sz = 0;
    for(int i = 1, idx = 1; i<=N && idx <= Q; i++){
        for(int b = 0; b<20; b++){
            if((1<<b)&arr[i]){
                if(!basis[b]){
                    basis[b] = arr[i];
                    sz++;
                }
                arr[i] ^= basis[b];
            }
        }
        while(idx <= Q && qu[idx].first == i){
            int v = val[qu[idx].second];
            for(int b = 0; b<20; b++){
                if((1<<b)&v){
                    v ^= basis[b];
                }
            }
            if(!v){
                ans[qu[idx].second] = pows[i-sz];
            }
            idx++;
        }
    }
    for(int q = 1; q<=Q; q++){
        cout << ans[q] << "\n";
    }
}