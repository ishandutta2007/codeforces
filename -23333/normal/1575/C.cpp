#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=1e6+10;
const int mo=1e9+7;
int a[N];
ll sum1[N],sum2[N],g1[N],g2[N],g3[N],g4[N],g5[N],gg[N],gg2[N];
struct FFT{
  const double pi=acos(-1);
  struct cp{
      double x,y;
      cp operator +(const cp &o)const{return (cp){x+o.x,y+o.y};}
      cp operator -(const cp &o)const{return (cp){x-o.x,y-o.y};}
      cp operator *(const cp &o)const{return (cp){x*o.x-y*o.y,y*o.x+x*o.y};}
      cp operator *(const double &o)const{return (cp){x*o,y*o};}
      cp operator !()const{return (cp){x,-y};}
  }a[N],b[N],c[N],w[N];
  int l,r[N];
  int n,m;
  void fft_init()
  {
      l=0; for (n=1;n<=m;n<<=1) l++;
  }
  void fft_clear()
  {
      rep(i,0,n) a[i].x=a[i].y=b[i].x=b[i].y=0;
  }
  void fft(cp x[],int k,int v){
      for(int i=0,j=0;i<k;i++)
      {
          if(i>j)std::swap(x[i],x[j]);
          for(int l=k>>1;(j^=l)<l;l>>=1);
      }
      w[0]=(cp){1,0};
      for(int i=2;i<=k;i<<=1){
          cp g=(cp){cos(2*pi/i),(v?-1:1)*sin(2*pi/i)};
          for(int j=(i>>1);j>=0;j-=2)w[j]=w[j>>1];
          for(int j=1;j<i>>1;j+=2)w[j]=w[j-1]*g;
          for(int j=0;j<k;j+=i){
              cp *a=x+j,*b=a+(i>>1);
              for(int l=0;l<i>>1;l++){
                  cp o=b[l]*w[l];
                  b[l]=a[l]-o;
                  a[l]=a[l]+o;
              } 
        }
    }
    if(v)for(int i=0;i<k;i++)x[i]=(cp){x[i].x/k,x[i].y/k};
  }
  void get_cj(ll *A,ll *B,ll *C,int len)
  {
      rep(i,0,len) (i&1?a[i>>1].y:a[i>>1].x)=A[i];
      rep(i,0,len) (i&1?b[i>>1].y:b[i>>1].x)=B[i];
      m=len;
      fft_init();
      fft(a,n,0); fft(b,n,0);
      for(int i=0;i<n;i++){
        int j=(n-1)&(n-i);
        c[i]=(a[i]*b[i]*4-(a[i]-!a[j])*(b[i]-!b[j])*(((i&n>>1)?(cp){1,0}-w[i^n>>1]:w[i]+(cp){1,0})))*0.25;
      }
      fft(c,n,1);
      rep(i,0,2*len)
        if (i&1) C[i]=(ll)(c[i>>1].y+0.1);
        else C[i]=(ll)(c[i>>1].x+0.1);
      fft_clear();
  }
}F;
int f[N];
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	rep(i,1,n) cin>>a[i];
	gg[0]=1;
	ll tt=0;
	rep(i,1,n)
	{ 
	  sum1[i]=(sum1[i-1]+a[i])%k;
	  tt+=gg[sum1[i]];
	  gg[sum1[i]]++;
    }
	dep(i,n,1) sum2[i]=(sum2[i+1]+a[i])%k;
    rep(i,1,n-1)
	{ 
		sum1[i]=(sum1[i-1]+a[i])%k;
		tt+=gg2[((sum1[i]-sum1[n]*m)%k+k)%k];
		gg2[sum1[i]]++;
	}
    tt%=mo;
    tt=tt*m%mo;
    if (m==1)
    {
    	cout<<tt<<endl;
    	return 0;
    }
    rep(i,1,n-1) if (sum1[i]%k==0) tt-=m;
    dep(i,n,2) if (sum2[i]%k==0) tt-=m;
	rep(i,0,n-1) g1[sum1[i]]++;
	dep(i,n+1,2) g2[sum2[i]]++;
	memcpy(g4,g1,sizeof(g1));
	memcpy(g5,g2,sizeof(g2));
	F.get_cj(g1,g2,g3,k+3);
	rep(i,k,2*k-1) g3[i-k]+=g3[i];
	g3[0]--;
	rep(i,0,k-1) g3[i]%=mo;
//	rep(i,0,n-1)
//	  dep(j,n+1,2)
//	    if ((sum1[i]+sum2[j])%k==0) cout<<i<<" "<<j<<endl;
//	rep(i,0,k-1) cout<<f[i]<<" "<<g3[i]<<endl;
	//rep(i,0,k-1) cout<<g3[i]<<" ";
	ll ans=0;
	rep(i,0,m-2)
	{
		int t=sum1[n]*i%k;
		(ans+=g3[(k-t)%k]*m)%=mo;
		//cout<<ans<<endl;
    }
  //  cout<<ans<<endl;
    int t=sum1[n]*(m-1)%k;
    g4[0]--; g5[0]--;
    (ans+=g4[(k-t)%k]*m)%=mo;
    (ans+=g5[(k-t)%k]*m)%=mo;
    rep(i,2,m-1)
    {
    	if (sum1[n]*i%k==0) (ans+=m)%=mo;
    }
  //  cout<<ans<<endl;
    if (sum1[n]*m%k==0) ans++;
    ans+=tt;
    cout<<(ans%mo+mo)%mo<<endl;
	return 0;
}

/*
5 8 5
1 2 3 4 5
*/