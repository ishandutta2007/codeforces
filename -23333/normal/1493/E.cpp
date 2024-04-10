#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
#define me(x) memset(x,0,sizeof(x))
#define IL inline
#define rint register int
inline ll rd(){
	ll x=0;char c=getchar();bool f=0;
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f?-x:x;
}
char ss[1<<24],*A=ss,*B=ss;
IL char gc()
{
	return A==B&&(B=(A=ss)+fread(ss,1,1<<24,stdin),A==B)?EOF:*A++;
}
template<class T>void read(T &x)
{
	int f=1,c; while (c=gc(),c<48||c>57) if (c=='-') f=-1; x=(c^48);
	while(c=gc(),c>47&&c<58) x=x*10+(c^48); x*=f;
}
const int mo=1e9+7;
struct re{
	int a,b,c;
};
const int N=2e6;
char s1[N],s2[N],s3[N];
int main()
{
   ios::sync_with_stdio(false);
   int n;
   cin>>n;
   cin>>(s1+1)>>(s2+1);
   bool tt=0;
   rep(i,1,n) if (s1[i]!=s2[i]) tt=1;
   rep(i,1,n) s3[i]=s2[i];
   if (!tt)
   {
   	 rep(i,1,n) cout<<s1[i];
   	 return 0;
   }
   int j=n+1,k;
   rep(i,1,n)
   {
   	 if (s1[i]!=s2[i])  {j=i; break;}
   }
   if (j==1)
   {
   	 rep(i,1,n) cout<<1;
	 cout<<endl;
	 return 0; 
   }
    int i=n;
    while (s2[i]=='0') --i;
    s2[i]='0';
    rep(j,i+1,n) s2[j]='1';
    tt=0;
    rep(i,1,n) if (s1[i]!=s2[i]) tt=1;
    if (!tt)
    {
    	rep(i,1,n) cout<<s3[i];
    	return 0;
    }
    s3[n]='1';
   rep(i,1,n) cout<<s3[i];
   return 0;
}