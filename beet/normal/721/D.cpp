#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(){
  ll n,k,x,m=0,i,j,y=0,f=0;
  cin>>n>>k>>x;
  ll a[n];
  for(i=0;i<n;i++){
    cin>>a[i];
    if(a[i]==0) f++;
    if(a[i]<0) m++;
    if(abs(a[i])<abs(a[y])) y=i;
  }

  if(f==0){
    if(m%2==0){
      if(a[y]<0){
	j=(-a[y])/x+1;
	j=min(k,j);
	a[y]+=x*j;
	k-=j;
      }else{
	j=a[y]/x+1;
	j=min(k,j);
	a[y]-=x*j;
	k-=j;
      }
    }
  }else{
    if(f<=k){
      bool z=true;
      for(i=0;i<n;i++){
	if(a[i]==0){
	  a[i]+=x;
	  f--;k--;
	  if(z&&m%2==0) a[i]*=-1,z=false;
	}
      }
    }
  }
  priority_queue<P,vector<P>,greater<P> > q;
  for(i=0;i<n;i++) q.push(P(abs(a[i]),i));
  for(j=0;j<k;j++){
    i=q.top().second;q.pop();
    if(a[i]<0) a[i]-=x;
    else a[i]+=x;
    q.push(P(abs(a[i]),i));
  }
  for(i=0;i<n;i++) cout << a[i] << (i+1==n?'\n':' ');
  return 0;
}