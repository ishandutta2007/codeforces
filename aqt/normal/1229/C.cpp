#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
vector<int> lst[100005];
long long ans = 0;
long long in[100005], out[100005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 1; i<=M; i++){
        int a, b;
        cin >> a >> b;
        if(a > b){
            swap(a, b);
        }
        //a < b
        lst[a].push_back(b);
        in[a]++;
        out[b]++;
    }
    for(int i = 1; i<=N; i++){
        ans += in[i]*out[i];
    }
    cout << ans << "\n";
    cin >> Q;
    while(Q--){
        int n;
        cin >> n;
        ans -= in[n]*out[n];
        while(lst[n].size()){
            int e = lst[n].back();
            lst[n].pop_back();
            in[n]--;
            out[n]++;
            ans -= out[e]*in[e];
            out[e]--;
            in[e]++;
            ans += out[e]*in[e];
            lst[e].push_back(n);
        }
        cout << ans << "\n";
    }
}