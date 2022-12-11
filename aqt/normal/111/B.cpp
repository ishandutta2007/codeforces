#include <bits/stdc++.h>

using namespace std;

int N;
int lst[100005];
vector<int> fact[100005];

int main(){
    for(int i = 1; i<=100000; i++){
        for(int j = i; j<=100000; j+=i){
            fact[j].push_back(i);
        }
    }
    cin >> N;
    for(int i =1; i<=N; i++){
        int n, k;
        cin >> n >> k;
        int cnt = 0;
        for(int f : fact[n]){
            if(i-lst[f] > k){
                cnt++;
            }
            lst[f] = i;
        }
        printf("%d\n", cnt);
    }
}