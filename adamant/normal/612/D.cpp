#include <bits/stdc++.h>

#define INF (int)10e6
#define eps 10e-6
#define mp make_pair
#define pb push_back
#define all(t) t.begin(),t.end()
#define LL long long
#define MOD 1000000007


using namespace std;

//ifstream fin ("input.txt");
//ofstream fout ("output.txt");


vector< LL > ans;
vector< pair<LL,LL> > a;
int n,m,k;

bool cmp(pair<LL,LL> x, pair<LL,LL> y){
    if(x.first==y.first){
        return x.second>y.second;
    }
    return x.first<y.first;
}

int main(){
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
ios::sync_with_stdio(0);
    cin >> n >> k ;
    for(int i=0;i<n;++i){
        LL l,r; cin >> l >> r;
        a.pb(mp(l,1));
        a.pb(mp(r,-1));
    }
    sort(all(a),cmp);   
    int cnt=0;
    for(int i=0;i<a.size();++i){
        if(a[i].second==1){
            cnt++;
            if(cnt==k)
                ans.pb(a[i].first);
        }
        else{
            if(cnt==k){
                ans.pb(a[i].first);
                cnt--;
            }
            else{
                cnt--;
            }
        }
    }
    m=ans.size()/2;
    cout << m << "\n";
    for(int i=0;i<ans.size();i+=2){
        cout << ans[i] << " " << ans[i+1];
        cout << "\n";
    }
    return 0;
}