#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const int N = 1e6 + 3;

deque <pair<ll,ll>> q;
ll n,m,ctk,ct,ans = 2,flag = 0,flag1 = 0;
string mat[N],mat2[N];
pair <ll,ll> p;
map <pair <ll,ll>,ll> d;

void dfsup(ll x, ll y){
    if(x == 0 && y == 0) flag = 1;
    d[{x,y}]++;
    //cout<<x<<" "<<y<<endl;
    if(mat[x][y] == '.'){
        ll j = y-1;
        if(j != -1){
            if(mat[x][j] != '#' ){
                dfsup(x,j);
            }
        }
        if(flag != 1){
            j = x-1;
            if(j != -1){
                if(mat[j][y] != '#'){
                    dfsup(j,y);
                }
            }
        }
        mat[x][y] = '#';
    }
}

void dfsleft(ll x , ll y){
    if(x == 0 && y == 0) flag1 = 1;
    else if((x != n-1 || y != m-1) && d[{x,y}]) ans = 1;
    if(mat2[x][y] == '.'){
        ll j = x-1;
        if(j != -1){
            if(mat2[j][y] != '#'){
                dfsleft(j,y);
            }
        }
        if(flag1 != 1){
            j = y-1;
            if(j != -1){
                if(mat2[x][j] != '#' ){
                    dfsleft(x,j);
                }
            }
        }
        mat2[x][y] = '#';
    }
}

int main(){
    cin>>n>>m;
    
    for(int i = 0; i < n; i++) {
        cin>>mat[i];
        mat2[i] = mat[i];
    }

    dfsup(n-1,m-1);
    dfsleft(n-1,m-1);

    if(flag == 0) cout<<"0"<<endl; 
    else cout<<ans<<endl;
}