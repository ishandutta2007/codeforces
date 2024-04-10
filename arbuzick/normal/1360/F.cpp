#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
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
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    M[0] = 1000000007;
    M[1] = 1000000009;
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        string s = "";
        string ans = "";
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < 26; ++j){
                s += char('a'+j);
                for(int i1 = i+1; i1 < m; ++i1)
                    s += a[0][i1];
                bool ans1 = 1;
                for(int j = 1; j < n; ++j){
                    int k = 0;
                    for(int j2 = 0; j2 < m; ++j2)
                        if(s[j2] != a[j][j2])
                            k++;
                    if(k > 1)
                        ans1 = 0;
                }
                if(ans1){
                    ans = s;
                    break;
                }
                while(s.size() > i)
                    s.pop_back();
            }
            if(ans.size())
                break;
            s += a[0][i];
        }
        if(ans.size())
            cout << ans << '\n';
        else
            cout << -1 << '\n';
    }
	return 0;
}