#include<bits/stdc++.h>
using namespace std;
inline int read(){
 int x = 0,f = 1;char ch = getchar();
 while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
 while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
 return x*f;
}
const int N = 100005,M = 6800005;

int d[N],tot;
int q,change[N],opts[N];
map<string,int> mp;
string opt,name;
int x;


class Segtree{
public:
 int root[N],cnt;
 struct node{
  int ls,rs;
  int sum;
  node(){
   ls = rs = sum = 0;
  }
 }tr[M];
 void add(int &rt1,int rt2,int l,int r,int x,int v){
  rt1 = ++cnt;
  tr[rt1] = tr[rt2];
  tr[rt1].sum += v;
  if(l == r) return;
  int mid = (l+r)>>1;
  if(x <= mid) add(tr[rt1].ls,tr[rt2].ls,l,mid,x,v);
  else add(tr[rt1].rs,tr[rt2].rs,mid+1,r,x,v);
 }
 int query(int rt,int l,int r,int x){
  if(l == r) return 0;
  int mid = (l+r)>>1;
  if(x <= mid) return query(tr[rt].ls,l,mid,x);
  else return tr[tr[rt].ls].sum+query(tr[rt].rs,mid+1,r,x);
 }
 int Gets(int rt,int l,int r,int x){
  if(l == r) return tr[rt].sum;
  int mid = (l+r)>>1;
  if(x <= mid) return Gets(tr[rt].ls,l,mid,x);
  else return Gets(tr[rt].rs,mid+1,r,x);
 }
}A,B;
int main(){
 cin >> q;
 for(int i = 1;i <= q;++i){
  cin >> opt;
  // cout << opt << endl;
  A.root[i] = A.root[i-1];
  B.root[i] = B.root[i-1];
  if(opt[0] == 's'){
   cin >> name >> x;
   if(mp[name] == 0){
    mp[name] = ++tot;
    B.add(B.root[i],B.root[i],1,100000,mp[name],x);
    A.add(A.root[i],A.root[i],1,1e9,x,1);
   }
   else{
    int tmp = B.Gets(B.root[i],1,100000,mp[name]);
    B.add(B.root[i],B.root[i],1,100000,mp[name],x-tmp);
    if(tmp != 0) A.add(A.root[i],A.root[i],1,1e9,tmp,-1);
    A.add(A.root[i],A.root[i],1,1e9,x,1);
   }
  }
  else if(opt[0] == 'r'){
   cin >> name;
   if(mp[name] != 0){
    int tmp = B.Gets(B.root[i],1,100000,mp[name]);
    B.add(B.root[i],B.root[i],1,100000,mp[name],-tmp); 
    if(tmp == 0) continue;
    A.add(A.root[i],A.root[i],1,1e9,tmp,-1);
   }
  }
  else if(opt[0] == 'q'){
   cin >> name;
   if(mp[name] == 0) puts("-1");
   else{
    int tmp = B.Gets(B.root[i],1,100000,mp[name]);
    if(tmp == 0){
     puts("-1");
     continue;
    }
    printf("%d\n",A.query(A.root[i],1,1e9,tmp));
   }
  }
  else{
   cin >> x;
   A.root[i] = A.root[i-x-1];
   B.root[i] = B.root[i-x-1];
  }
  cout << flush;

 }
}