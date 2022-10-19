#include<cstdio>
#include<algorithm>
using namespace std;
int ax,ay,mx,my,mt;
struct aaa
{
	int x,y;
}a[4],b[4];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch;do ch=getchar(),f|=(ch=='-');while(ch<'0' || ch>'9');
	do x=(x<<3)+(x<<1)+(ch^48),ch=getchar();while(ch>='0' && ch<='9');
	x=f? -x:x;
}
inline bool cmp(aaa a,aaa b)
{
	return (a.y==b.y)? (a.x<b.x):(a.y<b.y);
}
inline int abs(int x)
{
	return x>0? x:-x;
}
int main()
{
	for(int i=0;i<4;++i)read(a[i].x),read(a[i].y);
	for(int i=0;i<4;++i)read(b[i].x),read(b[i].y);
	sort(a,a+4,cmp),sort(b,b+4,cmp),mx=((b[1].x+b[2].x)>>1),my=b[1].y,mt=abs(b[0].x-mx)+abs(b[0].y-my);
	if(a[0].x<=mx && mx<=a[3].x)ax=mx;else if(a[0].x>mx)ax=a[0].x;else ax=a[3].x;
	if(a[0].y<=my && my<=a[3].y)ay=my;else if(a[0].y>my)ay=a[0].y;else ay=a[3].y;
	return 0&puts((abs(ax-mx)+abs(ay-my)<=mt)? "YES":"NO");
}