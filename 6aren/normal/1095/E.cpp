#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1000000+5;
const int MOD=998244353;

int n, cnt[N];
string s;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    if (n%2) return cout << 0, 0;
    for (int i=0; i<s.size(); i++){
        if (s[i]=='(') cnt[i+1]=cnt[i]+1;
        else cnt[i+1]=cnt[i]-1;
        if (cnt[i+1]<-2) return cout << 0, 0;
    }
    if (cnt[n]==2){
        int res=0;
        for (int i=1; i<=n ;i++){
            if (cnt[i]<0) return cout << 0, 0;
        }
        for (int i=n; i>=1; i--){
            if (cnt[i]<=1) break;
            if (s[i-1]=='(') res++;
        }
        return cout << res, 0;
    } else if (cnt[n]==-2){
        int res=0;
        for (int i=1; i<=n; i++){
            if (s[i-1]==')'){
                res++;
                if (cnt[i]<0) break;
            }
        }
        return cout << res, 0;
    } else return cout << 0, 0;
    return 0;
}