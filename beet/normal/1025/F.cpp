#include<bits/stdc++.h>
using namespace std;
using Int = long long;

struct Point{
  Int x,y;
  Point(){}
  Point(Int x,Int y) :x(x),y(y){}
  Point operator+(Point p) {return Point(x+p.x,y+p.y);}
  Point operator-(Point p) {return Point(x-p.x,y-p.y);}

  bool operator == (const Point &p) const{
    return x==p.x && y==p.y;
  }
};

istream &operator >> (istream &is,Point &p){
  is>>p.x>>p.y;
  return is;
}

typedef Point Vector;
typedef vector<Point> Polygon;

Int dot(Vector a,Vector b){
  return a.x*b.x+a.y*b.y;
}

Int cross(Vector a,Vector b){
  return a.x*b.y-a.y*b.x;
}

//INSERT ABOVE HERE
Int calc(Int c,Int d){
  return c*(c-1)*d*(d-1)/4;
}

signed solve(Int n,Polygon p){
  Int ans=0;
  for(Int i=0;i<n;i++){
    for(Int j=0;j<i;j++){
      Int c=0;      
      Vector u=p[j]-p[i];
      for(Int k=0;k<n;k++){
	if(i==k||j==k) continue;
	Vector v=p[k]-p[i];
	if(cross(u,v)>0) c++;
      }
      Int d=n-2-c;
      ans+=calc(c,d);
    }
  }
  cout<<ans<<endl;
  return 0;
}

signed main(){
  Int n;
  cin>>n;
  Polygon p(n);
  for(Int i=0;i<n;i++) cin>>p[i];

  if(n<=200){
    return solve(n,p);
  }
  
  auto comp=
    [&](Point a,Point b)->bool{
      if(a==b) return false;
      
      if(a.y*b.y<0) return a.y<0;
      if(a.y*b.y>0) return cross(a,b)>0;
      
      if(a.y==0&&a.x<0) return true;
      if(a.y==0&&a.x>0) return b.y>0;
      
      if(b.y==0&&b.x<0) return false;
      if(b.y==0&&b.x>0) return a.y<0;

      assert(0);
      return false;
    };
  
  Int ans=0;
  for(Int i=0;i<n;i++){
    Polygon w;
    for(Int j=0;j<n;j++){
      if(i==j) continue;
      w.push_back(p[j]-p[i]);
    }
    sort(w.begin(),w.end(),comp);
    for(Int j=0;j<n-1;j++) w.push_back(Point(w[j]));
    
    for(Int j=0,k=0;j<n-1;j++){
      while(k<j+(n-1)){	
	if(cross(w[j],w[k])>=0) k++;
	else break;
      }      
      Int c=k-j-1;
      //cout<<i<<" "<<j<<" "<<k<<":"<<c<<" "<<n-2-c<<endl;
      ans+=calc(c,n-2-c);
    }
  }
  
  cout<<ans/2<<endl;
  return 0;
}