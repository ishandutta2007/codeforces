#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
using namespace std;
vector<pair<int , int>> ans;
const int K=20;
int ile[K];
vector<int> V;
void solve(int n, int pot){
    if(n==0)return;
    if(n==1){
        V.pb(pot);
        return;
    }
    int p=1;
    while(p<n)p*=2;
    if(n==p){
        V.pb(pot*p);
        n--;
    }
    for(int i=n; i>p/2; i--){
        ans.pb(mp(i*pot, (p-i)*pot));
        V.pb(p*pot);
    }
    V.push_back(p*pot/2);
    solve(p-n-1, pot);
    //solve(n-p/2, pot*2);
    solve(n-p/2, pot*2);
}
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        if(n>2){
            solve(n, 1);
            sort(V.begin(), V.end());
            int a=V.back();
            int z=0;
            while(V.size()&&V.back()==a){
                V.pop_back();
            }
            vector<int> V2;
            //for(int i:V)cout<<i<<" ";
            //cout<<"\n";
            for(int i:V)ile[__builtin_ctz(i)]++;
            for(int i=0; i<__builtin_ctz(a); i++){
                while(ile[i]>=2){
                    ile[i]-=2;
                    ile[i+1]++;
                    z++;
                    ans.pb(mp(1<<i, 1<<i));
                }
            }
            //cout<<"a\n";
            for(int i=0; i<__builtin_ctz(a); i++){
                if(ile[i]==1){
                    ile[i]--;
                    ile[i+1]++;
                    ans.pb(mp(0, 1<<i));
                    ans.pb(mp(1<<i, 1<<i));
                    assert(z>=1);
                }
                while(ile[i]>=2){
                    ile[i]-=2;
                    ile[i+1]++;
                    z++;
                    ans.pb(mp(1<<i, 1<<i));
                }

            }
ile[__builtin_ctz(a)]=0;
            while(z--){
                ans.pb(mp(0, a));
            }
        }
        if(n==2){
            cout<<"-1\n";
            continue;
        }
        cout<<ans.size()<<"\n";
        for(auto &i:ans){
            cout<<i.st<<" "<<i.nd<<"\n";
        }
        ans.clear();
V.clear();
    }
}