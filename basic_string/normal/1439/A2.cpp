    #include<bits/stdc++.h>
    using namespace std;
    const int N=109;
    char c[N][N];
    bool b[N][N];
    struct P{
    	int a1,b1,a2,b2,a3,b3;
    }ans[N*N];
    int tp;
    void make(int a1,int b1,int a2,int b2,int a3,int b3){
    	b[a1][b1]^=1,b[a2][b2]^=1,b[a3][b3]^=1;
    }
    void get(int a1,int b1,int a2,int b2,int a3,int b3){
    	ans[++tp]={a1,b1,a2,b2,a3,b3};
    	b[a1][b1]^=1,b[a2][b2]^=1,b[a3][b3]^=1;
    }
    int calcs(int i,int j){
    	int s=0;
    	if(b[i][j])++s;
    	if(b[i][j+1])++s;
    	if(b[i+1][j])++s;
    	if(b[i+1][j+1])++s;
    	return s;
    }
    void work(int i,int j){
    	int s=calcs(i,j);
    				if(s==4){
    					get(i,j,i,j+1,i+1,j),s=1;
    				}
    				if(s==1){
    					if(make(i,j,i+1,j,i,j+1),calcs(i,j)==2){
    						make(i,j,i+1,j,i,j+1);
    						get(i,j,i+1,j,i,j+1);
    						goto gg0;
    					}else make(i,j,i+1,j,i,j+1);
    					if(make(i+1,j+1,i+1,j,i,j+1),calcs(i,j)==2){
    						make(i+1,j+1,i+1,j,i,j+1);
    						get(i+1,j+1,i+1,j,i,j+1);
    						goto gg0;
    					}else make(i+1,j+1,i+1,j,i,j+1);
    					if(make(i,j,i+1,j,i+1,j+1),calcs(i,j)==2){
    						make(i,j,i+1,j,i+1,j+1);
    						get(i,j,i+1,j,i+1,j+1);
    						goto gg0;
    					}else make(i,j,i+1,j,i+1,j+1);
    					if(make(i,j,i+1,j+1,i,j+1),calcs(i,j)==2){
    						make(i,j,i+1,j+1,i,j+1);
    						get(i,j,i+1,j+1,i,j+1);
    						goto gg0;
    					}else make(i,j,i+1,j+1,i,j+1);
    					gg0:;
    					s=2;
    				}
    				if(s==2){
    					if(make(i,j,i+1,j,i,j+1),calcs(i,j)==3){
    						make(i,j,i+1,j,i,j+1);
    						get(i,j,i+1,j,i,j+1);
    						goto gg;
    					}else make(i,j,i+1,j,i,j+1);
    					if(make(i+1,j+1,i+1,j,i,j+1),calcs(i,j)==3){
    						make(i+1,j+1,i+1,j,i,j+1);
    						get(i+1,j+1,i+1,j,i,j+1);
    						goto gg;
    					}else make(i+1,j+1,i+1,j,i,j+1);
    					if(make(i,j,i+1,j,i+1,j+1),calcs(i,j)==3){
    						make(i,j,i+1,j,i+1,j+1);
    						get(i,j,i+1,j,i+1,j+1);
    						goto gg;
    					}else make(i,j,i+1,j,i+1,j+1);
    					if(make(i,j,i+1,j+1,i,j+1),calcs(i,j)==3){
    						make(i,j,i+1,j+1,i,j+1);
    						get(i,j,i+1,j+1,i,j+1);
    						goto gg;
    					}else make(i,j,i+1,j+1,i,j+1);
    					gg:;
    					s=3;
    				}
    				if(s==3){
    					if(make(i,j,i+1,j,i,j+1),calcs(i,j)==0){
    						make(i,j,i+1,j,i,j+1);
    						get(i,j,i+1,j,i,j+1);
    						goto gg2;
    					}else make(i,j,i+1,j,i,j+1);
    					if(make(i+1,j+1,i+1,j,i,j+1),calcs(i,j)==0){
    						make(i+1,j+1,i+1,j,i,j+1);
    						get(i+1,j+1,i+1,j,i,j+1);
    						goto gg2;
    					}else make(i+1,j+1,i+1,j,i,j+1);
    					if(make(i,j,i+1,j,i+1,j+1),calcs(i,j)==0){
    						make(i,j,i+1,j,i+1,j+1);
    						get(i,j,i+1,j,i+1,j+1);
    						goto gg2;
    					}else make(i,j,i+1,j,i+1,j+1);
    					if(make(i,j,i+1,j+1,i,j+1),calcs(i,j)==0){
    						make(i,j,i+1,j+1,i,j+1);
    						get(i,j,i+1,j+1,i,j+1);
    						goto gg2;
    					}else make(i,j,i+1,j+1,i,j+1);
    					gg2:;
    				}
    }
    int main(){
    	int T,n,m,i,j,s;
    	scanf("%d",&T);
    	while(T--){
    		scanf("%d%d",&n,&m),tp=0;
    		for(i=1;i<=n;++i){
    			scanf("%s",c[i]+1);
    			for(j=1;j<=m;++j)if(c[i][j]=='1')b[i][j]=1;else b[i][j]=0;
    		}
    		
    			for(i=1;i<n;++i)
    			for(j=1;j<m-1;++j){
    				if(b[i][j]&&b[i+1][j])get(i,j,i+1,j,i+1,j+1);
    				else if(b[i][j])get(i,j,i,j+1,i+1,j+1);
    				else if(b[i+1][j])get(i+1,j,i,j+1,i+1,j+1);
    			}
    			j=m-1;
    			for(i=1;i<n-1;++i){
    				if(b[i][j]&&b[i][j+1])get(i,j,i,j+1,i+1,j+1);
    				else if(b[i][j])get(i,j,i+1,j,i+1,j+1);
    				else if(b[i][j+1])get(i,j+1,i+1,j,i+1,j+1); 
    			}
    		work(n-1,m-1);
    		printf("%d\n",tp);
    		for(i=1;i<=tp;++i)printf("%d %d %d %d %d %d\n",ans[i].a1,ans[i].b1,ans[i].a2,ans[i].b2,ans[i].a3,ans[i].b3); 
    		//for(i=1;i<=n;++i)for(j=1;j<=m;++j)assert(b[i][j]==0);
    	}
    	return 0;
    }