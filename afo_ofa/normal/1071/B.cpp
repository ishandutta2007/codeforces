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
int n,k,pre[2005][2005],f[2005][2005],p,vis[2005][2005];
char s[2005][2005];
const int step[2][2]={{0,1},{1,0}};
struct Node {
	int x,y;
	Node(int x=0,int y=0):x(x),y(y){}
	inline bool operator < (const Node &rhs) const {
		return s[x][y]<s[rhs.x][rhs.y];
	}
};
vector<Node>vec;
vector<char>ans;
inline void Print(int x,int y) {
	if(pre[x][y]==1)
		Print(x,y-1);
	if(pre[x][y]==2)
		Print(x-1,y);
	ans.push_back(s[x][y]);
}
int main() {
	read(n),read(k);
	for(int i=0;i<n;++i)
		scanf("%s",s[i]);
	memset(f,0x3f,sizeof f);
	f[0][0]=(s[0][0]!='a');
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j) {
			if(i&&j)
				f[i][j]=min(f[i][j],min(f[i-1][j],f[i][j-1]))+(s[i][j]!='a');
			else if(i)
				f[i][j]=min(f[i][j],f[i-1][j])+(s[i][j]!='a');
			else if(j)
				f[i][j]=min(f[i][j],f[i][j-1])+(s[i][j]!='a');
		}
//	for(int i=0;i<n;++i,puts(""))
//		for(int j=0;j<n;++j)
//			cout<<f[i][j]<<" ";
	
	if(f[n-1][n-1]<=k) {
		for(int i=1;i<2*n;++i)
			putchar('a');
		puts("");
		return 0;
	}
	int mx=-1;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			if(f[i][j]<=k)
				mx=max(mx,i+j),vis[i][j]=1;
	if(~mx) {
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				if(i+j==mx+1&&((i&&vis[i-1][j])||(j&&vis[i][j-1])))
					vec.push_back(Node(i,j));
	}
	else
		vec.push_back(Node(0,0));
	while(vec.size()) {
		sort(vec.begin(),vec.end());
		vector<Node>tmp;
		char beg=s[vec[0].x][vec[0].y];
		for(int i=0;i<(int)vec.size();++i) {
			int x=vec[i].x,y=vec[i].y;
//			cout<<"???"<<x<<" "<<y<<" "<<s[x][y]<<endl;
			if(s[x][y]!=beg)
				continue;
			for(int j=0;j<2;++j) {
				int nx=x+step[j][0],ny=y+step[j][1];
				if(nx>=0&&nx<n&&ny>=0&&ny<n)
					if(!pre[nx][ny])
						pre[nx][ny]=j+1,tmp.push_back(Node(nx,ny));
			}
		}
		vec.clear();
		for(int i=0;i<(int)tmp.size();++i)
			vec.push_back(tmp[i]);
	}
	Print(n-1,n-1);
	int lef=2*n-1-ans.size();
	for(int i=0;i<lef;++i)
		putchar('a');
	for(int i=0;i<(int)ans.size();++i)
		putchar(ans[i]);
	puts("");
}
/*
5 0
abaaa
ababa
ababa
ababa
aaaba
*/