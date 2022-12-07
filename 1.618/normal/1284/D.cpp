#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#include <set>

using namespace std;
typedef long long ll;
const int LEN = 100000;

struct fastio{
  int it,len;
  char s[LEN + 5];
  fastio(){
    it = len = 0;
  }
  char get(){
    if(it < len) return s[it++];
    it = 0, len = fread(s,1,LEN,stdin);
    return len ? s[it++] : EOF;
  }
  bool notend(){
    char c;
    for(c = get();c == ' ' || c == '\n';c = get());
    if(it) it--;
    return c != EOF;
  }
  void put(char c){
    if(it == LEN) fwrite(s,1,LEN,stdout), it = 0;
    s[it++] = c;
  }
  void flush(){
    fwrite(s,1,it,stdout);
  }
}buff,bufo;
inline int getint(){
  char c; int res = 0, sig = 1;
  for(c = buff.get();c < '0' || c > '9';c = buff.get()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = buff.get()) res = res * 10 + (c - '0');
  return sig * res;
}
inline ll getll(){
  char c; ll res = 0, sig = 1;
  for(c = buff.get();c < '0' || c > '9';c = buff.get()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = buff.get()) res = res * 10 + (c - '0');
  return sig * res;
}
inline void putint(int x,char suf){
  if(!x) bufo.put('0');
  else{
    if(x < 0) bufo.put('-'), x = -x;
    int k = 0; char s[15];
    while(x){
      s[++k] = x % 10 + '0';
      x /= 10;
    }
    for(;k;k--) bufo.put(s[k]);
  }
  bufo.put(suf);
}
inline void putll(ll x,char suf){
  if(!x) bufo.put('0');
  else{
    if(x < 0) bufo.put('-'), x = -x;
    int k = 0; char s[25];
    while(x){
      s[++k] = x % 10 + '0';
      x /= 10;
    }
    for(;k;k--) bufo.put(s[k]);
  }
  bufo.put(suf);
}
inline char get_char(){
  char c;
  for(c = buff.get();c == ' ' || c == '\n';c = buff.get());
  return c;
}
#define maxn 100005
#define maxp 400005
#define mp make_pair
typedef pair<int,int> P;
int n,rb,sa[maxn],ea[maxn],sb[maxn],eb[maxn];
vector <int> ps;
vector <P> al,bl,ar,br; // val,id.
struct Sgt{
  ll sum[maxp << 2],add[maxp << 2];
  void clear(){
    memset(sum,0,sizeof(sum));
    memset(add,0,sizeof(add));
  }
  void up(int id,int l,int r){
    sum[id] = sum[id << 1] + sum[id << 1 | 1];
    sum[id] += add[id] * (r - l + 1);
  }
  void down(int id,int l,int r){
    if(add[id]){
      int mid = (l + r) >> 1;
      add[id << 1] += add[id];
      sum[id << 1] += add[id] * (mid - l + 1);
      add[id << 1 | 1] += add[id];
      sum[id << 1 | 1] += add[id] * (r - mid);
      add[id] = 0;
    }
  }
  void _plus(int id,int l,int r,int ql,int qr,ll x){
    if(ql <= l && r <= qr){
      add[id] += x;
      sum[id] += x * (r - l + 1);
    }else{
      down(id,l,r);
      int mid = (l + r) >> 1;
      if(ql <= mid) _plus(id << 1,l,mid,ql,qr,x);
      if(mid < qr) _plus(id << 1 | 1,mid + 1,r,ql,qr,x);
      up(id,l,r);
    }
  }
  ll query(int id,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr) return sum[id];
    down(id,l,r);
    int mid = (l + r) >> 1; ll res = 0;
    if(ql <= mid) res += query(id << 1,l,mid,ql,qr);
    if(mid < qr) res += query(id << 1 | 1,mid + 1,r,ql,qr);
    return res;
  }
}sgt;
int main(){
  n = getint();
  for(int i = 1;i <= n;i++){
    sa[i] = getint(),ea[i] = getint(),sb[i] = getint(),eb[i] = getint();
    al.push_back(mp(sa[i],i));
    ar.push_back(mp(ea[i],i));
    bl.push_back(mp(sb[i],i));
    br.push_back(mp(eb[i],i));
    ps.push_back(sa[i]);
    ps.push_back(sb[i]);
    ps.push_back(ea[i]);
    ps.push_back(eb[i]);
  }
  sort(ps.begin(),ps.end());
  ps.erase(unique(ps.begin(),ps.end()),ps.end());
  rb = ps.size();
  for(int i = 1;i <= n;i++){
    sa[i] = lower_bound(ps.begin(),ps.end(),sa[i]) - ps.begin() + 1;
    ea[i] = lower_bound(ps.begin(),ps.end(),ea[i]) - ps.begin() + 1;
    sb[i] = lower_bound(ps.begin(),ps.end(),sb[i]) - ps.begin() + 1;
    eb[i] = lower_bound(ps.begin(),ps.end(),eb[i]) - ps.begin() + 1;
  }
  sort(al.begin(),al.end());
  sort(ar.begin(),ar.end());
  sgt.clear();
  int j = 0;
  for(int i = 0;i < n;i++){
    while(j < n && ar[j].first < al[i].first){
      int id = ar[j].second;
      sgt._plus(1,1,rb,sb[id],eb[id],1);
      j++;
    }
    int id = al[i].second;
    if(sgt.query(1,1,rb,sb[id],eb[id])){
      puts("NO");
      return 0;
    }
  }
  j = n - 1;
  sgt.clear();
  for(int i = n - 1;i >= 0;i--){
    while(j >= 0 && al[j].first > ar[i].first){
      int id = al[j].second;
      sgt._plus(1,1,rb,sb[id],eb[id],1);
      j--;
    }
    int id = ar[i].second;
    if(sgt.query(1,1,rb,sb[id],eb[id])){
      puts("NO");
      return 0;
    }
  }
  sort(bl.begin(),bl.end());
  sort(br.begin(),br.end());
  sgt.clear();
  j = 0;
  for(int i = 0;i < n;i++){
    while(j < n && br[j].first < bl[i].first){
      int id = br[j].second;
      sgt._plus(1,1,rb,sa[id],ea[id],1);
      j++;
    }
    int id = bl[i].second;
    if(sgt.query(1,1,rb,sa[id],ea[id])){
      puts("NO");
      return 0;
    }
  }
  sgt.clear();
  j = n - 1;
  for(int i = n - 1;i >= 0;i--){
    while(j >= 0 && bl[j].first > br[i].first){
      int id = bl[j].second;
      sgt._plus(1,1,rb,sa[id],ea[id],1);
      j--;
    }
    int id = br[i].second;
    if(sgt.query(1,1,rb,sa[id],ea[id])){
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}