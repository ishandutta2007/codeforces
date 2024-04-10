#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
const int INF=1e9+7;
pair<pair<int,int>,int>T[25];
map<pair<pair<int,int>,int>,pair<int,int>>mp;
int ans1, ans2, ans3=-INF;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    rep(i, n) cin >> T[i].st.st >> T[i].st.nd >> T[i].nd;
    int ma=1;
    rep(i, n/2) ma*=3;
    rep(i, ma) {
        int sum1=0, sum2=0, sum3=0, p=i;
        rep(j, n/2) {
            sum1+=T[j].st.st;
            sum2+=T[j].st.nd;
            sum3+=T[j].nd;
            if(p%3==0) sum1-=T[j].st.st;
            if(p%3==1) sum2-=T[j].st.nd;
            if(p%3==2) sum3-=T[j].nd;
            p/=3;
        }
        int mi=min(min(sum1, sum2), sum3);
        p=max(max(sum1, sum2), sum3);
        sum1-=mi;
        sum2-=mi;
        sum3-=mi;
        if(mp[{{sum1, sum2}, sum3}].nd==0 || mp[{{sum1, sum2}, sum3}].st<p) mp[{{sum1, sum2}, sum3}]={p, i+1};
    }
    ma=1;
    for(int i=n/2; i<n; ++i) ma*=3;
    rep(i, ma) {
        int sum1=0, sum2=0, sum3=0, p=i;
        for(int j=n/2; j<n; ++j) {
            sum1+=T[j].st.st;
            sum2+=T[j].st.nd;
            sum3+=T[j].nd;
            if(p%3==0) sum1-=T[j].st.st;
            if(p%3==1) sum2-=T[j].st.nd;
            if(p%3==2) sum3-=T[j].nd;
            p/=3;
        }
        int mi=min(min(sum1, sum2), sum3);
        sum1-=mi;
        sum2-=mi;
        sum3-=mi;
        int ma=max(max(sum1, sum2), sum3);
        sum1=ma-sum1;
        sum2=ma-sum2;
        sum3=ma-sum3;
        int l=mp[{{sum1, sum2}, sum3}].nd;
        if(l) {
            p=l-1;
            int sum1=0;
            rep(j, n/2) {
                sum1+=T[j].st.st;
                if(p%3==0) sum1-=T[j].st.st;
                p/=3;
            }
            p=i;
            for(int j=n/2; j<n; ++j) {
                sum1+=T[j].st.st;
                if(p%3==0) sum1-=T[j].st.st;
                p/=3;
            }
            if(sum1>ans3) {
                ans3=sum1;
                ans1=l-1;
                ans2=i;
            }
        }
    }
    if(ans3==-INF) cout << "Impossible\n";
    else {
        rep(i, n/2) {
            if(ans1%3==0) cout << "MW\n";
            if(ans1%3==1) cout << "LW\n";
            if(ans1%3==2) cout << "LM\n";
            ans1/=3;
        }
        for(int j=n/2; j<n; ++j) {
            if(ans2%3==0) cout << "MW\n";
            if(ans2%3==1) cout << "LW\n";
            if(ans2%3==2) cout << "LM\n";
            ans2/=3;
        }
    }
}