#include<cstdio>
int a,b,c,d,x,y,x1,y1,x2,y2,_a,_c,_x,_y,Test_num;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int abs(int x)
{
	return x<0? -x:x;
}
int max(int x,int y)
{
	return x>y? x:y;
}
void swap(int &x,int &y)
{
	int z=x;x=y;y=z;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(a),read(b),read(c),read(d);
		read(x),read(y),read(x1),read(y1),read(x2),read(y2);
		if((x1==x2 && (a || b)) || (y1==y2 && (c || d)))
		{
			puts("No");
			continue;
		}
		if(a<b)swap(a,b),x1=2*x-x2;
		if(c<d)swap(c,d),y1=2*y-y2;
		_a=a-b,_c=c-d,_x=x-x1,_y=y-y1;
		if(_a<=_x && _c<=_y)puts("Yes");
		else puts("No");
	}
	return 0;
}