#include <bits/stdc++.h>
using namespace std;
int n, k;
long long mid[5*100005+1],tot[5*100005+1];
int main(){
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    int check=1;
    for (int i=0;i<=5*100005;i++){
        mid[i]=0;
        tot[i]=0;
    }
    for (int i=0; i<s.size(); i++){
        if (check==1 && s[i]!=t[i]) {
            check=0;
            tot[i]=2;
            continue;
        }
        if (!check){
            if (s[i]==t[i]){
                mid[i]=mid[i-1]*2+1;
                tot[i]=mid[i]+2;
                if (mid[i]>1e9) {
                    mid[i]=1e9+1;
                    tot[i]=1e9+1;
                }
                continue;
            }
            if (s[i]=='a' && t[i]=='b'){
                mid[i]=mid[i-1]*2+2;
                tot[i]=mid[i]+2;
                if (mid[i]>1e9) {
                    mid[i]=1e9+1;
                    tot[i]=1e9+1;
                }
                continue;
            }
            if (s[i]=='b' && t[i]=='a'){
                mid[i]=mid[i-1]*2;
                tot[i]=mid[i]+2;
                if (mid[i]>1e9) {
                    mid[i]=1e9+1;
                    tot[i]=1e9+1;
                }
                continue;
            }
        }
        tot[i]=1;
    }
    long long res=0;
    for (int i=0; i<s.size(); i++){
        //cout << tot[i] << endl;
        if (tot[i]>=k){
            res+=1LL*(s.size()-i)*k;
            break;
        }
        res+=tot[i];
    }
    cout << res;
}