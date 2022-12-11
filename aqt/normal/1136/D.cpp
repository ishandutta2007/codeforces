#include <bits/stdc++.h>

using namespace std;

int N, M;
int nidx[300005];
vector<int> graph[300005];
bool canpass[300005];
int cnt[300005];

int main(){
    cin >> N >> M;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        nidx[n] = i;
    }
    for(int i = 1; i<=M; i++){
        int a, b;
        cin >> a >> b;
        a = nidx[a];
        b = nidx[b];
        graph[b].push_back(a);
        if(b == N){
            canpass[a] = 1;
        }
    }
    int passed = 0;
    for(int i = N; i>0; i--){
        if(canpass[i]){
            if(cnt[i] != N-i-passed){
                for(int e : graph[i]){
                    cnt[e]++;
                }
            }
            else{
                passed++;
            }
        }
        else{
            for(int e : graph[i]){
                cnt[e]++;
            }
        }
    }
    cout << passed << endl;
}