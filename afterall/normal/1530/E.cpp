#include <bits/stdc++.h>
/// 500 485 462 A4
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100;
ll cnt[27];
int Main(){
    memset(cnt,0,sizeof cnt);
    string s;
    cin >> s;
    ll n=s.size();
    for (int i=0;i<n;i++){
        cnt[s[i]-'a']++;
    }
    ll id=-1;
    vector <int> b;
    for (int i=0;i<27;i++){
        if (cnt[i]>0) b.pb(i);
        if (cnt[i]==1 && id==-1) id=i;
    }
    string ans="";
    if (id!=-1){
        ans+=(char)('a'+id);
        cnt[id]--;
        for (int i=0;i<27;i++){
            for (int j=0;j<cnt[i];j++){
                ans+=(char)('a'+i);
            }
        }
        kill(ans);
    }
    if (cnt[b[0]]-2<=n-(cnt[b[0]])){
        vector <char> cc;
        for (int i=0;i<27;i++){
            if (i==b[0]) continue;
            for (int j=0;j<cnt[i];j++){
                cc.pb((char)('a'+i));
            }
        }
        reverse(cc.begin(),cc.end());
        ans+=(char)('a'+b[0]);
        cnt[b[0]]--;
        for (int i=0;i<cnt[b[0]];i++){
            ans+=(char)('a'+b[0]);
            if (cc.size()){
                ans+=cc.back();

                cc.pop_back();
            }
        }
        while(cc.size()){
            ans+=cc.back();
            cc.pop_back();

        }
        kill(ans);
    }
    if (b.size()>2){
        ans+=(char)('a'+b[0]);
        ans+=(char)('a'+b[1]);
        for (int i=0;i<cnt[b[0]]-1;i++){
            ans+=(char)('a'+b[0]);
        }
        ans+=(char)('a'+b[2]);
        cnt[b[1]]--;
        cnt[b[2]]--;
        cnt[b[0]]=0;
        for (int i=0;i<27;i++){
            for (int j=0;j<cnt[i];j++){
                ans+=(char)('a'+i);
            }
        }
        kill(ans);
    }
    if (b.size()==1){
        kill(s);
    }
    /*
    if (cnt[b[0]]-1<=cnt[b[1]]){
        ans+=(char)('a'+b[0]);
        cnt[b[0]]--;
        for (int i=0;i<cnt[b[0]];i++){
            ans+=(char)('a'+b[0]);
            ans+=(char)('a'+b[1]);
            cnt[b[1]]--;
        }
        for (int i=0;i<cnt[b[1]];i++){
            ans+=(char)('a'+b[1]);
        }
        kill(ans);
    }
    else{
    */
        ans+=(char)('a'+b[0]);
        cnt[b[0]]--;
        for (int i=0;i<cnt[b[1]];i++){
            ans+=(char)('a'+b[1]);
        }
        for (int i=0;i<cnt[b[0]];i++){
            ans+=(char)('a'+b[0]);
        }
        kill(ans);

    kill(-1);
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}