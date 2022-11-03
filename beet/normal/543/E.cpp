#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
const int X = 9;
const int BS = 1<<X;
const int MAX = 1<<18;

int dat[MAX]={}; // state
int val[MAX>>X]={}; // max
int frt[MAX>>X]={}; // front
int add[MAX>>X]={}; // add

int bm[MAX>>X][MAX>>X]; // max
int bf[MAX>>X][MAX>>X]; // front

int cp[3][MAX]={}; // pos
int cv[3][MAX]={}; // value

inline int block_id(int x){return x>>X;};
inline int position(int x){return x&(BS-1);};
inline int first_element(int x){return x<<X;};

signed main(){
  int n,m;
  cin>>n>>m;
  vector<int> as(n+n,0);
  for(int i=0;i<n;i++) cin>>as[i];

  using P = pair<int, int>;
  vector<P> vp;
  for(int i=0;i<n;i++) vp.emplace_back(-as[i],i);
  sort(vp.begin(),vp.end());

  auto eval=
    [&](int i){
      int l=first_element(block_id(i));
      if(add[block_id(l)]==0) return;
      for(int j=l;j<l+BS;j++) dat[j]+=add[block_id(j)];
      add[block_id(l)]=0;
    };

  for(int i=0;i<n;i++){
    if(position(i)==0){
      for(int j=0;j<MAX;j+=BS){
        val[block_id(j)]+=add[block_id(j)];
        eval(j);
        bm[block_id(i)][block_id(j)]=val[block_id(j)];
        bf[block_id(i)][block_id(j)]=dat[j];
      }
    }

    // [l, r)
    int r=vp[i].second+1;
    int l=max(0,r-m);

    int idx=0;
    cp[idx][i]=-1;
    for(int j=l;j<r;j++){
      if(position(j)==0 && j+BS<=r){
        add[block_id(j)]+=1;
        j+=BS-1;
      }else{
        dat[j]+=1;
        chmax(val[block_id(j)],dat[j]);
        if(cp[idx][i]!=block_id(j)){
          idx++;
          cp[idx][i]=block_id(j);
        }
        cv[idx][i]=val[cp[idx][i]];
      }
    }
    while(idx<2){
      idx++;
      cp[idx][i]=(MAX>>X)-1;
      cv[idx][i]=val[cp[idx][i]];
    }
  }

  auto calc=
    [&](int l,int r,int v)->int{
      int idx=upper_bound(vp.begin(),vp.end(),P(-v,n))-vp.begin();

      int k=first_element(block_id(idx));
      for(int j=0;j<MAX;j+=BS){
        val[block_id(j)]=bm[block_id(k)][block_id(j)];
        frt[block_id(j)]=bf[block_id(k)][block_id(j)];
        add[block_id(j)]=0;
      }

      for(int i=k;i<idx;i++){
        int q=vp[i].second+1;
        int p=max(0,q-m);
        if(position(p)) p=first_element(block_id(p)+1);
        if(p<=q){
          add[block_id(p)]+=1;
          add[block_id(q)]-=1;
        }
        val[cp[1][i]]=cv[1][i];
        val[cp[2][i]]=cv[2][i];
        if(p<=q && position(q)) frt[block_id(q)]+=1;
      }

      for(int j=BS;j<MAX;j+=BS)
        add[block_id(j)]+=add[block_id(j)-1];

      int res=0,flg=0,tmp=0;
      for(int j=l;j<r;j++){
        if(position(j)==0 && j+BS<=r){
          chmax(res,val[block_id(j)]+add[block_id(j)]);
          j+=BS-1;
          flg=0;
        }else{
          if(flg==0){
            flg=1;
            tmp=frt[block_id(j)]+add[block_id(j)];
            int p=first_element(block_id(j));
            while(p<j){
              tmp-=as[p]>=v;
              tmp+=as[p+m]>=v;
              p++;
            }
          }
          chmax(res,tmp);
          tmp-=as[j]>=v;
          tmp+=as[j+m]>=v;
        }
      }
      return m-res;
    };

  int q;
  cin>>q;
  int pre_ans=0;
  for(int i=0;i<q;i++){
    int l,r,x;
    cin>>l>>r>>x;
    l--;
    int ans=calc(l,r,x^pre_ans);
    cout<<ans<<"\n";
    pre_ans=ans;
  }
  cout<<flush;
  return 0;
}