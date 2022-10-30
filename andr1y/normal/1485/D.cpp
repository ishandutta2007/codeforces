// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll b[505][505];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<m;j++){
            ll a;
            cin >> a;
            if((i+j)&1){
                //even
                b[i][j]=720720;
            }else{
                if(a==1||a==2||a==3||a==4||a==6||a==8||a==9||a==12||a==16) b[i][j] = 719424;
                else if(a==5||a==15) b[i][j] =670095;
                else if(a==7||a==14) b[i][j] =106064;
                else if(a==10) b[i][j]=560720;
                else if(a==11) b[i][j]=486464;
                else if(a==13) b[i][j]=263744;
            }
            cout<<b[i][j]<<' ';
        }
        cout<<'\n';
    }
}