#include <iostream>

using namespace std;

long long h,n;
long long ans;

void dfs(long dir,long long l,long long r){
    long long m = (l+r)>>1;
    if(l==r) return;

    if(n <= m){
        if(dir==0) {
            ans ++;
            dfs(dir^1,l,m);
        }else{
            ans += (m-l+1)*2;
            dfs(dir,l,m);
        }
    } else {
        if(dir==1){
            ans++;
            dfs(dir^1,m+1,r);
        }else{
            ans += (r-m)*2;
            dfs(dir,m+1,r);
        }
    }
}

int main()
{
    cin >> h >> n;
    dfs(0,1,1LL<<h);
    cout << ans;

    return 0;
}