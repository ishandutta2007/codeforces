//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
//#pragma GCC optimize("Ofast")
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
const int N=5e5;
int a[N],n;
char c[N];

   	 string s1,s2;
int main()
{
   ios::sync_with_stdio(false);
   int T;
   cin>>T;
   while (T--)
   {
   	 int a1=0,a2=0,z1=0;
     cin>>n;
   	 cin>>(c+1);
   	 int cnt=0;
   	 rep(i,1,n) if (c[i]=='1') cnt++;
   	 if (cnt%2==1)
   	 {
   	 	cout<<"NO"<<endl;
   	 	continue;
   	 }
   	 s1=s2="";
   	 int cnt2=0;
   	 int tt=0;
   	 rep(i,1,n)
   	 {
   	 	if (c[i]=='1')
   	 	  if (z1!=cnt/2) s1+='(',s2+='(',z1++,a1++,a2++;
   	 	  else s1+=')',s2+=')',a1--,a2--;
   	 	else
   	 	  {
   	 	  	cnt2^=1;
   	 	  	if (cnt2) s1+='(',s2+=')',a1++,a2--;
   	 	  	else s1+=')',s2+='(',a1--,a2++;
   	 	  }
   	 	if (a1<0||a2<0)
		{ 
			  tt=-1;
			  break;
			}
   	 }
   	 if (tt==-1)
   	 {
   	 	cout<<"NO"<<endl; 
   	 } else
   	 {
   	 	cout<<"YES"<<endl;
  	 	cout<<s1<<endl;
   	 	cout<<s2<<endl;
   	 }
   }
   return 0;
}