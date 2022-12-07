#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
template<class T>inline void print(T x){if(x/10!=0)print(x/10);putchar(x%10+'0');}
template<class T>inline void writeln(T x){if(x<0)putchar('-');x=abs(x);print(x);putchar('\n');}
template<class T>inline void write(T x){if(x<0)putchar('-');x=abs(x);print(x);}
/*================Header Template==============*/
int T;
ll l,r,f[19][4];
vector<int>dig;
inline ll dfs(int pos,int cnt,bool up) {
//	cout<<pos<<" "<<dig.size()<<" "<<cnt<<" "<<up<<endl;
	if(cnt>3)
		return 0;
	if(pos==-1)
		return cnt<=3;
	if(~f[pos][cnt]&&!up)
		return f[pos][cnt];
//	cout<<"???"<<endl;
	ll res=0;
	int ux=up?dig[pos]:9;
//	cout<<ux<<endl;
	for(int u=0;u<=ux;++u)
		res+=dfs(pos-1,cnt+(u>0),up&&u==ux);
//	cout<<"Now :"<<res<<endl;
	if(!up)
		f[pos][cnt]=res;
	return res;
}
inline ll calc(ll x) {
	dig.clear();
	while(x)
		dig.push_back(x%10),x/=10;
	memset(f,-1,sizeof f);
	return dfs(dig.size()-1,0,1);
}
int main() {
	read(T);
	while(T--)
		read(l),read(r),printf("%lld\n",calc(r)-calc(l-1));
}