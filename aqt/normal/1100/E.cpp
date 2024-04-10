#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> graph[100005];
int s[100005], t[100005], w[100005];
queue<int> ll;
int dgr[100005];
vector<int> lis;
vector<int> tem;
bool vis[100005], done[100005];

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 1; i<=M; i++){
        scanf("%d %d %d", &s[i], &t[i], &w[i]);
        graph[s[i]].push_back(i);
        graph[t[i]].push_back(i);
    }
    int l = 0, r = 1000000000, ans = 0;
    while(l <= r){
        int mid = (l+r)/2;
        bool b = 1;
        int cnt = N;
        for(int i =1; i<=N; i++){
            dgr[i] = 0;
            vis[i] = 0;
            for(int id : graph[i]){
                done[id] = 0;
                if(w[id] > mid && t[id] == i){
                    dgr[i]++;
                }
            }
        }
        for(int i = 1; i<=N; i++){
            if(!dgr[i]){
                ll.push(i);
                vis[i] = 1;
            }
        }
        while(ll.size()){
            int n = ll.front();
            ll.pop();
            cnt--;
            for(int id : graph[n]){
                if(!done[id]){
                    if(w[id] > mid){
                        if(s[id] == n){
                            dgr[t[id]]--;
                            if(dgr[t[id]] == 0){
                                ll.push(t[id]);
                                vis[t[id]] = 1;
                            }
                        }
                    }
                    else{
                        if(s[id] != n){
                            tem.push_back(id);
                        }
                    }
                    done[id] = 1;
                }
            }
        }
        if(cnt){
            l = mid + 1;
        }
        else{
            ans = mid;
            r = mid - 1;
            lis.clear();
            for(int e : tem){
                lis.push_back(e);
            }
        }
        tem.clear();
    }
    sort(lis.begin(), lis.end());
    printf("%d %d\n", ans, lis.size());
    for(int e : lis){
        printf("%d ", e);
    }
}