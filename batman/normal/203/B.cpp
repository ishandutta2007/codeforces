//INOG
#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ll long long
#define int long long
#define lb long double
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()

const long long MAXN=1e6;
const long long MAXM=1e3;
const long long MOD=1e9+7;
const long long INF=1e15+5040;

bool a[MAXM][MAXM];

bool check(int x,int y){
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            if(x-i<0  || y-j<0)continue;
            bool f=true;
            for(int k=0;k<3;k++)
                for(int t=0;t<3;t++)
                    f=(f && (a[x+k-i][y+t-j]));
            if(f)return true;
        }
    return false;
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(false),cout.tie(false);
    int n;
    cin>>n;
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        x--,y--;
        a[x][y]=true;
        if(check(x,y))return cout<<i+1,0;
    }
    cout<<-1;
}