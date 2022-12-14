#include <bits/stdc++.h>
using namespace std;
#define lll __int128
typedef long long ll;
typedef pair<int,int> pii;
typedef double lf;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
const int N=510;
const int inf=1e9;
const int mod=1e9+7;
//#define int ll
int t,n,x,k;
int a[N],p[N],f[10];
void disc(int a[],int n){
	vector<int> m(a,a+n);
	sort(m.begin(),m.end());
	m.erase(unique(m.begin(),m.end()),m.end());
	repeat(i,0,n)
		a[i]=lower_bound(m.begin(),m.end(),a[i])-m.begin()+1;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k; n=k+1;
	repeat(i,0,n){
		cout<<"? ";
		repeat(j,0,n)if(i!=j)
			cout<<j+1<<" ";
		cout<<endl;
		cout.flush();
		cin>>p[i]>>a[i];
	}
	disc(a,n);
	repeat(i,0,n)f[a[i]]++;
	cout<<"! "<<f[2]<<endl;
	return 0;
}