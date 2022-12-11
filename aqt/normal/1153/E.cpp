#include <bits/stdc++.h>

using namespace std;

int N, k;
int ans[2][2];

int main(){
    cin >> N;
    int cnt = 0;
    for(int i = 1; i<=N && cnt < 2; i++){
        cout << "? " << i << " " << 1 << " " << i << " " << N << endl;
        cout.flush();
        cin >> k;
        if(k%2){
            ans[cnt][0] = i;
            int l = 1, r = N;
            while(l <= r){
                int m = (l+r)/2;
                cout << "? " << i << " " << l << " " << i << " " << m << endl;
                cout.flush();
                cin >> k;
                if(k%2){
                    ans[cnt][1] = m;
                    r = m - 1;
                }
                else{
                    l = m + 1;
                }
            }
            cnt++;
        }
    }
    for(int i = 1; i<=N && cnt < 2; i++){
        if(i == N){
            k = 1;
        }
        else{
            cout << "? " << 1 << " " << i << " " << N << " " << i << endl;
            cout.flush();
            cin >> k;
        }
        if(k%2){
            ans[cnt][1] = i;
            int l = 1, r = N;
            while(l <= r){
                int m = (l+r)/2;
                cout << "? " << l << " " << i << " " << m << " " << i << endl;
                cout.flush();
                cin >> k;
                if(k%2){
                    ans[cnt][0] = m;
                    r = m - 1;
                }
                else{
                    l = m + 1;
                }
            }
            cnt++;
        }
    }
    cout << "! " << ans[0][0] << " " << ans[0][1] << " " << ans[1][0] << " " << ans[1][1] << endl;
}