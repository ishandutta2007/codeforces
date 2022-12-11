#include <bits/stdc++.h>

using namespace std;

int Q, M = 100005;
int f[100005];
int arr[3];
int sub[10];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 1; i<=M; i++){
        for(int j = 1; j<=sqrt(i); j++){
            if(i%j == 0){
                f[i]++;
                f[i] += (i/j != j);
            }
        }
    }
    cin >> Q;
    while(Q--){
        cin >> arr[0] >> arr[1] >> arr[2];
        sub[7] = f[__gcd(arr[0], __gcd(arr[1], arr[2]))];
        sub[6] = f[__gcd(arr[1], arr[2])]-sub[7];
        sub[5] = f[__gcd(arr[2], arr[0])]-sub[7];
        sub[3] = f[__gcd(arr[0], arr[1])]-sub[7];
        sub[4] = f[arr[2]]-sub[6]-sub[5]-sub[7];
        sub[2] = f[arr[1]]-sub[6]-sub[3]-sub[7];
        sub[1] = f[arr[0]]-sub[5]-sub[3]-sub[7];
        /*
        for(int i = 1; i<8; i++){
            cout << sub[i] << " ";
        }
        */
        long long ans = 0;
        for(int m1 = 1; m1<7; m1++){
            for(int m2 = m1; m2<8; m2++){
                for(int m3 = m2; m3<8; m3++){
                    if((m1|m2|m3) == 7){
                        //cout << Q << " " << sub[m1] << " " << sub[m2] << " " << sub[m3] << "\n";
                        if(m1 == m2){
                            ans += (sub[m1]*(sub[m2]+1))/2*sub[m3];
                        }
                        else if(m2 == m3){
                            ans += sub[m1]*(sub[m3])*(sub[m2]+1)/2;
                        }
                        else if(m1 == m3){
                            ans += sub[m1]*(sub[m3]+1)/2 * sub[m2];
                        }
                        else{
                            ans += sub[m1]*sub[m2]*sub[m3];
                        }
                    }
                }
            }
        }
        ans += sub[7]*(sub[7]+1)*(sub[7]+2)/6;
        ans -= (sub[1]*(sub[1]+1))/2*(sub[7]+sub[6]);
        ans -= (sub[2]*(sub[2]+1))/2*(sub[7]+sub[5]);
        ans -= (sub[4]*(sub[4]+1))/2*(sub[7]+sub[3]);
        cout << ans << "\n";
    }
}