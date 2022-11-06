#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
    cin >> s;
    int cnt = 0;
    rep(i,0,sz(s)) cnt += s[i] != s[sz(s)-i-1];
    if(cnt == 2 || (cnt == 0 && sz(s)&1))
        puts("YES");
    else
        puts("NO");
}