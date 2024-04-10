// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
const int maxn=(1e5)+10;
const double eps=1e-10;
const double PIE=acos(-1.0);
int T,n;
int x[maxn],y[maxn],L,K;
double ans;
double dis(double a,double b,double c,double d) {
	return sqrt((a-c)*(a-c)+(d-b)*(d-b));
}
double X,Y;
vector<pair<double,int> > D;
void solve(vector<pair<double,double> > &v) {
	if ((int)v.size()==1) { ans=0; return; }
	if ((int)v.size()==2) {
		double tmp=dis(v[0].first,v[0].second,v[1].first,v[1].second)/2;
		if (tmp<ans) ans=tmp; return;
	}
	vector<pair<double,double> > V,V2;
	for (int i=0;i<v.size();i++) {
		pair<double,double> A=MP(v[i].first*X+v[i].second*Y,-v[i].first*Y+v[i].second*X);
	//	printf("%.5lf %.5lf %.5lf %.5lf\n",v[i].first,v[i].second,A.first,A.second);
		//printf("%.5lf %.5lf\n",dis(0,0,A.first,A.second),dis(0,0,v[i].first,v[i].second));
		assert(fabs(dis(0,0,A.first,A.second)-dis(0,0,v[i].first,v[i].second))<1e-6);
		V.push_back(A); V2.push_back(A);
	}
	sort(V2.begin(),V2.end());
	random_shuffle(V.begin(),V.end());
//	for (pair<double,double> &A : V) printf("%.5lf %.5lf\n",A.first,A.second);
int lst=0;
	for (pair<double,double> &A : V) {
		double x=A.first,y=A.second;
		double L=0,R=ans; bool st=0;
		//printf("lst=%d\n",lst);
		while ((R-L)/max(1.0,L)>eps) {
		//printf("%d %.15lf %.15lf %.15lf\n",lst,L,R,R-L);
			//if (lst==1) printf("%.15lf %.15lf %.15lf\n",L,R,R-L);
			double mid=(L+R)*0.5;
			if (L>1) mid=sqrt(L*R);
			else if (1>L&&R>1) mid=1;
			if (!st) st=1,mid=R;
			int l=lower_bound(V2.begin(),V2.end(),MP(x-mid*2-eps-1,0.0))-V2.begin();
			int r=upper_bound(V2.begin(),V2.end(),MP(x+mid*2+eps+1,0.0))-V2.begin()-1;
			int cnt=0,flag=0;
			if (r-l+1>=K) {
				D.clear();
			//	printf("mid=%.5lf\n",mid);
				/*if (fabs(mid-0.707106781)<eps) {
					printf("%d %d\n",x,y); puts("");
					for (auto B : V) printf("%.5lf %.5lf\n",B.first,B.second);
				}*/
				for (int i=l;i<=r;i++) {
					double d=dis(x,y,V2[i].first,V2[i].second);
					if (d<eps) { cnt++; continue; }
					if (d>mid*2) continue;
					double theta=atan2(V2[i].second-y,V2[i].first-x);
					double alpha=acos(d/2/mid);
					double l=theta-alpha,r=alpha+theta;
					if (l<0) l+=2*PIE; if (l>=2*PIE) l-=2*PIE;
					if (r<0) r+=2*PIE; if (r>=2*PIE) r-=2*PIE;
					if (l>r) cnt++;
					D.push_back(MP(l,1)),D.push_back(MP(r,-1));
					//if (fabs(mid-50625044.77123)<0.01) printf("?? %d %.5lf %.5lf\n",i,l,r);
				}
				sort(D.begin(),D.end());
				if (cnt>=K) flag=1;
				for (auto B : D) {
					if (flag) break;
					cnt+=B.second;
					if (cnt>=K) flag=1;
				}
			}
			if (flag) R=ans=mid;
			else L=mid;
		}
		lst++;
	}
}
int main() {
//	freopen("1.txt","r",stdin);
double theta=(rand()%10000)*1.0/10000*PIE;
X=cos(theta),Y=sin(theta);
	read(T); while (T--) {
		read(n); read(L); read(K);
		for (int i=1;i<=n;i++) read(x[i]),read(y[i]);
		set<pair<double,double> > s; ans=2e8;
		for (int i=1;i<=n;i++) {
			if (i-1>=L) s.erase(MP(x[i-L],y[i-L]));
			s.insert(MP(x[i],y[i]));
			set<pair<double,double> >::iterator it=s.lower_bound(MP(x[i]-ans*2-1,0));
			vector<pair<double,double> > V;
			while (it!=s.end()) {
				int a=(*it).first,b=(*it).second;
				if (a>x[i]+ans*2+1) break;
				if (dis(a,b,x[i],y[i])<=2*ans) V.push_back(MP(a,b));
				it++;
			}
			if ((int)V.size()>=K) solve(V);
		}
		printf("%.15lf\n",ans);
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/