#include<bits/stdc++.h>
using namespace std;
double eps=1e-7;
int n,m,A,B,a[6010];
int cmp(double x){
	if(x>eps)return 1;
	if(x<-eps)return -1;
	return 0;
}
struct line{
	double k,b;//a line of y=kx+b
	line(double _k,double _b){k=_k,b=_b;}
	line(double __x){k=2,b=-2*__x;}
	friend line operator+(const line&u,const line&v){return line(u.k+v.k,u.b+v.b);}
	void operator+=(const line&v){k+=v.k,b+=v.b;}
	void shift(double x){b-=k*x;}
	double f(double x){return k*x+b;}
	double rt(){return -b/k;}
};
vector<line>v;
vector<double>u;
void SHIFT(){
//	printf("[%lf,%lf]\n",v[0].f(u[0]),v.back().f(u.back()));
	int tur=-1;
	for(int i=0;i<v.size();i++)if(cmp(v[i].f(u[i+1]))!=-1&&cmp(v[i].f(u[i]))!=1)tur=i;
	if(tur==-1){
		if(cmp(v[0].f(u[0]))==1)tur=-1;
		if(cmp(v.back().f(u.back()))==-1)tur=v.size();
	}
	for(int i=0;i<v.size();i++){
//		printf("%d:%d,%d\n",i,u.size(),v.size());
		double x=v[i].rt();
		if(tur==-1&&i==0){
			x=u[0],tur++;
			u[i]+=A,u[i+1]+=B;
			v.insert(v.begin()+i,line(0,0));
			u.insert(u.begin()+i+1,x+B);
			v[i+1].shift(B);
			i+=1;
			continue;
		}
		if(tur==v.size()&&i==v.size()-1){
			x=u.back(),tur--;
			u[i]+=A,u[i+1]+=B;
			u.insert(u.begin()+i,x+A);
			v.insert(v.begin()+i,line(0,0));
			v[i].shift(A);
			i+=1;
			continue;
		}
		if(i<tur)u[i]+=A,v[i].shift(A);
		else if(i>tur)u[i+1]+=B,v[i].shift(B);
		else{
			u[i]+=A,u[i+1]+=B;
			u.insert(u.begin()+i+1,x+A);
			u.insert(u.begin()+i+2,x+B);
			v.insert(v.begin()+i+1,line(0,0));
			v.insert(v.begin()+i+2,v[i]);
			v[i].shift(A);
			v[i+2].shift(B);
			i+=2;
		}
	}
	int i=0;while(i<u.size()&&cmp(u[u.size()-i-1]-m)==1)i++;
//	for(auto i:u)printf("%lf ",i);puts("");
	u[u.size()-i]=m;u.erase(u.end()-i+1,u.end()),v.erase(v.end()-i+1,v.end());
//	for(int i=0;i<v.size();i++)printf("%.2lf[%.2lfx+%.2lf]",u[i],v[i].k,v[i].b);printf("%.2lf\n",u.back());
}
void ADD(line p){for(auto&i:v)i+=p;}
double pos(){
//	for(int i=0;i<v.size();i++)printf("<%.2lf,%.2lf>",v[i].f(u[i]),v[i].f(u[i+1]));puts("");
	if(cmp(v[0].f(u[0]))==1)return u[0];
	if(cmp(v.back().f(u.back()))==-1)return u.back();
//	printf("%d %d\n",u.size(),v.size());
	for(int i=0;i<v.size();i++)if(cmp(v[i].f(u[i+1]))!=-1&&cmp(v[i].f(u[i]))!=1)return v[i].rt();
	for(int i=1;i+1<u.size();i++)if(cmp(v[i-1].f(u[i]))==-1&&cmp(v[i].f(u[i]))==1)return u[i];
}
double b[6010],res;
int main(){
	scanf("%d%d%d%d",&n,&m,&A,&B);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	v.emplace_back(a[1]);
	u.push_back(1),u.push_back(m);
	for(int i=2;i<=n;i++)b[i-1]=pos(),SHIFT(),ADD(line(a[i]));
	b[n]=pos();
//	for(int i=1;i<=n;i++)printf("%lf ",b[i]);puts("");
	for(int i=n;i>=2;i--){
		if(cmp(max(b[i]-B,1.0)-b[i-1])==1)b[i-1]=max(b[i]-B,1.0);
		else if(cmp(b[i-1]-max(b[i]-A,1.0))==1)b[i-1]=max(b[i]-A,1.0);
	}
	for(int i=1;i<=n;i++)printf("%lf ",b[i]),res+=(b[i]-a[i])*(b[i]-a[i]);puts("");
//	for(int i=2;i<=n;i++)printf("%lf ",b[i]-b[i-1]);puts("");
	printf("%lf\n",res);
	return 0;
}