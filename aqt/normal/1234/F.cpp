#include <bits/stdc++.h>

using namespace std;

string s;
int rht[21][1<<20];
int lftmst[1<<20];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    fill(lftmst, lftmst+(1<<20), -1);
    for(int i = 0; i<s.size(); i++){
        int m = 0;
        for(int j = i; j<s.size(); j++){
            if((m&(1<<(s[j]-'a'))) == 0){
                m |= (1<<(s[j]-'a'));
            }
            else{
                break;
            }
            if(lftmst[m] == -1){
                lftmst[m] = j;
            }
            rht[__builtin_popcount(m)][m] = i;
        }
    }
    rht[0][0] = s.size();
    for(int m = 1; m<1<<20; m++){
        for(int b = 0; b<20; b++){
            if(m&(1<<b) == 0){
                continue;
            }
            for(int k = 0; k<=__builtin_popcount(m); k++){
                rht[k][m] = max(rht[k][m], rht[k][m^(1<<b)]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i<1<<20; i++){
        if(lftmst[i] == -1){
            continue;
        }
        for(int k = 0; k<=20; k++){
            if(rht[k][i^((1<<20)-1)] > lftmst[i]){
                ans = max(ans, k+__builtin_popcount(i));
            }
        }
    }
    cout << ans << endl;
}