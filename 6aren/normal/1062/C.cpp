#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,q,fen[100000+5];
string s;
void update(int p){
    for (int i=p;i<=n;i+=i&(-i)){
        fen[i]+=1;
    }
}
int get(int p){
    int ans=0;
    for (int i=p;i>0;i-=i&(-i)){
        ans+=fen[i];
    }
    return ans;
}
long long luythua(int k){
    if (k==0) return 1;
    long long t=luythua(k/2);
    t=t*t%mod;
    if (k%2){
        t=t*2%mod;
    }
    return t;
}

long long calc(int bit1,int bit){
    long long res=0;
    bit=bit-bit1;
    res+=(luythua(bit1)-1)*(luythua(bit)-1) % mod;
    res=(res+(luythua(bit1)-1)) % mod;
    return res;
}

int main(){
    cin >> n >> q;
    cin >> s;
    for (int i=0;i<n;i++){
        if (s[i]=='1') update(i+1);
    }
    for (int i=1;i<=q;i++){
        int l,r;
        cin >> l >> r;
        int v=r-l+1;
        int u;
        if (l==1) u=get(r);
        else u=get(r)-get(l-1);
        cout << calc(u,v) << endl;
    }
}