#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX_N = 1 << 22;
int bit[MAX_N+1],n;
//1-indexed
int sum(int i){
  int s=0;
  while(i>0){
    s+=bit[i];
    i-=i&-i;
  }
  return s;
}
void add(int i,int x){
  while(i<=2*n){
    bit[i]+=x;
    i+=i&-i;
  }
}
signed main(){
  memset(bit,0,sizeof(bit));
  int k;
  cin>>n>>k;
  k=min(k,n-k);
  int c=1,p=1;
  for(int i=0;i<n;i++){
    c+=sum(p+k-1)-sum(p)+1;
    add(p,1);
    add(p+n,1);
    p+=k;
    if(p>n) p-=n;
    add(p,1);
    add(p+n,1);
    //cout<<p<<" "<<sum(p)<<" "<<p+n<<" "<<sum(p+n)<<" "<<c<<endl;
    cout<<c<<" \n"[i==n-1];
  }
  return 0;
}