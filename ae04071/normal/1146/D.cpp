#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int vis[200100];
lli m,a,b;

lli s1(lli v) {
    return v*(v+1)/2;
}
int main() {
    scanf("%lld%lld%lld",&m,&a,&b);
    lli ans=0,g=__gcd(a,b);
    for(lli p=0,t=0,c=0;p<=m;p+=g) {
        queue<lli> que;
        if(p==0 || (p-a>=0 && vis[p-a])) {
            que.push(p);
            vis[p]=1;
        }
        while(!que.empty()) {
            lli cur=que.front();que.pop();
            t++;
            if(cur<=a) c++;
            if(cur-b>=0 && !vis[cur-b]) {
                vis[cur-b]=1;
                que.push(cur-b);
            }
            if(cur+a<=p && !vis[cur+a]) {
                vis[cur+a]=1;
                que.push(cur+a);
            }
        }
        if(c==a/g+1) {
            ans += (s1((m-p+1)/g-1+t) - s1(t-1))*g;
            ans += ((m-p+1)/g+t)*((m-p+1)%g);
            break;
        } else {
            ans += min(g,m-p+1)*t;
        }
    }
    printf("%lld\n",ans);
    return 0;
}