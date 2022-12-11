#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
    cin >> N;
    long long lstp = -1e18, lstb = -1e18, lstr = -1e18, maxib = 0, maxir = 0;
    long long ans = 0;
    for(int i =1; i<=N; i++){
        long long p;
        char typ;
        cin >> p >> typ;
        if(typ == 'P'){
            if(lstb != -1e18){
                maxib = max(maxib, p-lstb);
                ans += p-lstb;
            }
            if(lstr != -1e18){
                maxir = max(maxir, p-lstr);
                ans += p-lstr;
            }
            if(lstp != -1e18){
                ans += min(p-lstp-maxib-maxir, 0LL);
            }
            lstr = lstb = lstp = p;
            maxib = maxir = 0;
        }
        else if(typ == 'B'){
            if(lstb != -1e18){
                ans += p - lstb;
                maxib = max(maxib, p - lstb);
            }
            lstb = p;
        }
        else{
            if(lstr != -1e18){
                ans += p - lstr;
                maxir = max(maxir, p - lstr);
            }
            lstr = p;
        }
    }
    cout << ans << endl;
}