#include <bits/stdc++.h>

using namespace std;

int N;
int fre[100005], amt[100005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int D = 0, ans = 0;
    bool lst = 1;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        if(fre[n] == 0){
            D++;
            amt[0]++;
        }
        amt[fre[n]]--;
        fre[n]++;
        amt[fre[n]]++;
        if(amt[fre[n]] == D-1 && amt[fre[n]+1] == 1 || amt[fre[n]] == 1 && amt[fre[n]-1] == D-1){
            ans = i;
        }
        else if(lst){
            ans = i;
        }
        else if(amt[1] == 1 && amt[fre[n]] == D-1){
            ans = i;
        }
        if(amt[fre[n]] == D){
            lst = 1;
        }
        else{
            lst = 0;
        }
    }
    cout << ans << endl;
}