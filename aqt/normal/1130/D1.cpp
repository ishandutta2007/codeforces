#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> arr[5005];
vector<int> way;
int idx[5005];

int main(){
    cin >> N >> M;
    for(int i =1; i<=M; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        way.push_back(N*(arr[a].size())+a);
        int dif = b-a;
        if(b < a){
            dif = N+b-a;
        }
        arr[a].push_back(dif);
    }
    int s = 0;
    for(int i =0; i<N; i++){
        sort(arr[i].begin(), arr[i].end(), greater<int>());
        /*
        if(arr[i].size()){
            way.push_back(N*arr[i].size()+i);
        }
        */
    }
    sort(way.begin(), way.end());
    for(int i =0; i<N; i++){
        long long ans = 0;
        fill(idx, idx+N, 0);
        if(way[s] < i){
            way.push_back(N*arr[way[s]].size()+way[s]);
            s++;
        }
        for(int j=s; j<s+M; j++){
            ans = ans < way[j]+arr[way[j]%N][idx[way[j]%N]] ? way[j]+arr[way[j]%N][idx[way[j]%N]] : ans;
            idx[way[j]%N]++;
        }
        printf("%lld ", ans-i);
    }
}