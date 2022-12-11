#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, lst = 0;
    int ans = 1, crnt = 1;
    cin >> N;
    for(int i= 1; i<=N; i++){
        int n;
        cin >> n;
        if(lst*2 < n){
            crnt = 1;
        }
        else{
            crnt++;
        }
        ans = max(crnt, ans);
        lst = n;
    }
    cout << ans << endl;
}