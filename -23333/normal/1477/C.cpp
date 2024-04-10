#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
#define me(x) memset(x,0,sizeof(x))
#define IL inline
#define rint register int
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
const int N=6000;
int a[N],b[N],p[N],c[5],f[5],o[100];
int js(int x,int y,int z)
{
	ll a1=a[x]-a[y],b1=b[x]-b[y];
	ll a2=a[z]-a[y],b2=b[z]-b[y];
	if (a1*a2+b1*b2>0) return 1; else return 0;
}
int main()
{
   ios::sync_with_stdio(false);
   int n;
   cin>>n;
   rep(i,1,n)
   {
   	 cin>>a[i]>>b[i];
   }
   p[1]=1; p[2]=2;
   rep(i,3,n)
   {
   	 p[i]=i;
   	 if (!js(p[i-2],p[i-1],p[i])) 
   	 {
   	 	f[1]=p[i-2],f[2]=p[i-1],f[3]=p[i];
   	 	c[1]=1; c[2]=2; c[3]=3;
   	 	int tf=1;
   	 	do{
   	 		bool tt=1;
   	 		if (i>3)
   	 		  if (!js(p[i-3],f[c[1]],f[c[2]])) tt=0;
   	 		if (i>4)
   	 		  if (!js(p[i-4],p[i-3],f[c[1]])) tt=0;
   	 		if (!js(f[c[1]],f[c[2]],f[c[3]])) tt=0;
   	 		if (tt)
   	 		{
   	 			tf=0;
   	 			p[i-2]=f[c[1]],p[i-1]=f[c[2]],p[i]=f[c[3]];
   	 			break;
   	 		}
   	 	}while(next_permutation(c+1,c+3+1));
   	 	if (tf)
   	 	{
   	 		f[1]=p[i-3],f[2]=p[i-2],f[3]=p[i-1],f[4]=p[i];
   	 	    c[1]=1; c[2]=2; c[3]=3; c[4]=4;
   	 	    do{
   	 	    	int h=max(i-5,1);
   	 	    	rep(j,h,i) if (j<i-3) o[j-h+1]=p[j]; else o[j-h+1]=f[c[4-(i-j)]];
                bool tt=1;
   	 	    	rep(j,3,i-h+1) if (!js(o[j-2],o[j-1],o[j])) tt=0;
   	 		    if (tt)
   	 		    {
   	 			  tf=0;
   	 			  p[i-3]=f[c[1]]; p[i-2]=f[c[2]],p[i-1]=f[c[3]],p[i]=f[c[4]];
   	 			  break;
   	 		     }
   	 	      }while(next_permutation(c+1,c+4+1));
   	 	}
   	 	if (tf) cout<<"bug"<<endl;
   	 }
   }
   rep(i,1,n) cout<<p[i]<<" ";
   cout<<endl;
   rep(i,3,n) if (!js(p[i-2],p[i-1],p[i])) cout<<i<<endl; 
   return 0;
}