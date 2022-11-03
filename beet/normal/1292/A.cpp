#include <bits/stdc++.h>
using namespace std;

using Int = long long;
const char newl = '\n';

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}
template<typename T=int>
vector<T> read(size_t n){
  vector<T> ts(n);
  for(size_t i=0;i<n;i++) cin>>ts[i];
  return ts;
}

//INSERT ABOVE HERE
const int MAX = 2e5;
int st[3][MAX]={};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;

  int x=0,y=0,z=0;

  for(int i=0;i<q;i++){
    int r,c;
    cin>>r>>c;

    x-=st[2][c+0]&&st[1][c+1];
    x-=st[2][c-1]&&st[1][c+0];
    y-=st[1][c+0]&&st[2][c+0];
    z-=st[1][c+0]&&st[2][c+1];
    z-=st[1][c-1]&&st[2][c+0];

    st[r][c]^=1;

    x+=st[2][c+0]&&st[1][c+1];
    x+=st[2][c-1]&&st[1][c+0];
    y+=st[1][c+0]&&st[2][c+0];
    z+=st[1][c+0]&&st[2][c+1];
    z+=st[1][c-1]&&st[2][c+0];

    cout<<(x+y+z==0?"Yes":"No")<<newl;
  }

  return 0;
}