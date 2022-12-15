#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli=long long;
using pii=pair<lli,int>;

int n,m;
lli a[100000],ans[100000];
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lld",a+i);

    vector<pii> qa;
    scanf("%d",&m);
    for(int i=0;i<m;i++) {
        lli l,r;
        scanf("%lld%lld",&l,&r);
        qa.push_back(pii(r-l,i));
    }
    
    sort(a,a+n);
    priority_queue<lli,vector<lli>,greater<lli>> que;
    for(int i=0;i<n-1;i++) que.push(a[i+1]-a[i]);
    
    sort(qa.begin(),qa.end());

    lli sum=0,pr=0,cnt=n;
    for(int i=0;i<m;i++) {
        while(!que.empty() && que.top()<=qa[i].fi) {
            if(pr!=que.top()) sum += (que.top()-pr)*cnt,pr=que.top();
            cnt--; que.pop();
        }
        ans[qa[i].se] = sum + (qa[i].fi-pr+1)*cnt;
    }
    for(int i=0;i<m;i++) printf("%lld ",ans[i]);
    
    return 0;
}