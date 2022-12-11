#include <bits/stdc++.h>

using namespace std;

int N, Q;
int lft[300005], rht[300005];
int arr[300005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> Q;
    while(Q--){
        cin >> N;
        for(int i = 1; i<=N; i++){
            cin >> arr[i];
            lft[i] = N+1, rht[i] = 0;
        }
        for(int i = 1; i<=N; i++){
            lft[arr[i]] = min(lft[arr[i]], i);
            rht[arr[i]] = i;
        }
        int cnt = 0;
        int tot = 0, lst = 0;
        int ans = 0;
        for(int i = 1; i<=N; i++){
            if(rht[i]){
                tot++;
                if(lft[i] > lst){
                    cnt++;
                    lst = rht[i];
                }
                else{
                    cnt = 1;
                    lst = rht[i];
                }
                ans = max(ans, cnt);
            }
        }
        cout << tot-ans << "\n";
    }
}

/*
4
1 4 3 2
*/