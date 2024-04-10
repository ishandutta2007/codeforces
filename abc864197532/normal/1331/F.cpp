#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<lli,lli> 
#define X first
#define Y second

string s[] = {"H","HE","LI","BE","B","C","N","O","F","NE","NA","MG","AL","SI","P","S","CL","AR","K","CA","SC","TI","V","CR","MN","FE","CO","NI","CU","ZN","GA","GE","AS","SE","BR","KR","RB","SR","Y","ZR","NB","MO","TC","RU","RH","PD","AG","CD","IN","SN","SB","TE","I","XE","CS","BA","LA","CE","PR","ND","PM","SM","EU","GD","TB","DY","HO","ER","TM","YB","LU","HF","TA","W","RE","OS","IR","PT","AU","HG","TL","PB","BI","PO","AT","RN","FR","RA","AC","TH","PA","U","NP","PU","AM","CM","BK","CF","ES","FM","MD","NO","LR","RF","DB","SG","BH","HS","MT","DS","RG","CN","NH","FL","MC","LV","TS","OG"};

int main () {
    string t;
    cin >> t;
    bool dp[11];
    fop (i,0,11) dp[i] = false;
    dp[0] = true;
    fop (i,1,t.length() + 1) {
        for (string ss : s) {
            if (i >= 2 and ss.length() == 2 and t.substr(i - 2, 2) == ss) {
                if (dp[i-2]) dp[i] = true;
            } else if (ss.length() == 1 and t.substr(i - 1, 1) == ss) {
                if (dp[i-1]) dp[i] = true;
            }
        }
    }
    if (dp[t.length()]) cout << "YES\n";
    else cout << "NO\n";
}