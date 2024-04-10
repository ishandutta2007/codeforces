#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
Int n,m;
Int st[55][55];
void show(){
  return;
  for(Int i=1;i<=n;i++){
    for(Int j=1;j<=n;j++) cout<<st[i][j];
    cout<<endl;
  }
  cout<<endl;
}
using P = pair<Int, Int>;
vector<P> from,to;
void move(Int fy,Int fx,Int ty,Int tx){
  st[ty][tx]=st[fy][fx];st[fy][fx]=0;
  from.push_back(P(fy,fx));
  to.push_back(P(ty,tx));
}

signed main(){
  from.clear();to.clear();
  
  cin>>n>>m;
  if(n==1){
    cout<<0<<endl;
    return 0;
  }
  vector<Int> x(m),y(m),p(m),q(m);
  for(Int i=0;i<m;i++) cin>>y[i]>>x[i];
  for(Int i=0;i<m;i++) cin>>q[i]>>p[i];

  memset(st,0,sizeof(st));
  for(Int i=0;i<m;i++) st[y[i]][x[i]]=i+1;
  show();
  
  vector<Int> ord(m);
  iota(ord.begin(),ord.end(),0);
  
  auto comp1=[&](Int i,Int j)->bool{
	       if(i==j) return false;
	       if(y[i]!=y[j]) return y[i]<y[j];
	       if(y[i]==1) return x[i]<x[j];
	       return x[i]>x[j];
	     };
  
  sort(ord.begin(),ord.end(),comp1);
  //for(Int i=0;i<m;i++) cout<<i<<"*"<<ord[i]<<endl;
  for(Int i=0;i<m;i++){
    Int j=ord[i];
    
    if(y[j]==1){
      while(x[j]>1&&!st[y[j]][x[j]-1]){
	move(y[j],x[j],y[j],x[j]-1);
	x[j]--;
      }
    }else{
      while(x[j]<n){
	move(y[j],x[j],y[j],x[j]+1);
	x[j]++;
      }
      while(y[j]>1){
	move(y[j],x[j],y[j]-1,x[j]);
	y[j]--;
      }
      while(x[j]>1&&!st[y[j]][x[j]-1]){
	move(y[j],x[j],y[j],x[j]-1);
	x[j]--;
      }
    }
    //show();
  }
  show();
  
  auto comp2=[&](Int i,Int j)->bool{
	       if(i==j) return false;
	       if(q[i]!=q[j]) return q[i]>q[j];	       
	       if(q[i]<=2) return p[i]<p[j];
	       return p[i]>p[j];
	     };

  auto calc=
    [&](){
      for(int k=n;k>=1;k--){
	int j=st[1][k]-1;
	if(j<0) continue;
	while(x[j]<n&&!st[y[j]][x[j]+1]){
	  move(y[j],x[j],y[j],x[j]+1);
	  x[j]++;
	}
      }      
    };
  sort(ord.begin(),ord.end(),comp2);
  
  for(Int i=0;i<m;i++){
    Int j=ord[i];
    if(q[j]<=2){
      calc();
      move(y[j],x[j],y[j]+1,x[j]);
      y[j]++;
      while(x[j]>1&&!st[y[j]][x[j]-1]){
	move(y[j],x[j],y[j],x[j]-1);
	x[j]--;
      }
      calc();      
    }else{
    
      move(y[j],x[j],y[j]+1,x[j]);
      y[j]++;

      while(x[j]>1){
	move(y[j],x[j],y[j],x[j]-1);
	x[j]--;
      }
    
      while(y[j]<q[j]){
	move(y[j],x[j],y[j]+1,x[j]);
	y[j]++;
      }
    
      while(x[j]<p[j]){
	move(y[j],x[j],y[j],x[j]+1);
	x[j]++;
      }
    }
    //show();
  }
  
  show();

  for(Int i=0;i<m;i++){    
    Int j=ord[i];
    if(q[j]==1){
      move(y[j],x[j],y[j]-1,x[j]);
      y[j]--;
      while(x[j]>1&&!st[y[j]][x[j]-1]){
	move(y[j],x[j],y[j],x[j]-1);
	x[j]--;
      }
    }
  }
  show();
  
  for(Int i=m-1;i>=0;i--){      
    Int j=ord[i];
    while(x[j]<p[j]){
      move(y[j],x[j],y[j],x[j]+1);
      x[j]++;
    }
  }
  show();
  
  
  cout<<from.size()<<endl;
  for(Int i=0;i<(Int)from.size();i++){
    cout<<from[i].first<<" "<<from[i].second<<" ";
    cout<<to[i].first<<" "<<to[i].second<<endl;
  }
  return 0;
}