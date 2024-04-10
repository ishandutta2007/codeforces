#include <bits/stdc++.h>

using namespace std;

int N;
long long arr[200005];
long long lft[200005], rht[200005];

int main(){
    cin >> N;
    long long idx = 1, lst = 0;
    for(int i = 2; i<=N; i+=2){
        cin >> arr[i];
        while(idx*idx <= 1e13){
            long long l = lst+1, r = idx-1, ans = -1;
            while(l <= r){
                long long mid = l+r>>1;
                if(idx*idx-mid*mid == arr[i]){
                    ans = mid;
                    break;
                }
                else if(idx*idx-mid*mid > arr[i]){
                    l = mid + 1;
                }
                else{
                    r = mid -1;
                }
            }
            if(ans != -1){
                lst = rht[i] = idx;
                lft[i] = ans;
                idx++;
                break;
            }
            idx++;
        }
    }
    if(idx*idx > 1e13){
        cout << "No" << endl;
        exit(0);
    }
    cout << "Yes" << "\n";
    for(int i = 1; i<=N; i++){
        if(i&1){
            rht[i] = lft[i+1];
            lft[i] = rht[i-1];
        }
        cout << rht[i]*rht[i] - lft[i]*lft[i] << " ";
    }
}