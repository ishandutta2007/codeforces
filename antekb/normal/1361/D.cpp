#include<bits/stdc++.h>
#define st first
#define nd second
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N=1<<20, INF=2e9+5, mod=1e9+7;
vector<ld> V[N];
int ile[N];
int cwi(pii a){
    if(a.st>0 && a.nd>=0)return 0;
    if(a.st<=0 && a.nd>0) return 1;
    return (a.st<0)? 2:3;
}
int main(){
    int n, k;
    cin>>n>>k;
    vector<pii> pts(n);
    for(int i=0; i<n; i++){
        cin>>pts[i].st>>pts[i].nd;
    }
    sort(all(pts), [](pii a, pii b){
        if(a==mp(0, 0))return false;
        if(b==mp(0, 0)) return true;
        if(cwi(a)!=cwi(b))return cwi(a)<cwi(b);
        return a.st*1ll*b.nd<a.nd*1ll*b.st;
    });
    int wsk=0;
    //cout<<"\n";
    for(int i=0; i<n; i++){

        if(i && (cwi(pts[i])!=cwi(pts[i-1]) || pts[i].st*1ll*pts[i-1].nd!=pts[i].nd*1ll*pts[i-1].st)) wsk++;
        V[wsk].pb(sqrt(pts[i].st*1ll*pts[i].st+pts[i].nd*1ll*pts[i].nd));
        //cout<<pts[i].st<<" "<<pts[i].nd<<" "<<wsk<<"\n";
    }
    priority_queue<pair<ld, int>> Q;
    for(int i=0; sz(V[i]); i++){
        //cout<<V[i].size()<<" ";
        //for(auto c:V[i])cout<<c<<" ";
        //cout<<"\n";
        sort(all(V[i]));
        Q.push({V[i].back()*(k-1), i});
    }
    int cnt=0;
    ld sum=0;
    while(cnt<k){
        if(sz(Q)==1 && ile[Q.top().nd]>=(k-1)/2){
            break;
        }
        cnt++;
        int l=Q.top().nd;
        ile[l]++;
        sum+=Q.top().st;
        V[l].pop_back();
        Q.pop();
        if(sz(V[l])){
            Q.push({V[l].back()*(k-1-2*ile[l]), l});
        }
    }
    int l=Q.top().nd;
    for(int i=0; i<k-cnt; i++){
        sum+=V[l][i]*(k-1-2*(ile[l]+k-cnt-i-1));
    }
    cout<<fixed<<setprecision(9)<<sum;
}