#include <bits/stdc++.h>

using namespace std;

int N;
int arr[300005];
char clr[300005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        cin >> clr[i];
    }
    int st = 1, ed = N;
    long long ans = 0;
    int lstB = 0, lstR = 0, lstG = 0;
    for(; st<=N; st++){
        if(clr[st] == 'G'){
            if(lstB){
                ans += arr[st]-lstB;
            }
            if(lstR){
                ans += arr[st]-lstR;
            }
            lstB = lstR = lstG = arr[st];
            break;
        }
        else if(clr[st] == 'R'){
            if(lstR){
                ans += arr[st]-lstR;
            }
            lstR = arr[st];
        }
        else{
            if(lstB){
                ans += arr[st]-lstB;
            }
            lstB = arr[st];
        }
    }
    int tlstB = 0, tlstR = 0;
    for(; ed>=st; ed--){
        if(clr[ed] == 'G'){
            if(tlstB){
                ans += tlstB - arr[ed];
            }
            if(tlstR){
                ans += tlstR - arr[ed];
            }
            break;
        }
        else if(clr[ed] == 'R'){
            if(tlstR){
                ans += tlstR - arr[ed];
            }
            tlstR = arr[ed];
        }
        else{
            if(tlstB){
                ans += tlstB - arr[ed];
            }
            tlstB = arr[ed];
        }
    }
    int maxiR = 0, maxiB = 0;
    for(int i = st+1; i<=ed; i++){
        if(clr[i] == 'G'){
            maxiR = max(maxiR, arr[i]-lstR);
            maxiB = max(maxiB, arr[i]-lstB);
            ans += arr[i]-lstR;
            ans += arr[i]-lstB;
            if(maxiR + maxiB > arr[i] - lstG){
                ans -= maxiR;
                ans -= maxiB;
                ans += arr[i] - lstG;
            }
            maxiR = maxiB = 0;
            lstR = lstB = lstG = arr[i];
        }
        else if(clr[i] == 'R'){
            maxiR = max(maxiR, arr[i]-lstR);
            ans += arr[i]-lstR;
            lstR = arr[i];
        }
        else{
            maxiB = max(maxiB, arr[i]-lstB);
            ans += arr[i]-lstB;
            lstB = arr[i];
        }
    }
    cout << ans << endl;
}