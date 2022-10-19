#include<bits/stdc++.h>

#define st first
#define nd second
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
#define sz(x) (int)(x).size()

using namespace std;

///~~~~~~~~~~~~~~~~~~~~~~~~~~

void debug(){cerr<<"\n";}
template <typename H, typename... T>
void debug(H h, T... t) {cerr<<h; if (sizeof...(t)) cerr << ", "; debug(t...);}
#define deb(x...) cerr<<#x<<" = ";debug(x);

///~~~~~~~~~~~~~~~~~~~~~~~~~

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef string str;

const int N=2e5+5, INF=1e9+5, mod=1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    vector<int> V(n), ile(n+1);
    for(int &i:V){
        cin>>i;
    }
    int maks=0, t;
    for(int i:V){
        if(++ile[i]>maks){
            t=i;
            maks=ile[i];
        }
    }
    /*for(int i=0; i<=n; i++){
        if(ile[i]==ile[t] && i!=t){
            cout<<n;
            return 0;
        }
    }*/
    //cout<<
    vector<vector<int> > gdzie(n+1);
    for(int i=0; i<n; i++){
        gdzie[V[i]].pb(i);
        //pref[i+1]=pref[i]+(V[i]==t);
    }
    int ans=0;
    for(int i=0; i<=n; i++){
        if(i==t || !sz(gdzie[i]))continue;
        vi V2, V3;
        V2.pb(-1);
        V3.pb(-1);
        vii V4;
        V4.pb(mp(-1, 0));
        for(int j:gdzie[i]){
            V4.pb(mp(j, 1));
        }
        for(int j:gdzie[t]){
            V4.pb(mp(j, -1));
        }
        sor(V4);
        V4.pb(mp(n, 0));
        int act=0;
        for(int j=1; j<V4.size()-1; j++){
            act+=V4[j].nd;
            if(act>=0){
                if(V2.size()>act){
                    ans=max(ans, V4[j+1].st-1-V2[act]);
                }
                else{
                    V2.pb(V4[j].st);
                }
            }
            else{
                //act=-act;
                if(sz(V3)>-act){
                    ans=max(ans, V4[j+1].st-1-V3[-act]);
                }
                else{
                    V3.pb(V4[j].st);
                }
            }
            //cout<<ans<<"\n";
        }
        /*while(wsk1<gdzie[t].size() || wsk2<gdzie[i].size()){
            //cout<<wsk1<<" "<<wsk2<<"\n";
            int id=-1;
            if(wsk1==gdzie[t].size()){
                id=gdzie[i][wsk2++];
                act--;
            }
            else{
                if(wsk2==gdzie[i].size()){
                    id=gdzie[t][wsk1++];
                    act++;
                }
                else{
                    if(gdzie[i][wsk2]<gdzie[t][wsk1]){
                        id=gdzie[i][wsk2++];
                        act--;
                    }
                    else{
                        id=gdzie[t][wsk1++];
                        act++;
                    }
                }
            }
            //deb(act, id);

        }*/
        //cout<<ans<<"\n";
    }
    cout<<ans;
}