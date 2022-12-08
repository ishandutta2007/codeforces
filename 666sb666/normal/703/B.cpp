#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string> 
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
#define GC getchar()
#define PC putchar
inline void read(int&n)
{int x=0,f=1;char ch=GC;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=GC;}while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=GC;n=x*f;}
int outputarray[20];
inline void write(int k)
{int num=0;if(k<0)PC('-'),k=-k;do{outputarray[++num]=k%10,k/=10;}while(k);while(num)PC(outputarray[num--]+'0');puts("");}
/*-----------------------------------------------------header file----------------------------------------------------------------*/
const int maxn=100001;
int n,k,c[maxn],d[maxn],sum[maxn],s[maxn];
bool is[maxn];
struct int32768
{
	static const int bn=1e4;
	static const int wi=4;
	vector<int>s;
	int32768(long long num=0)
	{
		*this=num;
	}
	int32768 operator =(long long num)
	{
		s.clear();
		do
		{
			s.push_back(num%bn);
			num/=bn;
		}while(num);
		return *this;
	}
	int32768 operator =(const string&str)
	{
		s.clear();
		int x,len=(str.length()-1)/wi+1;
		for(int i=0;i<len;i++)
		{
			int end=str.length()-i*wi,start=max(0,end-wi);
			sscanf(str.substr(start,end-start).c_str(),"%d",&x);
			s.push_back(x);
		}
		return *this;
	}
	int32768 operator +(const int32768&b)const
	{
		int32768 c;
		c.s.clear();
		for(int i=0,g=0;;i++)
		{
			if(!g&&i>=s.size()&&i>=b.s.size())break;
			int x=g;
			if(i<s.size())x+=s[i];
			if(i<b.s.size())x+=b.s[i];
			c.s.push_back(x%bn);
			g=x/bn;
		}
		return c;
	}
	int32768 operator +=(const int32768&b)
	{
		*this=*this+b;
		return *this;
	}
	int32768 operator *(const int32768&b)const
	{
		int32768 c;
		c.s.clear();
		for(int i=0;i<s.size();i++)
		{
			int x=0;
			for(int j=0;j<b.s.size();j++)
			{
				if(c.s.size()<i+j+1)c.s.push_back(0);
				c.s[i+j]+=s[i]*b.s[j]+x;
				x=c.s[i+j]/bn;
				c.s[i+j]%=bn;
			}
			int p=s.size()-1,q=b.s.size()-1;
			if(x)
				if(c.s.size()<=p+q+1)c.s.push_back(x);
				else c.s[p+q+1]+=x;
		}
		return c;
	}
	int32768 operator *=(const int32768&b)
	{
		*this=*this*b;
		return *this;
	}
	int32768 operator /(const int&b)const
	{
		int32768 c;
		int a[s.size()];
		c.s.clear();
		int x=0;
		for(int i=s.size()-1;i>=0;i--)
		{
			a[s.size()-i-1]=((s[i]+x*bn)/b);
			x=(s[i]+x*bn)%b;
		}
		for(int i=0;i<s.size();i++)c.s.push_back(a[s.size()-i-1]);
		return c;
	}
	int32768 operator /=(const int&b)
	{
		*this=*this/b;
		return *this;
	}
	bool operator <(const int32768&b)const
	{
		if(s.size()!=b.s.size())return s.size()<b.s.size();
		for(int i=s.size()-1;i>=0;i--)if(s[i]!=b.s[i])return s[i]<b.s[i];
		return false;
	}
	bool operator >(const int32768&b)const
	{
		return b<*this;
	}
	bool operator <=(const int32768&b)const
	{
		return !(b<*this);
	}
	bool operator >=(const int32768&b)const
	{
		return !(*this<b);
	}
	bool operator !=(const int32768&b)const
	{
		return b<*this||*this<b;
	}
	bool operator ==(const int32768&b)const
	{
		return !(b<*this)&&!(*this<b);
	}
};
ostream&operator <<(ostream&out,const int32768&x)
{
	if(x.s.back())out<<x.s.back();
	for(int i=x.s.size()-2;i>=0;i--)
	{
		char ch[20];
		sprintf(ch,"%04d",x.s[i]);
		for(int j=0;j<strlen(ch);j++)out<<ch[j];
	}
	return out;
}
istream&operator >>(istream&in,int32768&x)
{
	string s;
	if(!(in>>s))return in;
	x=s;
	return in;
}
inline int binary(int x)
{
	int l=0,r=k+1,mid;
	while(l<r)
	{
		mid=(l+r+1)>>1;
		if(d[mid]<=x)l=mid;
		else r=mid-1;
	}
	return l;
}
int main()
{
	memset(is,0,sizeof(is));
	read(n),read(k);
	for(int i=1;i<=n;i++)read(c[i]);
	for(int i=1;i<=k;i++)read(d[i]),is[d[i]]=1;
	sort(d+1,d+k+1);
	sum[1]=c[d[1]];
	for(int i=2;i<=k;i++)sum[i]=sum[i-1]+c[d[i]];
	s[1]=c[1];
	for(int i=2;i<=n;i++)s[i]=s[i-1]+c[i];
	int32768 ans=0;
	for(int i=1;i<=n;i++)
	if(!is[i])
	{
		int j=binary(i);
		if(j>k)continue;
		int32768 a=c[i],b=sum[k]-sum[j];
		ans+=a*b;
	}
	else
	{
		int32768 j=s[n]-s[i],a=c[i];
		ans+=j*a;
	}
	for(int i=1;i<n;i++)if(is[i]==false&&is[i+1]==false)ans+=(int32768)c[i]*c[i+1];
	if(is[1]==false&&is[n]==false)ans+=(int32768)c[1]*c[n];
	cout<<ans<<endl;
	return 0;
}