#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n, b;
    cin >> n >> b;
    long long fact = 1, crnt = b, factor = 1, expo = 1, s = sqrt(b);
    long long ans = n;
    for(long long i = 2; i<=s; i++){
        if(crnt%i == 0){
            long long tot = 0;
            long long temp = 1;
            int tempexpo = 0;
            while(crnt%i == 0){
                crnt/=i;
                temp *= i;
                tempexpo++;
            }
            fact = i;
            factor = temp;
            expo = tempexpo;
            long long tempcrnt = n;
            int cnt = 0;
            while(tempcrnt){
                cnt++;
                tempcrnt/=fact;
            }
            cnt--;
            for(int i = 1; i<=cnt; i++){
                tot += n/((long long)pow(fact, i));
            }
            ans = min(tot/expo, ans);
        }
    }
    if(crnt > 1){
        long long tot = 0;
        fact = crnt;
        factor = crnt;
        expo = 1;
        long long tempcrnt = n;
        int cnt = 0;
        while(tempcrnt){
            cnt++;
            tempcrnt/=fact;
        }
        cnt--;
        for(int i = 1; i<=cnt; i++){
            tot += n/((long long)pow(fact, i));
        }
        ans = min(tot/expo, ans);
    }
    cout << ans << endl;
}