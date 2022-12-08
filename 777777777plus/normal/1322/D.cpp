    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    const int N = 4e3+5;
    const int M = 14;
     
    int n,m;
    int a[N],s[N],c[N];
    int f[N][N],cnt[N],tot[N];
    int ans;
     
    int main(){
    	cin>>n>>m;
    	for(int i=1;i<=n;++i)cin>>a[i];
    	for(int i=1;i<=n;++i)cin>>s[i];
    	for(int i=1;i<=n+m;++i)cin>>c[i];
    	reverse(a+1,a+n+1);
    	reverse(s+1,s+n+1);
    	int top=0;
    	for(int i=0;i<N;++i)memset(f[i],-0x3f,sizeof(f[i]));
    	for(int i=0;i<N;++i)f[i][0]=0;
    	for(int i=1;i<=n;++i){
    		for(int j=cnt[a[i]];~j;--j)
    		if(f[i][j]!=-0x3f3f3f3f){
    			f[a[i]][j+1]=max(f[a[i]][j+1],f[a[i]][j]+c[a[i]]-s[i]);
    		}
    		cnt[a[i]]++;
    		tot[a[i]]++;
    		for(int j=a[i];j<N-1;++j){
        		for(int k=(cnt[a[i]]>>min(j-a[i],20));~k;--k)
        		if(f[j][k]!=-0x3f3f3f3f){
        			f[j+1][k>>1]=max(f[j+1][k>>1],f[j][k]+(k>>1)*c[j+1]);
        		}
        		cnt[j+1]=cnt[j]/2+tot[j+1];
    		}
    	}
    	cout<<*max_element(f[N-1],f[N-1]+N)<<endl;
    }