#include <bits/stdc++.h>
#define int long long
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
bool cmp(int x, int y){
    int k1 = a[word].size(), k2 = a[word].size();
    if(x != k1)
        k1--;
    if(y != k2)
        k2--;
    int l = 0, r = a[word].size();
    while(l < r-1){
        int m = (l+r)/2;
        if(get_str(word, x, m) == get_str(word, y, m))
            l = m;
        else
            r = m;
    }
    if(l == a[word].size()-1)
        return k1 < k2;
    int l1 = l, l2 = l;
    if(l1 >= x)
        l1++;
    if(l2 >= y)
        l2++;
    return a[word][l1] < a[word][l2];
}
vector<int> b[100000], dp[100000], pr1[100000];
//vector<pair<string, int>> b2[1000];
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
/*bool cmp3(pair<string, int> a, pair<string, int> b1){
    for(int i = 0; i < min(a.first.size(), b1.first.size()); ++i)
        if(a.first[i] != b1.first[i])
            return a.first[i] < b1.first[i];
    return a.first.size() < b1.first.size();
}*/
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
        b[i].resize(a[i].size()+1);
        for(int j = 0; j < a[i].size()+1; ++j)
            b[i][j] = j;
        word = i;
        stable_sort(b[i].begin(), b[i].end(), cmp);
        /*b2[i].resize(a[i].size()+1);
        for(int j = 0; j < a[i].size(); ++j)
            for(int j2 = 0; j2 <= a[i].size(); ++j2)
                if(j2 != j)
                    b2[i][j2].first += a[i][j], b2[i][j].second = j;
        for(int j = 0; j < a[i].size(); ++j)
            if(cmp3(b2[i][b[i][j+1]], b2[i][b[i][j]])){
                cout << cmp(b[i][j+1], b[i][j]) << '\n';
                cout << i << ' ' << b[i][j+1] <<  ' ' << b[i][j] << '\n';
                return 1;
            }*/
    }
    int mod = 1000000007;
    dp[n-1].resize(a[n-1].size()+1);
    pr1[n-1].resize(a[n-1].size()+2);
    for(int i = 0; i < a[n-1].size()+1; ++i)
        pr1[n-1][i+1] = pr1[n-1][i]+1, dp[n-1][i] = 1;
    for(int i = n-2; i >= 0; --i){
        dp[i].resize(a[i].size()+1);
        word = i;
        int j1 = a[i+1].size()+1;
        for(int j = a[i].size(); j >= 0; --j){
            while(j1 > 0 && cmp2(b[i][j], b[i+1][j1-1]))
                j1--;
            dp[i][j] = pr1[i+1][a[i+1].size()+1]-pr1[i+1][j1];
            dp[i][j] += mod;
            dp[i][j] %= mod;
        }
        pr1[i].resize(a[i].size()+2);
        for(int j = 0; j < a[i].size()+1; ++j)
            pr1[i][j+1] = pr1[i][j]+dp[i][j], pr1[i][j+1] += mod, pr1[i][j+1] %= mod;
    }
    int ans = pr1[0][a[0].size()+1];
    cout << ans;
    return 0;
}