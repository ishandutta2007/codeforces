#include <bits/stdc++.h>

using namespace std;

int N, X;
int arr[1000005];
int lft[1000005], rht[1000005];
int mapos[1000005], mipos[1000005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> X;
    for(int i =1 ; i<=N; i++){
        cin >> arr[i];
        if(!lft[arr[i]]){
            lft[arr[i]] = i;
        }
        rht[arr[i]] = i;
    }
    for(int i =1; i<=X; i++){
        mapos[i] = max(mapos[i-1], rht[i]);
    }
    mipos[X+1] = INT_MAX;
    for(int i = X; i>0; i--){
        if(lft[i] == 0){
            mipos[i] = mipos[i+1];
            continue;
        }
        mipos[i] = min(mipos[i+1], lft[i]);
    }
    int r = X, lst = N+1;
    while(r>0){
        if(lft[r] == 0){
            r--;
            continue;
        }
        if(rht[r] > lst){
            r++;
            break;
        }
        lst = lft[r];
        r--;
    }
    r = max(1, r);
    int l = 1;
    lst = 0;
    while(l <= X){
        if(rht[l] == 0){
            l++;
            continue;
        }
        if(lft[l] < lst){
            l--;
            break;
        }
        lst = rht[l];
        l++;
    }
    l = min(X, l);
    int llim = l, rlim = r;
    long long ans = 0;
    for(r = rlim-1, l = 0; r<=X; r++){
        while(l <= llim && l < r && mapos[l] <= mipos[r+1]){
            l++;
        }
        ans += l;
    }
    cout << ans << endl;
}