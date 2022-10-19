#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define fi first 
#define se second
const int maxn = 2e5+10; 
int n,k;
int s[maxn];
int cnt[maxn];
int cal(int x) {
    int ch = 0;
    for(int i=1; i<=200000; i++){
        ch+=cnt[i]/x;
    }
    if(ch>=k) return 1;
    else return 0;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
  //freopen("input.txt","r",stdin);
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        cin >> s[i];
        cnt[s[i]]++;
    }
    int l=1; int r=maxn;
    while(l<=r) {
        int mid=(l+r)/2;
        if(cal(mid)==0) r=mid-1;
        else l=mid+1;
    }
    //cout<<1;
    for(int i=1; i<=200000; i++){
        if(cnt[i]/r!=0) {
            int res = min(cnt[i]/r,k);
            for(int j=1; j<=res; j++) {
                //if(res==k&&j==res) cout<<(int)i;
                 cout<<i<<" ";
            }
            k-=res;
        } 
    }
    //debug xong roi. nop lai thu xem...
    cout<<endl;
    
    return 0;
}