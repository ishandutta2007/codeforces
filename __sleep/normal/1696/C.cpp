#include<cstdio>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
int t, n, m, k;
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n,&m);
        vector<int> a(n+2);
        for (int i = 1; i <= n;i++)
            scanf("%d", &a[i]);
        // puts("!");
        scanf("%d", &k);
        vector<int> b(k+2);
        for (int i = 1; i <= k;i++)
            scanf("%d", &b[i]);
        vector<pair<int,long long> > aa, bb;
        for(auto v:a){
            int x=v, y=1;
            while(x%m==0&&x!=0)
                x /= m, y *= m;
            if(aa.size()&&aa.rbegin()->first==x)
                aa.rbegin()->second += y;
            else
                aa.push_back({x,y});
        }
        for(auto v:b){
            int x=v, y=1;
            while(x%m==0&&x!=0)
                x /= m, y *= m;
            if(bb.size()&&bb.rbegin()->first==x)
                bb.rbegin()->second += y;
            else
                bb.push_back({x,y});
        }
        if(aa.size()!=bb.size())
            goto NO;
        for (int i = 0; i < aa.size();i++)
            if(aa[i]!=bb[i])
                goto NO;
        puts("Yes");
        continue;
NO:
        puts("No");
    }
    return 0;
}