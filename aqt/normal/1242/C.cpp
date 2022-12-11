#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> arr[20];
map<long long, int> mp;
long long sum[20];
bool pos[1<<20], dp[1<<20];
vector<pair<pair<int, int>, int>> vec[1<<20];
int par[1<<20];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    long long tot = 0;
    for(int i = 0; i<N; i++){
        int k;
        cin >> k;
        while(k--){
            int n;
            cin >> n;
            mp[n] = i;
            tot += n;
            sum[i] += n;
            arr[i].push_back(n);
        }
    }
    if(tot%N){
        cout << "No" << endl;
        return 0;
    }
    tot /= N;
    for(int i = 0; i<N; i++){
        sum[i] -= tot;
    }
    for(int i = 0; i<N; i++){
        for(int e : arr[i]){
            int mask = 0;
            vector<pair<pair<int, int>, int>> k;
            int crnt = i, lst = e;
            do{
                if(!mp.count(-(1LL*sum[crnt]-lst))){
                    break;
                }
                int l = mp[-(1LL*sum[crnt]-lst)];
                if(mask&(1<<l)){
                    break;
                }
                mask ^= (1<<l);
                lst = -(sum[crnt]-lst);
                k.push_back({{l, lst}, crnt+1});
                crnt = l;
            }
            while(crnt != i);
            if((mask&(1<<i)) && e == lst){
                pos[mask] = 1;
                vec[mask] = k;
            }
        }
    }
    dp[0] = 1;
    for(int m = 1; m<1<<N; m++){
        for(int k = m; k; k = ((k-1)&m)){
            if(pos[k] && dp[m^k]){
                dp[m] = 1;
                par[m] = k;
                break;
            }
        }
    }
    if(dp[(1<<N)-1]){
        int c = (1<<N)-1;
        vector<pair<pair<int, int>, int>> out;
        while(c){
            for(auto p : vec[par[c]]){
                out.push_back(p);
            }
            c ^= par[c];
        }
        sort(out.begin(), out.end());
        cout << "yes" << endl;
        for(auto p : out){
            cout << p.first.second << " " << p.second << endl;
        }
    }
    else{
        cout << "no" << endl;
    }
}