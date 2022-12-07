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
int n,m,k,a[100005],ans=1;
vector<int>vec;
int main() {
	read(n),read(m),read(k);
	for(int i=1;i<=n;++i) {
		read(a[i]);
		if(i>1)
			vec.push_back(a[i]-a[i-1]-1),ans+=a[i]-a[i-1];
	}
	sort(vec.begin(),vec.end(),greater<int>());
	for(int i=0;i<k-1;++i)
		ans-=vec[i];
	printf("%d\n",ans); 
}