#include <bits/stdc++.h>

using namespace std;

int N, M = 300000;
int arr[300005];
int cnt[300005];
bool exist[300005];
int seive[300005];
vector<int> p[300005];
int dist[300005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 2; i<=M; i++){
        if(seive[i] == 0){
            for(int j = i; j<=M; j+=i){
                if(seive[j] != -1){
                    seive[j]++;
                    p[j].push_back(i);
                }
            }
            for(long long j = 1LL*i*i; j<=M; j+=1LL*i*i){
                seive[j] = -1;
            }
        }
    }
    for(int i = 1; i<=M; i++){
        if(seive[i] == -1){
            seive[i]++;
        }
        else if(seive[i]%2 == 0){
            seive[i] = 1;
        }
        else{
            seive[i] = -1;
        }
    }
    for(int i = 1; i<=M; i++){
        if(seive[i]){
            vector<int> v;
            for(int m = 0; m<(1<<p[i].size()); m++){
                int f = 1;
                for(int k = 0; k<p[i].size(); k++){
                    if((m>>k)&1){
                        f *= p[i][k];
                    }
                }
                v.push_back(f);
            }
            swap(v, p[i]);
        }
    }
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        for(int j = 2; j<=sqrt(arr[i]); j++){
            while(arr[i]%(j*j) == 0){
                arr[i]/=j;
            }
        }
        exist[arr[i]] = 1;
        for(int f : p[arr[i]]){
            cnt[f]++;
        }
    }
    fill(dist+1, dist+1+M, 10);
    for(int n = M; n; n--){
        if(exist[n]){
            dist[n] = 1;
        }
        if(dist[n] < 10){
            for(int m : p[n]){
                int sum = 0;
                for(int f : p[n]){
                    if((f%m) == 0){
                        sum += (seive[f] == seive[m] ? 1 : -1)*cnt[f];
                    }
                }
                if(sum){
                    dist[m] = min(dist[m], dist[n] + 1);
                }
            }
        }
    }
    if(dist[1] == 10){
        dist[1] = -1;
    }
    cout << dist[1] << endl;
}