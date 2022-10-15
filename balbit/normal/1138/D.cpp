#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define piii pair<pair<int, int>, int> 
#define pll pair<ll, ll>
#define ull unsigned ll
#define REP(i,n) for (int i=0; i<n; i++)
#define RREP(i,n) for (int i=n; i>=0; i--)
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define MNTO(a,b) a = min(a,b)
#define MXTO(a,b) a = max(a,b)
#define ALL(a) a.begin(), a.end()
#define SZ(a) a.size()
#define pb push_back
#define f first
#define s second

using namespace std;

#define debug(x) cerr<<#x<<" is "<<x<<endl

const int maxn = 5e5+5;
const ll inf = 1ll<<60;

int lps[maxn]; 

int longestPrefixSuffix(string s) 
{ 
    int n = s.length(); 
  
    
    lps[0] = 0; // lps[0] is always 0 
  
    // length of the previous 
    // longest prefix suffix 
    int len = 0; 
  
    // the loop calculates lps[i] 
    // for i = 1 to n-1 
    int i = 1; 
    while (i < n) 
    { 
        if (s[i] == s[len]) 
        { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            // This is tricky. Consider 
            // the example. AAACAAAA 
            // and i = 7. The idea is 
            // similar to search step. 
            if (len != 0) 
            { 
                len = lps[len-1]; 
  
                // Also, note that we do 
                // not increment i here 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
  
    int res = lps[n-1]; 
  
    // Since we are looking for 
    // non overlapping parts. 
    return res; 
} 

vector<int> nn(2);

void out(int x){
    if (nn[x]){
        cout<<(x); nn[x]--;
    }else{
        cout<<(x^1);
        nn[(x^1)]--;
    }
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string a,b;
    cin>>a>>b;
    REP(i,a.length()){
        nn[a[i]-'0']++;
    }
    int lllps = longestPrefixSuffix(b);
    int it = 0;
    REP(i,a.length()){
        if (it>=b.length()) it = lllps;
        if (it>=b.length()) it = 0;
        out(b[it]-'0');
        it++;
    }
}