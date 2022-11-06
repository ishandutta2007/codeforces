    #include<bits/stdc++.h>
    using namespace std;
    const int N=3005,P=998244353;
    int n,c,a[N];
    namespace sol1
    {
    	int f[N][N];
    	inline void sol()
    	{
    		int nn=(1<<c)-1;f[0][0]=1;
    		for(int i=1;i<=n;++i)for(int j=n/c;~j;--j)for(int k=nn-1;~k;--k)if(f[j][k])
    		{
    			if((k|1<<a[i])==nn)f[j+1][0]=(f[j+1][0]+f[j][k])%P;
    			else f[j][k|1<<a[i]]=(f[j][k|1<<a[i]]+f[j][k])%P;
    		}
    		for(int i=0;i<=n;++i)
    		{
    			int ans=i?0:P-1;
    			for(int j=0;j<nn;++j)ans=(ans+f[i][j])%P;
    			printf("%d ",ans);
    		}
    	}
    }
    namespace sol2
    {
    	int w[N],iv[N],s[N][N],f[N][N],ans[N];
    	inline int pw(int a,int s){int r=1;for(;s;s>>=1,a=1ll*a*a%P)if(s&1)r=1ll*r*a%P;return r;}
    	void sol()
    	{
    		for(int i=1;i<=n;++i){for(int j=0;j<c;++j)s[i][j]=s[i-1][j];s[i][a[i]]++;}
    		for(int i=1;i<=n;++i)w[i]=pw(2,i)-1,iv[i]=pw(w[i],P-2);
    		f[0][0]=1;
    		for(int i=0;i<=n;++i)
    		{
    			int cc=0,res=1,tt=w[n-i]+1;
    			for(int j=i+1;j<=n;++j)
    			{
    				int d=s[j][a[j]]-s[i][a[j]];
    				if(d>1)res=1ll*res*w[d]%P*iv[d-1]%P;else cc++;
    				if(cc==c)
    				{
    					res=1ll*res*iv[d]%P;tt=(tt+1ll*(P-res)*(w[n-j]+1))%P;
    					for(int k=i/c;~k;--k)f[j][k+1]=(f[j][k+1]+1ll*f[i][k]*res)%P;
    					res=1ll*res*w[d]%P;
    				}
    			}
    			for(int j=i/c;~j;--j)ans[j]=(ans[j]+1ll*f[i][j]*tt)%P;
    		}
    		ans[0]=(ans[0]+P-1)%P;
    		for(int i=0;i<=n;++i)printf("%d ",ans[i]);
    	}
    }
    int main()
    {
    	scanf("%d%d",&n,&c);
    	for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]--;
    	c<=11?sol1::sol():sol2::sol();return 0;
    }