#include <bits/stdc++.h>

using namespace std;

int N;
int trie[2][8000000];

long long solve(vector<int> v, int b){
    if(b < 0 || v.empty()){
        return 0;
    }
    vector<int> z, o;
    for(int n : v){
        if((1<<b)&n){
            o.push_back(n);
        }
        else{
            z.push_back(n);
        }
    }
    trie[0][0] = trie[1][0] = 0;
    int idx = 0;
    long long ret = INT_MAX;
    if(o.empty() || z.empty()){
        ret = 0;
    }
    else{
        for(int n : o){
            int c = 0;
            for(int k = b; k>=0; k--){
                bool t = (1<<k)&n;
                if(!trie[t][c]){
                    trie[t][c] = ++idx;
                    trie[0][idx] = trie[1][idx] = 0;
                }
                c = trie[t][c];
            }
        }
        for(int n : z){
            int c = 0, tot = 0;
            for(int k = b; k>=0; k--){
                bool t = (1<<k)&n;
                if(!trie[t][c]){
                    tot += (1<<k);
                    c = trie[!t][c];
                }
                else{
                    c = trie[t][c];
                }
            }
            ret = min(ret, 1LL*tot);
        }
    }
    return ret + solve(o, b-1) + solve(z, b-1);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    vector<int> v;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        v.push_back(n);
    }
    cout << solve(v, 30) << endl;
}