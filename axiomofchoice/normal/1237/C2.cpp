#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define lowbit(x) (x&(-x))
struct node{
	int x,y,z,pos;
}a[50010];
vector<node> a2,a1;
bool fun(node a,node b){
	return a.x<b.x || (a.x==b.x? a.y<b.y || (a.y==b.y?a.z<b.z:0):0);
}
int n;
void caozuo2(int l,int r){
	while(l<r){
		cout<<a[l].pos+1<<' '<<a[l+1].pos+1<<endl;
		l+=2;
	}
	if(l==r){
		a2.push_back(a[l]);
	}
}
void caozuo(int l,int r){
	int j=l;
	a2.clear();
	repeat(i,l,r+1){
		if(i==r || a[i].y!=a[i+1].y){
			caozuo2(j,i),j=i+1;
		}
	}
	repeat(i,0,a2.size()/2)cout<<a2[i*2].pos+1<<' '<<a2[i*2+1].pos+1<<endl;
	if(a2.size()%2==1)a1.push_back(a2.back());
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	repeat(i,0,n){
		cin>>a[i].x>>a[i].y>>a[i].z;
		a[i].pos=i;
	}
	sort(a,a+n,fun);
	int j=0;
	a1.clear();
	repeat(i,0,n){
		if(i==n-1 || a[i].x!=a[i+1].x)
			caozuo(j,i),j=i+1;
	}
	repeat(i,0,a1.size()/2)
		cout<<a1[i*2].pos+1<<' '<<a1[i*2+1].pos+1<<endl;
	return 0;
}