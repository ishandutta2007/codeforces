#include<bits/stdc++.h>

#define st first
#define nd second
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
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

    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        int blo=0, m=0, blo2=-1;
        vi V;
        for(int i=0; i<n; i++){
            //cout<<blo2<<" "<<blo<<"\n";
            if(s[i]=='L')blo++;
            if(i!=0 && blo==0)m++;
            if(s[i]=='W'){
                m++;
                if(blo){
                    //cout<<"a";
                    if(blo2!=-1){V.pb(blo);}
                    else blo2=blo;
                }
                else if(blo2==-1)blo2=0;
                blo=0;
            }
        }
        if(blo2==-1){
            //blo2=0;
            cout<<max(min(n, k)*2-1, 0)<<"\n";
            continue;
        }
        blo2+=blo;
        //cout<<m<<" "<<blo2<<" "<<V.size()<<" ";
        sort(all(V));
        reverse(all(V));
        while(V.size() && V.back()<=k){
            m+=2*V.back()+1;
            k-=V.back();
            V.pop_back();
        }
        if(V.size())m+=2*k;
        else m+=min(k, blo2)*2;
        //cout<<s<<"\n";
        cout<<m<<"\n";
    }
}