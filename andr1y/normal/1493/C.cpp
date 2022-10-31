// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll cnt[26];
ll ltk[26];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, k;
        string s;
        cin >> n >> k >> s;
        memset(cnt, 0, sizeof(cnt));
        memset(ltk, 0, sizeof(ltk));
        if(n%k){
            cout<<"-1\n";
            continue;
        }
        ll latl=0, clatl=s[0]-'a'+1;
        ll sltk=0;
        for(ll i = 0;i<n;i++){
            cnt[s[i]-'a']++;
            ltk[s[i]-'a']--;
            sltk--;
            if(ltk[s[i]-'a']<0) ltk[s[i]-'a']+=k, sltk+=k;
            if(i==n-1){
                if(sltk==0) latl=i+1;
            }else{
                for(ll j = 25;j>s[i+1]-'a';j--){
                    ltk[j]--, sltk--;
                    if(ltk[j]<0) ltk[j]+=k, sltk+=k;
                    if(sltk<=n-i-2) latl=i+1, clatl=j;
                    ltk[j]++, sltk++;
                    if(ltk[j]>=k) ltk[j]-=k, sltk-=k;
                }
            }
        }
        if(latl==n){
            cout<<s<<'\n';
            continue;
        }
        memset(cnt, 0, sizeof(cnt));
        memset(ltk, 0, sizeof(ltk));
        sltk=0;
        for(ll i = 0;i<latl;i++){
            cnt[s[i]-'a']++;
            ltk[s[i]-'a']--;
            sltk--;
            if(ltk[s[i]-'a']<0) ltk[s[i]-'a']+=k, sltk+=k;
        }
        ll lft2 = n-latl-1;
        s[latl]='a'+clatl;
        cnt[clatl]++;
        ltk[clatl]--;
        sltk--;
        if(ltk[clatl]<0) ltk[clatl]+=k, sltk+=k;
        ltk[0]+=lft2-sltk;
        latl++;
        for(ll i = 0;i<26;i++){
            while(ltk[i]){
                ltk[i]--;
                s[latl++]='a'+i;
            }
        }
        cout<<s<<'\n';
    }
}