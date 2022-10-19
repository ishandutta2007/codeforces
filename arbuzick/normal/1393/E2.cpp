#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int M[2];
struct str{
    int r[2];
    str(int x = 0){
        for(int i = 0; i < 2; ++i)
            r[i] = x;
    }
    str& operator += (str b){
        for(int i = 0; i < 2; ++i)
            r[i] = (r[i]+b.r[i])%M[i];
        return *this;
    }
    friend str operator + (str a, str b){
        return a+=b;
    }
    str& operator -= (str b){
        for(int i = 0; i < 2; ++i)
            r[i] = (r[i]-b.r[i] + M[i])%M[i];
        return *this;
    }
    friend str operator - (str a, str b){
        return a-=b;
    }
    str& operator *= (str b){
        for(int i = 0; i < 2; ++i)
            r[i] = (1LL*r[i]*b.r[i])%M[i];
        return *this;
    }
    friend str operator * (str a, str b){
        return a*=b;
    }
};
bool operator == (str a, str b){
    for(int i = 0; i < 2; ++i)
        if(a.r[i]!=b.r[i])
            return false;
    return true;
}
str st[1000001];
vector<str> pr[100000];
int word;
string a[100000];
str get_str(int word1, int x, int len){
    if(len <= x)
        return pr[word1][len];
    return pr[word1][x]*st[len-x]+pr[word1][len+1]-pr[word1][x+1]*st[len-x];
}
vector<int> b[100000], dp[100000];
bool cmp2(int x, int y){
    int k1 = a[word].size(), k2 = a[word+1].size();
    if(x != k1)
        k1--;
    if(y != k2)
        k2--;
    int l = 0, r = min(k1, k2)+1;
    while(l < r-1){
        int m = (l+r)/2;
        if(get_str(word, x, m) == get_str(word+1, y, m))
            l = m;
        else
            r = m;
    }
    if(l == min(k1, k2))
        return k1 <= k2;
    int l1 = l, l2 = l;
    if(l1 >= x)
        l1++;
    if(l2 >= y)
        l2++;
    return a[word][l1] <= a[word+1][l2];
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    M[0] = 1000000007;
    M[1] = 1000000009;
    int base = 200;
    st[0] = 1;
    for(int i = 0; i < 1000000; ++i)
        st[i+1] = st[i]*base;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i){
        pr[i].resize(a[i].size()+1);
        for(int j = 0; j < a[i].size(); ++j)
            pr[i][j+1] = pr[i][j]*base+a[i][j];
    }
    for(int i = 0; i < n; ++i){
        vector<int> nxt(a[i].size(), a[i].size()*1LL-1);
        for(int j = a[i].size()*1LL-2; j >= 0; --j){
            if(a[i][j] == a[i][j+1])
                nxt[j] = nxt[j+1];
            else
                nxt[j] = j+1;
        }
        int l = 0, r = a[i].size();
        vector<int> a1(a[i].size());
        r--;
        for(int j = 0; j < a[i].size(); ++j){
            if(a[i][j] >= a[i][nxt[j]])
                a1[l] = j, l++;
            else
                a1[r] = j, r--;
        }
        for(int j = 0; j < a[i].size(); ++j){
            b[i].pb(a1[j]);
            if(b[i].back() == a[i].size()*1LL-1)
                b[i].pb(a[i].size());
        }
    }
    int mod = 1000000007;
    dp[n-1].resize(a[n-1].size()+1);
    for(int i = 0; i < a[n-1].size()+1; ++i)
        dp[n-1][i] = 1;
    for(int i = n-2; i >= 0; --i){
        dp[i].resize(a[i].size()+1);
        word = i;
        int s = 0;
        int j1 = a[i+1].size()+1;
        for(int j = a[i].size(); j >= 0; --j){
            while(j1 > 0 && cmp2(b[i][j], b[i+1][j1-1]))
                j1--, s += dp[i+1][j1], s %= mod;
            dp[i][j] = s;
            dp[i][j] += mod;
            dp[i][j] %= mod;
        }
    }
    int ans = 0;
    for(int i = 0; i < dp[0].size(); ++i)
        ans += dp[0][i], ans %= mod;
    cout << ans;
    return 0;
}