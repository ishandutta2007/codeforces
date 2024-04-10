#include<bits/stdc++.h>
using namespace std;
int n;
typedef long long ll;
struct Vector{
	int x,y;
	Vector(int X=0,int Y=0){x=X,y=Y;}
	friend Vector operator +(const Vector &u,const Vector &v){return Vector(u.x+v.x,u.y+v.y);}
	friend Vector operator -(const Vector &u,const Vector &v){return Vector(u.x-v.x,u.y-v.y);}
	friend Vector operator *(const Vector &u,const int &v){return Vector(u.x*v,u.y*v);}
	friend Vector operator /(const Vector &u,const int &v){return Vector(u.x/v,u.y/v);}
	friend ll operator &(const Vector &u,const Vector &v){return 1ll*u.x*v.y-1ll*u.y*v.x;}//cross times
	friend ll operator |(const Vector &u,const Vector &v){return 1ll*u.x*v.x+1ll*u.y*v.y;}//point times
	friend bool operator <(const Vector &u,const Vector &v){return u.x==v.x?u.y<v.y:u.x<v.x;}
	friend bool operator ==(const Vector &u,const Vector &v){return u.x==v.x&&u.y==v.y;}
	void read(){scanf("%d%d",&x,&y);}
	void print()const{printf("(%d,%d)",x,y);}
}tmp;
typedef set<Vector>::iterator svi;
set<Vector>lower,upper;
void InsertLower(Vector ip){
	svi it=lower.lower_bound(ip),i,j;
	if(it!=lower.end()&&it!=lower.begin()){
		i=it,j=it;j--;
		if(((*i-ip)&(ip-*j))>=0)return;
	}
	i=it,j=it;
	bool out=(it!=lower.begin());
	if(it!=lower.begin())it--;
	if(i!=lower.end()){
		j++;
		while(j!=lower.end()){
			if(((*j-*i)&(*i-ip))<0)break;
			lower.erase(i),i=j,j++;
		}
	}
	if(out&&it!=lower.begin()){
		i=it,j=it;j--;
		while(true){
			if(((ip-*i)&(*i-*j))<0)break;
			lower.erase(i);
			if(j==lower.begin())break;
			i=j,j--;
		}
	}
	lower.insert(ip);
}
void InsertUpper(Vector ip){
	svi it=upper.lower_bound(ip),i,j;
	if(it!=upper.end()&&it!=upper.begin()){
		i=it,j=it;j--;
		if(((*j-ip)&(ip-*i))>=0)return;
	}
	i=it,j=it;
	bool out=(it!=upper.begin());
	if(it!=upper.begin())it--;
	if(i!=upper.end()){
		j++;
		while(j!=upper.end()){
			if(((ip-*i)&(*i-*j))<0)break;
			upper.erase(i),i=j,j++;
		}
	}
	if(out&&it!=upper.begin()){
		i=it,j=it;j--;
		while(true){
			if(((*j-*i)&(*i-ip))<0)break;
			upper.erase(i);
			if(j==upper.begin())break;
			i=j,j--;
		}
	}
	upper.insert(ip);
}
bool inside(Vector ip){
	svi it=lower.lower_bound(ip),i,j;
	if(it==lower.end())return false;
	if(*it==ip)return true;
	if(it==lower.begin())return false;
	i=it,j=it;j--;
	if(((*i-ip)&(ip-*j))<0)return false;
	
	it=upper.lower_bound(ip);
	if(it==upper.end())return false;
	if(*it==ip)return true;
	if(it==upper.begin())return false;
	i=it,j=it;j--;
	if(((*j-ip)&(ip-*i))<0)return false;
	
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x),tmp.read();
		if(x==1)InsertLower(tmp),InsertUpper(tmp);
		else puts(inside(tmp)?"YES":"NO");
//		for(auto x:lower)x.print();puts("");
//		for(auto x:upper)x.print();puts("");
//		puts("");
	}
	return 0;
}