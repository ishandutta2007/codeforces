#include <bits/stdc++.h>

using namespace std;

map<int, int> latest, cnt;
int arr[1505];
int N;

int main(){
    cin >> N;
    int ans = 0;
    for(int i =1 ; i<=N; i++){
        cin >> arr[i];
        int sum = 0;
        for(int j = i; j>0; j--){
            sum += arr[j];
            if(j > latest[sum]){
                latest[sum] = i;
                cnt[sum]++;
            }
            if(cnt[ans] < cnt[sum]){
                ans = sum;
            }
        }
    }
    cout << cnt[ans] << endl;
    int last = 0;
    for(int i = 1; i<=N; i++){
        int sum = 0;
        for(int j = i; j>last; j--){
            sum += arr[j];
            if(sum == ans){
                cout << j << " " << i << endl;
                last = i;
                break;
            }
        }
    }
}