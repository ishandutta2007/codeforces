#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define N 100010
#define mod 1000000007
//#define int ll
int x[N],y[N],z[N];
map<pii,int> m;
int n;
int f[N];
char s[N];
void work(int x,int y,int z){
	cout<<x<<' ';//gets(s);
	while(f[z]!=1){//cout<<endl<<x<<' '<<y<<' '<<z<<endl;
		int p=x;
		if(m.count({y,z}))p=m[{y,z}];//cout<<"p="<<p<<endl;
		if(p==x)p=m[{z,y}];//cout<<"m="<<m[{z,y}]<<' '<<m.count({z,y})<<endl;
		x=y,y=z,z=p;
		cout<<x<<' ';//gets(s);//getchar();
	}
	cout<<y<<' '<<z<<endl;
}
void add(int x,int y,int z){
	if(m.count({x,y}))m[{y,x}]=z;
	else m[{x,y}]=z;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	repeat(i,0,n-2){
		cin>>x[i]>>y[i]>>z[i];
		add(x[i],y[i],z[i]);
		add(x[i],z[i],y[i]);
		add(z[i],y[i],x[i]);
		f[x[i]]++;
		f[y[i]]++;
		f[z[i]]++;
	}
	//for(auto i:m){
		//cout<<i.first.first<<' '<<i.second<<' '<<i.first.second<<endl;
	//}
	int qi=0;
	while(f[qi]!=1)qi++;
	repeat(i,0,n-2)
	if(x[i]==qi || y[i]==qi || z[i]==qi){
		int qi2;
		if(f[x[i]]==2)qi2=x[i];
		else if(f[y[i]]==2)qi2=y[i];
		else qi2=z[i];
		//cout<<qi<<' '<<qi2;//return 0;
		work(qi,qi2,x[i]+y[i]+z[i]-qi-qi2);
		return 0;
	}
	return 0;
}