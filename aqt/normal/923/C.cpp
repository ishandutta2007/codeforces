#include <bits/stdc++.h>

using namespace std;

int trie[9000000][2];
int idx = 0;
int cnt[9000000];
int N;
int arr[9000000];

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        int crnt = 0;
        for(int k = 30; k>=0; k--){
            if((1<<k)&n){
                if(!trie[crnt][1]){
                    trie[crnt][1] = ++idx;
                }
                crnt = trie[crnt][1];
            }
            else{
                if(!trie[crnt][0]){
                    trie[crnt][0] = ++idx;
                }
                crnt = trie[crnt][0];
            }
            cnt[crnt]++;
        }
    }
    for(int i = 1; i<=N; i++){
        int n = arr[i];
        int crnt = 0, ans = 0;
        for(int k = 30; k>=0; k--){
            if((1<<k)&n){
                if(cnt[trie[crnt][1]]){
                    crnt = trie[crnt][1];
                }
                else{
                    crnt = trie[crnt][0];
                    ans += (1<<k);
                }
            }
            else{
                if(cnt[trie[crnt][0]]){
                    crnt = trie[crnt][0];
                }
                else{
                    crnt = trie[crnt][1];
                    ans += (1<<k);
                }
            }
            cnt[crnt]--;
        }
        printf("%d ", ans);
    }
}