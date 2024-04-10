#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef long long ll;
const int maxn=2e5+10;
const ll bas=99885111ll,P=1e18+7;
int n,m;string S[maxn];vector<int>up[maxn];vector<ll>pre[maxn];ll pw[maxn],occ[maxn],C2[maxn];

ll mul(ll a,ll b){
  ll t=a*b-(ll)((ll)((long double)a/P*b)*P);
  return t<0?t+P:t;
}
ll getH(const string&str){
  ll res=0;
  for(char c:str)res=(mul(res,bas)+c)%P;
  return res;
}
ll query(vector<ll>&A,int l,int r){
  if(!l)return A[r];
  return(A[r]+mul(P-A[l-1],pw[r-l+1]))%P;
}

map<ll,int>zzh;
map<ll,vector<int>>mp;

int main(){
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(0);
  pw[0]=1;rep(i,1,maxn-1)pw[i]=mul(bas,pw[i-1]),C2[i]=1ll*i*(i-1)/2;
  cin>>n;
  rep(i,1,n)cin>>S[i];
  m=S[n].size();
  rep(i,1,n){
    vector<int>ct(26,0);
    string res="";
    rep(j,0,m-1)ct[S[i][j]-'a']++;
    ll s=0;
    int k=0;
    rep(j,0,m-1){
      k=max(k,j);
      while(k<m-1&&S[i][k+1]>=S[i][k])k++;
      up[i].push_back(k);
      s=(mul(s,bas)+S[i][j])%P;
      pre[i].push_back(s);
    }
    rep(c,0,25)rep(j,1,ct[c])res+=char(c+'a');
    occ[i]=getH(res);
  }
  if(m>=50){
    ll ans=0;
    rep(i,1,n)rep(j,i+1,n)if(occ[i]==occ[j]){
      if(pre[i][m-1]==pre[j][m-1])continue;
      int pos=0;
      while(S[i][pos]==S[j][pos])pos++;
      int ed=m-1;
      while(S[i][ed]==S[j][ed])ed--;
      if(up[i][pos]>=ed||up[j][pos]>=ed){
        ans++;
      }else{
        ans+=2;
      }
    }else ans+=1337;
    cout<<ans<<endl;
    return 0;
  }
  ll ans=1ll*n*(n-1)/2*1337;
  rep(i,1,n)mp[occ[i]].push_back(i),ans-=zzh[pre[i][m-1]]++*2;
  for(auto&p:mp){
    vector<int>&V=p.second;
    int sz=V.size();
    ans-=1ll*sz*(sz-1)/2*1337;
    ans+=1ll*sz*(sz-1)/2*2;
    rep(lcp,0,m-1){
      map<ll,vector<int>>orz;
      for(int x:V)orz[lcp?pre[x][lcp-1]:0].push_back(x);
      for(auto&q:orz){
        auto&vec=q.second;
        rep(lcs,0,m-lcp-2){
          map<ll,vector<int>>zzh;
          for(int x:vec)zzh[lcs?query(pre[x],m-lcs,m-1):0].push_back(x);
          for(auto&r:zzh){
            auto&ano=r.second;
            if((int)ano.size()<=200){
              struct node{
                char x,y;bool f;
              };
              vector<node>A(ano.size());
              rep(i,0,ano.size()-1){
                int x=ano[i];
                A[i]={S[x][lcp],S[x][m-lcs-1],up[x][lcp]>=m-lcs-1};
              }
              rep(i,0,ano.size()-1)rep(j,i+1,ano.size()-1){
                if(A[i].x!=A[j].x&&A[i].y!=A[j].y&&(A[i].f||A[j].f)){
                  ans--;
                }
              }
            }else{
              static int buk[2][26][26],row[26],col[26];
              memset(buk,0,sizeof buk);
              memset(row,0,sizeof row);
              memset(col,0,sizeof col);
              int su=0;
              for(int x:ano){
                bool f=up[x][lcp]>=m-lcs-1;
                int i=S[x][lcp]-'a',j=S[x][m-lcs-1]-'a';
                buk[f][i][j]++;
                if(f){
                  su++,row[i]++,col[j]++;
                }
              }
              rep(i,0,25)rep(j,0,25){
                int t=buk[0][i][j];
                if(t){
                  ans-=1ll*t*(su-row[i]-col[j]+buk[1][i][j]);
                }
              }
              ans-=C2[su];
              rep(i,0,25)ans+=C2[row[i]]+C2[col[i]];
              rep(i,0,25)rep(j,0,25)ans-=C2[buk[1][i][j]];
            }
          }
        }
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}